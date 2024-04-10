/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1000 * 1000 * 1000 + 7;
const int N = 101234;
int p10[N], pre[N], suf[N], prepre[N];

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	p10[0] = 1;
	for (int i = 1; i < N; i++) {
		p10[i] = (p10[i - 1] * 10) % M;
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		num = (num + (p10[n - i - 1] * (s[i] - '0'))) % M;
	}
	pre[0] = s[0] - '0';
	for (int i = 1; i < n; i++) {
		pre[i] = (pre[i - 1] * 10 + (s[i] - '0')) % M;
	}
	suf[n] = 0;
	suf[n - 1] = s[n - 1] - '0';
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = (suf[i + 1] + (p10[n - i - 1] * (s[i] - '0') % M)) % M;
	}
	prepre[0] = 0;
	/* for (int i = 0; i < n; i++)
		cout << pre[i] << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << suf[i] << ' ';
	cout << '\n'; */
	for (int i = 1; i <= n; i++) {
		prepre[i] = (prepre[i - 1] + pre[i - 1]) % M;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = ans + (((suf[i] * (i)) % M) + ((p10[n - i] * prepre[i - 1]) % M));
		ans %= M;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}