#include <iostream>
using namespace std;

int main() {
	string s; char ch;
	cin >> s >> ws;
	for (int i = 0; i < s.size(); ++i) {
		cin >> ch;
		cout << (s[i] != ch);
	}
	return 0;
}