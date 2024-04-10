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
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

bool pchk[5000050];
int val[5000050];

ll dp[5000050];
int main() {
	int i, j;
	for (i = 2; i <= 5000000; i++) {
		if (pchk[i]) continue;
		val[i] = i;
//		dp[i] = (ll)i*(i - 1) / 2;
		for (j = 2 * i; j <= 5000000; j += i) {
			pchk[j] = true;
			if(!val[j]) val[j] = i;
		}
	}
	
	ll T, L, R;
	scanf("%lld %lld %lld", &T, &L, &R);

	for (i = L; i <= R; i++) {
		ll t = i;
		while (t != 1) {
			ll v = val[t];
			dp[i] += (t / v) * v * (v - 1) / 2;
			dp[i] %= MOD;
			t /= v;
		}
	}

	ll ans = 0, v = 1;
	for (i = L; i <= R; i++) {
		ans = (ans + v * dp[i]) % MOD;
		v = (v * T) % MOD;
	}
	return !printf("%lld\n", ans);
}