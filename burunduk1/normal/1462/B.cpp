/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

bool solve() {
	string s, t = "2020";
	int n;
	cin >> n >> s;
	// cout << s << " " << t << endl;
	auto pref = [&](const string &s, int k) { return s.substr(0, k); };
	auto suf = [&](const string &s, int k) { return s.substr(s.size() - k, k); };
	forn(i, 5) 
		if (pref(s, i) == pref(t, i) && suf(s, 4 - i) == suf(t, 4 - i)) 
			return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		cout << (solve() ? "YES" : "NO") << "\n";
}