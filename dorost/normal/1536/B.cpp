/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
pair <int, string> st[N * 4];

void solve() {
	int n;
	string s;
	cin >> n >> s;
	set <pair <int, string>> a;
	for (int i = 0; i < n * 4 + 10; i++) {
		a.insert(st[i]);
	}
	for (int i = 0; i < n; i++) {
		string ss;
		for (int j = i; j < min(n, i + 5); j++) {
			ss += s[j];
			a.erase({ss.size(), ss});
		}
	}
	cout << (*a.begin()).S << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x = 0;
	for (int s = 1; s <= 6; s++) {
		if (x >= N * 4) {
			break;
		}
		int a = pow(26, s);
		for (int i = 0; i < a; i++) {
			int aa = i;
			string t;
			for (int i = 0; i < s; i++) {
				t += (aa % 26) + 'a';
				aa /= 26;
			}
			if (x >= N * 4) {
				break;
			}
			st[x] = {s, t};
			x++;
		}
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}