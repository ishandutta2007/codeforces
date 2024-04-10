#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt[4] = {0};
	for (int i = 0; i < s.size(); i += 2) {
		cnt[s[i] - 48] ++;
	}
	s = "";
	for (int i = 1; i < 4; ++i) {
		for (int k = 0; k < cnt[i]; ++k) {
			s += (char) i + 48;
			s += '+';
		}
	}
	s.resize(s.size() - 1);
	cout << s;
	return 0;
}