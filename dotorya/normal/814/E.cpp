#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x * t2;
		v3 = v1 - x * v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
ll C[105][105];
ll po2[105];
int in[105];

ll dp[55][55];
ll F[105];
ll Finv[105];

ll val[55][55][55];
ll val2[55][55];
int main() {
	int N, i, j, k, l, m, n;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (i = 0; i <= 100; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	po2[0] = 1;
	for (i = 1; i <= 100; i++) po2[i] = (po2[i - 1] * 2) % MOD;
	F[0] = 1;
	for (i = 1; i <= 100; i++) F[i] = (F[i - 1] * i) % MOD;
	for (i = 0; i <= 100; i++) Finv[i] = mul_inv(F[i]);

	val2[0][0] = 1;
	for (j = 0; j <= N; j++) {
		for (i = 0; i <= N; i++) {
			if (i == 0 && j == 0) continue;
			if (j) {
				if (i >= 2) val2[i][j] = (val2[i][j] + C[i][2] * val2[i - 2][j - 1]) % MOD;
				if (i >= 1 && j >= 2) val2[i][j] = (val2[i][j] + i * (j - 1) * val2[i][j - 2]) % MOD;
				if (j >= 3) val2[i][j] = (val2[i][j] + C[j - 1][2] * val2[i + 2][j - 3]) % MOD;
			}
			else if(i % 2 == 0) val2[i][0] = (i - 1) * val2[i - 2][0];
		}
	}

	for (i = 0; i <= N; i++) {
		for (j = 0; i + j <= N; j++) {
			for (k = 0; k <= N; k++) {
				for (l = 0; l <= i; l++) {
					for (m = 0; m <= j; m++) {
						n = k - l - 2 * m;
						if (n < 0 || m + n > j) continue;
						
						int c1 = (i - l) + n;
						int c2 = j - n - m;
						
						ll v = C[i][l] * F[j] % MOD;
						v = (v * Finv[m]) % MOD;
						v = (v * Finv[n]) % MOD;
						v = (v * Finv[j - m - n]) % MOD;
						v = (v * val2[c1][c2]) % MOD;
						v = (v * mul_inv(po2[m])) % MOD;
						val[i][j][k] = (val[i][j][k] + v * F[k]) % MOD;
					}
				}
			}
		}
	}
	if (in[1] == 3 && N == 3) return !printf("0\n");

	dp[in[1] + 1][2] = 1;
	if (in[1] + 1 == N) {
		int c1 = 0, c2 = 0;
		for (i = 2; i <= in[1] + 1; i++) {
			if (in[i] == 2) c1++;
			else c2++;
		}
		dp[in[1] + 1][2] = val[c1][c2][0];
	}

	for (i = 3; i < N; i++) {
		for (j = 2; j <= i; j++) {
			int c1 = 0, c2 = 0;
			for (k = j; k <= i; k++) {
				if (in[k] == 2) c1++;
				else c2++;
			}
			for (k = i + 1; k <= N; k++) {
				ll v = val[c1][c2][k - i] * dp[i][j] % MOD;
				if (k == N) {
					int cx = 0, cy = 0;
					for (l = i + 1; l <= N; l++) {
						if (in[l] == 2) cx++;
						else cy++;
					}
					v = (v * val[cx][cy][0]) % MOD;
				}
				dp[k][i + 1] = (dp[k][i + 1] + v) % MOD;
			}
		}
	}
	ll ans = 0;
	for (i = 2; i <= N; i++) ans = (ans + dp[N][i]) % MOD;
	return !printf("%lld\n", ans);
}