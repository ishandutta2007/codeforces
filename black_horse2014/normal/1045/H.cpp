//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

char a[110000];
char b[110000];

const int P = 1e9 + 7;
const int N = 110000;

int f[N], g[N], r[N], c[2][2];

int C(int n, int m) {
	if (n == -1 && m == -1) return 1;
	if (m < 0 || m > n) return 0;
	return f[n] * 1LL * g[m] % P * g[n - m] % P;
}

bool okay(char *s) {
	int n = strlen(s);
	int cnt[2][2] = {0};
	for (int i = 0; i < n-1; i++) {
		int j = s[i]-'0', k = s[i+1]-'0';
		cnt[j][k]++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) if (cnt[i][j] != c[i][j]) return 0;
	}
	return 1;
}

int solve(int first, int c[2][2]) {
	if (c[0][0] + c[0][1] + c[1][0] + c[1][1] == 0) return 1;
	if (abs(c[0][1] - c[1][0]) > 1) return 0;
	if (!first) {
		if (c[0][1] < c[1][0]) return 0;
	} else {
		if (c[1][0] < c[0][1]) return 0;
	}
	int ones;
	int zeros;
	if (first == 0) {
		ones = c[0][1];
		zeros = c[1][0] + 1;
	} else {
		ones = c[0][1] + 1;
		zeros = c[1][0];
	}
	int onecnt = c[1][1] + ones;
	int zerocnt = c[0][0] + zeros;
	return C(onecnt-1, ones-1) * 1LL * C(zerocnt-1, zeros-1) % P;
}

int calc(char *s) {
	int n = strlen(s);
	int len = c[0][0] + c[0][1] + c[1][0] + c[1][1] + 1;
	if (len > n) return 0;
	if (len == 1) return 1;
	if (c[0][1] >= c[1][0] + 1 || c[1][0] >= c[0][1] + 2) return 0;
	if (len < n) return solve(1, c);
	int cnt[2][2];
	memcpy(cnt, c, sizeof c);
	int ans = 0;
	for (int i = 1; i < len; i++) {
		int j = s[i-1]-'0';
		if (s[i] == '1' && cnt[j][0]) {
			cnt[j][0]--;
			ans = (ans + solve(0, cnt)) % P;
			cnt[j][0]++;
		}
		cnt[j][s[i]-'0']--;
		if (cnt[j][s[i]-'0'] < 0) return ans;
	}
	ans = (ans + okay(s)) % P;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < N; i++) {
		f[i] = (i < 2 ? 1 : f[i - 1] * 1LL * i % P);
		r[i] = (i < 2 ? i : r[P % i] * 1LL * (P - P / i) % P);
		g[i] = (i < 2 ? 1 : g[i - 1] * 1LL * r[i] % P);
	}
	cin >> a >> b;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> c[i][j];
	cout << (calc(b) + P - calc(a) + okay(a)) % P << endl;
	return 0;
}