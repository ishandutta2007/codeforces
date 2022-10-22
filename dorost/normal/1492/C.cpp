/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int pre[N], suf[N], prem[N], sufm[N];

void solve() {
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m + 10; i++) {
		prem[i] = INT_MAX;
		sufm[i] = 0;
 	}
	int x = 0;
	if (s[0] == t[x]) {
		pre[0] = (s[0] == t[x]);
		x++;
	} else {
		pre[0] = (s[0] == t[x]);
	}
	for (int i = 1; i < n; i++) {
		if (x == m)
			break;
		if (s[i] == t[x]) {
			x++;
			pre[i] = pre[i - 1] + 1;
		} else {
			pre[i] = pre[i - 1];
		}
	}
	x = m - 1;
	if (s[n - 1] == t[x]) {
		suf[n - 1] = (s[n - 1] == t[x]);
		x--;
	} else {
		suf[n - 1] = (s[n - 1] == t[x]);
	}
	for (int i = n - 2; i >= 0; i--) {
		if (x == -1)
			break;
		if (s[i] == t[x]) {
			x--;
			suf[i] = suf[i + 1] + 1;
		} else {
			suf[i] = suf[i + 1];
		}
	}
	for (int i = 0; i < n; i++) {
//		cout << pre[i] << ' ' << suf[i] << '\n';
		prem[pre[i]] = min(prem[pre[i]], i);
		sufm[suf[i]] = max(sufm[suf[i]], i);
	}
	int mx = 0;
	for (int i = 1; i < m; i++) {
//		cout << prem[i] << ' ' << sufm[i] << '\n';
		mx = max(mx, sufm[m - i] - prem[i]);
	}
	cout << mx;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}