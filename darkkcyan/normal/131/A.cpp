#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	if (count_if(s.begin() + 1, s.end(), ::isupper) == s.size() - 1) {
		transform(s.begin() + 1, s.end(), s.begin() + 1, ::tolower);
		s[0] = islower(s[0]) ? toupper(s[0]) : tolower(s[0]);
	}
	cout << s;
	return 0;
}