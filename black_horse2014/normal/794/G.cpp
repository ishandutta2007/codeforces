#include <bits/stdc++.h>
using namespace std;

const int N = 660000;

int c[2][3];
int pw[N], f[N], g[N], r[N], cnt[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	string s[2]; int n; cin >> s[0] >> s[1] >> n;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < s[j].length(); i++) {
			if (s[j][i] == '?') c[j][2]++;
			else c[j][s[j][i] - 'A']++;
		}
	}
	int L0 = c[0][0] - c[1][0] - c[1][2];
	int R0 = c[0][0] - c[1][0] + c[0][2];
	int L1 = c[0][1] - c[1][1] - c[1][2];
	int R1 = c[0][1] - c[1][1] + c[0][2];
	int ans = 0;
	const int P = 1e9 + 7;
	for (int i = 0; i < N; i++) pw[i] = i == 0 ? 1 : pw[i - 1] * 2 % P;
	for (int i = 0; i < N; i++) {
		f[i] = i == 0 ? 1 : f[i - 1] * 1LL * i % P;
		r[i] = i < 2 ? i : r[P % i] * 1LL * (P - P / i) % P;
		g[i] = i == 0 ? 1 : g[i - 1] * 1LL * r[i] % P;
	}
	function<long long(int, int)> C = [&](int n, int m) {
		if (m < 0 || m > n) return 0LL;
		return f[n] * 1LL * g[m] % P * g[n - m] % P;
	};
	auto get = [&](int d, int a, int b) {
		return C(a + b, a - d);
	};
	auto calc = [&](int X, int Y) {
		if (X < 0 && Y < 0) return 0;
		if (X > 0 && Y > 0) return 0;
		if (X == 0 && Y != 0) return 0;
		if (Y == 0 && X != 0) return 0;
		int G = abs(__gcd(X, Y));
		X /= G, Y /= G;
		if (X < 0) X = -X, Y = -Y;
		Y = -Y;
		if (X == 0 && Y == 0) {
			int tot = get(-L0 - c[1][2], c[0][2], c[1][2]);
			int same = 1;
			for (int i = 0; i < s[0].length(); i++) {
				if (s[0][i] == '?' && s[1][i] == '?') same = 2 * same % P;
				else if (s[0][i] != '?' && s[1][i] != '?') {
					if (s[0][i] != s[1][i]) same = 0;
				}
			}
			int diff = (tot + P - same) % P;
			int ret = 0;
			for (int i = n; i > 0; i--) {
				cnt[i] = (n / i) * 1LL * (n / i) % P;
				for (int j = i + i; j <= n; j += i) cnt[i] = (cnt[i] + P - cnt[j]) % P;
				ret = (ret + 1LL * cnt[i] * pw[i]) % P;
			}
			ret = (1LL * ret * diff + 1LL * same * (pw[n + 1] + P - 2) % P * (pw[n + 1] + P - 2) % P) % P;
			return ret;
		} else {
			return (pw[n / max(X, Y) + 1] + P - 2) % P;
		}
	};
	for (int X = L0; X <= R0; X++) {
		int Y = L0 + R1 - X;
		if (X == 0 && Y == 0) ans = (ans + calc(0, 0)) % P;
		else ans = (ans + 1LL * calc(X, L0 + R1 - X) * get(X - L0 - c[1][2], c[0][2], c[1][2])) % P;
	}
	cout << ans << endl;
	return 0;
}