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

int IT_MAX = 1 << 17;
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
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
ll F[1005];
ll Finv[1005];
ll C(ll a, ll b) {
	ll rv = Finv[b];
	for (ll i = a; i > a - b; i--) rv = (rv * (i + MOD)) % MOD;
	return rv;
}
ll H(ll a, ll b) {
	return C(a + b - 1, b);
}

ll dp[55][55];
ll dp2[55][55];

ll tdp[55][55];
ll tdp2[55][55];

int main() {
	int N, M, i, j, k, l, m, n;
	F[0] = 1;
	for (i = 1; i <= 1000; i++) F[i] = F[i - 1] * i % MOD;
	for (i = 0; i <= 1000; i++) Finv[i] = mul_inv(F[i]);


	scanf("%d %d", &N, &M);
	dp[0][1] = 1;
	for (i = 1; i <= N; i++) {
		for (j = 0; j < i; j++) {
			int a1 = j, a2 = i - 1 - j;
			for (k = 1; k <= a1 + 1; k++) {
				for (l = 1; l <= a2 + 1; l++) {
					ll v = dp[a1][k] * dp[a2][l];
					dp2[i][min(k, l)] = (dp2[i][min(k, l)] + v) % MOD;
				}
			}
		}
		
		memset(tdp, 0, sizeof(tdp));
		tdp[0][1] = 1;
		for (j = 1; j <= i; j++) {
			for (k = 0; k <= j + 1; k++) {
				memset(tdp2, 0, sizeof(tdp2));
				ll x = dp2[j][k];
				for (l = 0;; l++) {
					int a1 = l * j, a2 = l * k;
					if (a1 > i) break;
					ll v = C(x + l - 1, l);
					for (m = 0; m <= i - a1; m++) {
						for (n = 0; n <= i + 1 - a2; n++) {
							tdp2[m + a1][n + a2] = (tdp2[m + a1][n + a2] + tdp[m][n] * v) % MOD;
						}
					}
				}
				for (l = 0; l <= i; l++) for (m = 0; m <= i + 1; m++) tdp[l][m] = tdp2[l][m];
			}
		}
		for (j = 1; j <= i; j++) for (k = 1; k <= i + 1; k++) dp[j][k] = tdp[j][k];
	}
	return !printf("%lld\n", dp[N][M]);
}