#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, ans;
	cin >> s;
	
	for (int i = 0; i < s.size(); ++i) {
		char t = tolower(s[i]);
		switch (t) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				continue;
			default:
				ans += '.';
				ans += t;
				break;
		}
	}
	cout << ans;
	return 0;
}