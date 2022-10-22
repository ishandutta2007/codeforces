/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 26;
vector <int> v[26];

void solve() {
	string s;
	int p;
	cin >> s >> p;
	string t;
	for (int i = 0; i < (int)s.size(); i++)
		t += '?';
	int pr = 0;
	for (int i = 0; i < M; i++)
		v[i].clear();
	for (int i = 0; i < (int)s.size(); i++)
		v[s[i] - 'a'].push_back(i), pr += (s[i] - 'a' + 1);
	for (int i = 25; i >= 0; i--) {
		if (pr <= p) {
			break;
		}
		while ((int)v[i].size()) {
			pr -= (i + 1);
			v[i].pop_back();
			if (pr <= p) {
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j : v[i])
			t[j] = (i + 'a');
	}
	for (int i = 0; i < (int)s.size(); i++) {
		if (t[i] != '?')
			cout << t[i];
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}