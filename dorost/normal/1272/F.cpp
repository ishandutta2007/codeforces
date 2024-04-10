/* 	* In the name of GOD  */

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201, INF = 2101212;
int dp[N][N][4 * N];
pair <pair <int, int>, int> p[N][N][4 * N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N * 4; k++) {
				dp[i][j][k] = INF;
				p[i][j][k].S = -1;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			bool f = true;
			if (i == 0 && j != 0) {
				if (t[j - 1] == '(')
					f = false;
			} else if (j == 0 && i != 0) {
				if (s[i - 1] == '(')
					f = false;
			} else if (j != 0 && i != 0) {
				if (s[i - 1] == '(')
					f = false;
			}
			if (i == 0 && j == 0) {
				for (int k = 0; k <= (n + m) * 2; k++) {
					dp[i][j][k] = k;
					if (k == 0)
						continue;
					p[i][j][k] = {{i, j}, k - 1};
				}
				continue;
			}
			if (f) {
				for (int k = 0; k <= (n + m) * 2; k++) {
					if (i == 0) {
						if (t[j - 1] == '(') {
							if (k != 0) 
								dp[i][j][k] = dp[i][j - 1][k - 1] + 1, p[i][j][k] = {{i, j - 1}, k - 1};
							if (dp[i][j][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j}, k + 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i][j][k + 1] + 1);
						} else {
							dp[i][j][k] = dp[i][j - 1][k + 1] + 1, p[i][j][k] = {{i, j - 1}, k + 1};
							if (k != 0) {
								if (dp[i][j][k - 1] + 1 < dp[i][j][k])
									p[i][j][k] = {{i, j}, k - 1};
								dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1] + 1);
							}
						}
					} else if (j == 0) {
						if (s[i - 1] == '(') {
							if (k != 0) 
								dp[i][j][k] = dp[i - 1][j][k - 1] + 1, p[i][j][k] = {{i - 1, j}, k - 1};
							if (dp[i][j][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j}, k + 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i][j][k + 1] + 1);
						} else {
							dp[i][j][k] = dp[i - 1][j][k + 1] + 1, p[i][j][k] = {{i - 1, j}, k + 1};
							if (dp[i][j][k - 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j}, k - 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1] + 1);
						}
					} else if (s[i - 1] == t[j - 1]) {
						if (s[i - 1] == '(') {
							if (k != 0) 
								dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1, p[i][j][k] = {{i - 1, j - 1}, k - 1};
						} else {
							dp[i][j][k] = dp[i - 1][j - 1][k + 1] + 1, p[i][j][k] = {{i - 1, j - 1}, k + 1};
						}
						if (s[i - 1] == '(') {
							if (dp[i][j][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j}, k + 1};
							dp[i][j][k] = min(dp[i][j][k + 1] + 1, dp[i][j][k]);
						} else {
							if (k != 0) {
								if (dp[i][j][k - 1] + 1 < dp[i][j][k])
									p[i][j][k] = {{i, j}, k - 1};
								dp[i][j][k] = min(dp[i][j][k - 1] + 1, dp[i][j][k]);
							}
						}
					} else {
						if (s[i - 1] == '(') {
							if (k != 0) 
								dp[i][j][k] = dp[i - 1][j][k - 1] + 1, p[i][j][k] = {{i - 1, j}, k - 1};
							if (dp[i][j - 1][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j - 1}, k + 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k + 1] + 1);
						} else {
							if (k != 0) 
								dp[i][j][k] = dp[i][j - 1][k - 1] + 1, p[i][j][k] = {{i, j - 1}, k - 1};
							if (dp[i - 1][j][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i - 1, j}, k + 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k + 1] + 1);
						}
					}
				}
			} else {
				for (int k = (n + m) * 2; k >= 0; k--) {
					if (i == 0) {
						if (t[j - 1] == '(') {
							if (k != 0) 
								dp[i][j][k] = dp[i][j - 1][k - 1] + 1, p[i][j][k] = {{i, j - 1}, k - 1};
							if (dp[i][j][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j}, k + 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i][j][k + 1] + 1);
						} else {
							dp[i][j][k] = dp[i][j - 1][k + 1] + 1, p[i][j][k] = {{i, j - 1}, k + 1};
							if (k != 0) {
								if (dp[i][j][k - 1] + 1 < dp[i][j][k])
									p[i][j][k] = {{i, j}, k - 1};
								dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1] + 1);
							}
						}
					} else if (j == 0) {
						if (s[i - 1] == '(') {
							if (k != 0) 
								dp[i][j][k] = dp[i - 1][j][k - 1] + 1, p[i][j][k] = {{i - 1, j}, k - 1};
							if (dp[i][j][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j}, k + 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i][j][k + 1] + 1);
						} else {
							dp[i][j][k] = dp[i - 1][j][k + 1] + 1, p[i][j][k] = {{i - 1, j}, k + 1};
							if (dp[i][j][k - 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j}, k - 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1] + 1);
						}
					} else if (s[i - 1] == t[j - 1]) {
						if (s[i - 1] == '(') {
							if (k != 0) 
								dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1, p[i][j][k] = {{i - 1, j - 1}, k - 1};
						} else {
							dp[i][j][k] = dp[i - 1][j - 1][k + 1] + 1, p[i][j][k] = {{i - 1, j - 1}, k + 1};
						}
						if (s[i - 1] == '(') {
							if (dp[i][j][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j}, k + 1};
							dp[i][j][k] = min(dp[i][j][k + 1] + 1, dp[i][j][k]);
						} else {
							if (k != 0) {
								if (dp[i][j][k - 1] + 1 < dp[i][j][k])
									p[i][j][k] = {{i, j}, k - 1};
								dp[i][j][k] = min(dp[i][j][k - 1] + 1, dp[i][j][k]);
							}
						}
					} else {
						if (s[i - 1] == '(') {
							if (k != 0) 
								dp[i][j][k] = dp[i - 1][j][k - 1] + 1, p[i][j][k] = {{i - 1, j}, k - 1};
							if (dp[i][j - 1][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i, j - 1}, k + 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k + 1] + 1);
						} else {
							if (k != 0) 
								dp[i][j][k] = dp[i][j - 1][k - 1] + 1, p[i][j][k] = {{i, j - 1}, k - 1};
							if (dp[i - 1][j][k + 1] + 1 < dp[i][j][k])
								p[i][j][k] = {{i - 1, j}, k + 1};
							dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k + 1] + 1);
						}
					}
				}
			}
		}
	}
	pair <pair <int, int>, int> k = {{n, m}, 0};
	string ans;
	while (p[k.F.F][k.F.S][k.S].S != -1) {
		if (p[k.F.F][k.F.S][k.S].S == k.S + 1) 
			ans += ')';
		else
			ans += '(';
		k = p[k.F.F][k.F.S][k.S];
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}