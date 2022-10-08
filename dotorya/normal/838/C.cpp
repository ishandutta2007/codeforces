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
#pragma comment(linker, "/STACK:33554432")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll mul_inv(ll a, ll b) {
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

ll P;
int cnt1[250050];
ll dp[250050][20];
ll F[250050];
ll Finv[250050];
ll C(ll a, ll b) {
	if (a < b) return 0;
	ll rv = F[a] * Finv[b] % P;
	return rv * Finv[a - b] % P;
}

int main() {
	int N, K, i, j, k;
	scanf("%d %d %lld", &N, &K, &P);
	int st = clock();

	ll ans = 1;
	for (i = 1; i <= N; i++) ans = ans * K % P;
	if (N == 1 || N % 2) return !printf("%lld\n", ans);

	F[0] = 1;
	for (i = 1; i <= N; i++) F[i] = (F[i - 1] * i) % P;
	for (i = 0; i <= N; i++) Finv[i] = mul_inv(F[i], P);

	dp[N][0] = 1;
	for (i = N; i; i = (i-1) & N) {
		ll t = 1048576;
		while (!(t&i)) t /= 2;
		for (j = 0; j < K; j++) {
			if (!dp[i][j]) continue;
			
			ll u = dp[i][j] * F[i] % P;
			ll x = i - t;
			for (k = x; k >= 0; k = (k - 1) & x) {
				ll a = t + k;
				
				ll c = u * Finv[a] % P;
				c = c * Finv[i - a] % P;
				c = c * (K - j) % P;
				dp[i - a][j + 1] = (dp[i - a][j + 1] + c) % P;
				if (k == 0) break;
			}
		}
	}
//	printf("%d\n", clock() - st);
	
	for (i = 1; i <= K; i++) ans = (ans + P - dp[0][i]) % P;
	return !printf("%lld\n", ans);
}