#include <iostream>
using namespace std;

int main() {
	char ch;
	cin >> ch;
	cout << (char) toupper(ch);
	while (cin >> ch) cout << ch;
	return 0;
}