/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 27;
int mx[N], mn[N], cnt[N];

void solve() {
	int n;
	string s;
	for (int i = 0; i < 26; i++) {
		mx[i] = cnt[i] = 0;
		mn[i] = 601;
	}
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		mx[s[i] - 'A'] = max(mx[s[i] - 'A'], i);
		mn[s[i] - 'A'] = min(mn[s[i] - 'A'], i);
		cnt[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (mn[i] == 601)
			continue;
		if (cnt[i] != mx[i] - mn[i] + 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}