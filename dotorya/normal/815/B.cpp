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

int IT_MAX = 1 << 18;
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

ll in[200050];
ll u[200050];

ll F[1000050];
ll Finv[1000050];
ll C(ll a, ll b) {
	if (a < b || b < 0) return 0;
	ll rv = F[a];
	rv = (rv * Finv[a - b]) % MOD;
	rv = rv * Finv[b] % MOD;
	return rv;
}
ll getv(ll a, ll b) {
	if (b % 2) return 0;
	
	ll rv = C(a, b / 2);
	if (b % 4) rv *= -1;
	return (rv%MOD + MOD) % MOD;
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	F[0] = 1;
	for (i = 1; i <= 1000000; i++) F[i] = F[i - 1] * i % MOD;
	for (i = 0; i <= 1000000; i++) Finv[i] = mul_inv(F[i]);

	int p = 0, a = 0, b = 0;
	for (i = N - 1; i >= 1; i--) {
		if (p == 0) a++;
		else b++;
		p ^= i % 2;
	}

	ll ans = 0;
	for (int k = 0; k <= N - 1; k++) {
		ll v = in[k + 1];

		ll t = 0;
		if (a - b == 2) t = getv(b, k) + 2 * getv(b, k - 1) + getv(b, k - 2);
		else if (a - b == 1) t = getv(b, k) + getv(b, k - 1);
		else if (a == b) t = getv(b, k);
		else if (a - b == -1) t = getv(a, k) - getv(a, k - 1);
		else assert(false);

		t = (t + MOD) % MOD;
		if (k % 4 >= 2) t = (-t + MOD) % MOD;
		ans = (ans + v * t) % MOD;
	}
	return !printf("%lld\n", ans);
}