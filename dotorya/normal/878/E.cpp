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
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

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

ll in[100050];
ll sum[100050];
ll po2[100050];
ll getsum(int p1, int p2) {
	ll rv = sum[p2] - sum[p1 - 1];
	rv = (rv + MOD) % MOD;
	rv = rv * mul_inv(po2[p1 - 1]) % MOD;
	return rv;
}

ll nxt[100050][2];

ll par[20][100050][2];
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);

	po2[0] = 1;
	for (i = 1; i <= N; i++) po2[i] = po2[i - 1] * 2 % MOD;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		sum[i] = sum[i - 1] + in[i] * po2[i];
		sum[i] %= MOD;
		sum[i] += MOD;
		sum[i] %= MOD;
	}
	for (i = 1; i <= N; i++) {
		ll s = 0;
		for (j = i; j >= 1; j--) {
			s = 2 * s + in[j];
			if (s <= 0) {
				nxt[i][0] = j - 1;
				break;
			}
			if (s >= 1000000000) break;
		}
		nxt[i][1] = getsum(nxt[i][0] + 1, i);
	}

	for (i = 0; i <= N; i++) par[0][i][0] = nxt[i][0], par[0][i][1] = nxt[i][1];
	for (i = 1; i < 20; i++) {
		for (j = 1; j <= N; j++) {
			int np = par[i - 1][j][0];
			par[i][j][0] = par[i - 1][np][0];
			par[i][j][1] = (par[i - 1][j][1] + par[i - 1][np][1]) % MOD;
		}
	}

	while (Q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		if (l == r) {
			printf("%lld\n", (in[l] + 2 * MOD) % MOD);
			continue;
		}

		ll ans = (in[l] + MOD) % MOD;
		l++;
	
		for (i = 19; i >= 0; i--) {
			int p = par[i][r][0];
			if (p >= l) {
				ans = (ans + par[i][r][1]) % MOD;
				r = p;
			}
		}
		ans += getsum(l, r);
		printf("%lld\n", ans % MOD);
	}
	return 0;
}