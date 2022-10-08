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

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
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

ll F[1000050];
ll Finv[1000050];
ll Co(ll a, ll b) {
	ll rv = F[a] * Finv[b] % MOD;
	return rv * Finv[a - b] % MOD;
}
int main() {
	ll N;
	scanf("%lld", &N);

	F[0] = 1;
	for (ll i = 1; i <= 1000020; i++) F[i] = F[i - 1] * i % MOD;
	for (ll i = 0; i <= 1000020; i++) Finv[i] = mul_inv(F[i]);

	ll ans = F[N];
	for (ll i = 1; i < N; i++) {
		ll c = Co(N, i) * (F[i] - 1) % MOD;
		ans = (ans + c * F[N - i]) % MOD;
	}
	return !printf("%lld\n", ans);
}