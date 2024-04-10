/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 26;
int cnt[M];

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++) {
		cnt[i] = 0;
	}
	for (auto c : s) {
		cnt[c - 'a']++;
	}
	int x = 0;
	for (int i = 0; i < M; i++) {
		x += min(2, cnt[i]);
	}
	cout << x / 2 << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}