/**
* @file modAlphaCipher.h
* @author Присяжный Андрей
* @version 1.0
* @copyright ИБСТ ПГУ
* @warning Это учебный пример
* @brief Заголовочный файл для модуля modAlphaCipher
*/

#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;

/**
 * @brief Шифрование методом Гронсфельда
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка
*/
class modAlphaCipher
{
private:
	wstring numAlpha = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ"; ///< Русский алфавит
	map <wchar_t, int> alphaNum; ///< Ассоциативный массив "номер по символу"
	vector <int> key; ///< Ключ
	
/** 
 *@brief Преобразование строки в вектор
 * @details В вектор типа "int" с именем "result" записываются числа, которые являются индексами алфавита "numAlpha",применяемый для строки,
 * которая поступила на вход.
 * @return std::vector <int>, в котором хранятся индексы букв сообщения из алфавита "numAlpha"
*/	
	vector <int> convert(const wstring& s); ///< Преобразование строка-вектор
	
/**
 *@brief Преобразование вектора в строку
 * @details В переменную типа "wstring" с именем "result" записывается строка согласно индексам каждой буквы алфавита "numAlpha".
 * Индексы хранятся в векторе типа "int", который поступил на вход.
 * @return строка текста типа "wstring"
*/
	wstring convert(const vector<int>& v); ///< Преобразование вектор-строка
	wstring getValidKey(const wstring& in);
	wstring getValidOpenText(const wstring& in);
	wstring getValidCipherText(const wstring& in);
public:
	modAlphaCipher() = delete; ///< Конструктор без параметров
	modAlphaCipher(const wstring& skey); ///< Конструктор для установки ключа
	wstring encrypt(const wstring& open_text); ///< Зашифрование
	wstring decrypt(const wstring& cipher_text); ///< Расшифрование
};

/// @brief Класс для обработки исключений
class cipher_error : public invalid_argument
{
public:
	explicit cipher_error(const string& what_arg) :
		invalid_argument(what_arg) {}
	explicit cipher_error(const char* what_arg) :
		invalid_argument(what_arg) {}
};
