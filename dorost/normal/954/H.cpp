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
const int N = 5012, M = 1000 * 1000 * 1000 + 7;
int a[N];
int dp[2][2 * N], dp2[2][2 * N], z[N][N];

int f(int x) {
	return x & 1;
}

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				z[i][i] = a[i];
			} else {
				z[i][j] = (((ll)z[i][j - 1]) * ((ll)a[j])) % M;
			}
		}
	}
	for (int i = n; i >= 0; i--) {
		for (int k = 2 * (n - i - 1); k >= 1; k--) {
			if (k >= 2) {
				if (k == 2) {
					dp2[f(i)][k] = 1;
				} else {
					dp2[f(i)][k] = ((ll)dp2[f(i + 1)][k - 2] * (((ll)a[i + 1] * (ll)a[i + 1]) % M)) % M + ((z[i + 1][min(n, i + k - 2)] * 2LL) % M);
				}
			}
			dp[f(i)][k] = (((((ll)dp[f(i + 1)][k] * (ll)a[i]) % M) + z[i][min(n, i + k - 1)]) % M + ((ll)dp2[f(i)][k] * (((ll)((ll)a[i] * (ll)(a[i] - 1)) / 2) % M))) % M;
		}
	}
	for (int i = 1; i <= 2 * n - 2; i++) {
		cout << dp[f(0)][i] << ' ';
	}
}