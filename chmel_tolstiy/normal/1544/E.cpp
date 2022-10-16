#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;

void solve() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());

	if (s[0] == s.back()) {
		cout << s << endl;
		return;
	}

	for (int i = 0; i < 26; ++i) {
		char c = 'a' + i;
		if (count(s.begin(), s.end(), c) == 1) {
			cout << c;
			for (int j = 0; j < s.length(); ++j) if (s[j] != c) {
				cout << s[j];
			}
			cout << endl;
			return;
		}
	}

	int k = count(s.begin(), s.end(), s[0]);
	string p = s.substr(0, k);
	s = s.substr(k);

	if (p.length() <= s.length() + 2) {
		cout << p[0];
		for (int i = 1; i < p.length() - 1; ++i) {
			cout << p[i] << s[i - 1];
		}
		cout << p[0];
		cout << s.substr(p.length() - 2) << endl;
		return;
	}

	if (s[0] == s.back()) {
		// abbb...bbbaaa...aaa
		cout << p[0] << s << p.substr(1) << endl;
		return;
	}

	k = count(s.begin(), s.end(), s[0]);
	string b = s.substr(0, k);
	s = s.substr(k);

	cout << p[0]; p = p.substr(1);
	cout << b[0]; b = b.substr(1);
	cout << p;
	cout << s[0]; s = s.substr(1);
	cout << b << s << endl;
}

int main() {
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while (t-- > 0)
		solve();
	return 0;
}