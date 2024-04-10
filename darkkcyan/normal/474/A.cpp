#include <iostream>
using namespace std;

int main() {
	char ch; cin >> ch >> ws;
	const int maxn = 'z' + 1;
	char n[maxn];
	string s = " qwertyuiopasdfghjkl;zxcvbnm,./ ";
	for (int i = 1; i < s.size() - 1; ++i) {
		if (ch == 'R') n[s[i]] = s[i - 1];
		else n[s[i]] = s[i + 1];
	}
	while (cin >> ch) {
		cout << n[ch];
	}
	return 0;
}