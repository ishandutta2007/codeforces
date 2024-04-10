#include <bits/stdc++.h>
using namespace std;

const int N = 444;
const int P = 998244353;

int a[N], b[N], go[N], chk[N], deg[N], dp[N], pd[N], cnt[4];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int ans = 1, blank = 0;
	vector<int> v;
	memset(go, -1, sizeof go);
	for (int i = 1; i <= n; i++) {
		if (!a[i] && !b[i]) ans = ans * 1LL * (++blank) % P;
		else {
			if (!a[i]) v.push_back(b[i]);
			else go[a[i]] = b[i];
			deg[b[i]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			int u = i;
			while (u > 0) chk[u] = 1, u = go[u];
			if (!u) cnt[2]++;
			else cnt[3]++;
		}
	}
	for (int i : v) {
		int u = i;
		while (u > 0) chk[u] = 1, u = go[u];
		if (!u) cnt[0]++;
		else cnt[1]++;
	}
	int cycle = 0;
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			cycle++;
			for (int j = i; !chk[j]; chk[j] = 1, j = go[j]);
		}
	}
	for (int i = 0; i < cnt[0]; i++) ans = ans * 1LL * (cnt[3] - i + P) % P;
	dp[cycle] = ans;
	for (int i = 0; i < cnt[3] + cnt[1]; i++) {
		for (int j = 0; j <= n; j++) pd[j] = dp[j], dp[j] = 0;
		for (int j = n; j > 0; j--) dp[j] = (pd[j - 1] + pd[j] * 1LL * i) % P;
		dp[0] = 0;
	}
	for (int i = 0; i < cnt[2]; i++) {
		for (int j = 0; j <= n; j++) pd[j] = dp[j], dp[j] = 0;
		for (int j = n; j > 0; j--) dp[j] = (pd[j - 1] + pd[j] * 1LL * (i + cnt[3])) % P;
		dp[0] = 0;
	}
	for (int i = 0; i < n; i++) cout << dp[n - i] << ' ';
	cout << endl;
	return 0;
}