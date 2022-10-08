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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll mymul(ll a, ll b) {
	if (b > LL_INF / a) return LL_INF;
	return min(LL_INF, a*b);
}

ll mypow(ll a, ll b) {
	ll rv = 1;
	while (b--) rv = mymul(rv, a);
	return rv;
}

set <ll> Sx;
int main() {
	ll X, Y, L, R, i, j;
	scanf("%lld %lld %lld %lld", &X, &Y, &L, &R);

	for (i = 0; i <= 64; i++) {
		for (j = 0; j <= 64; j++) {
			ll t1 = mypow(X, i);
			ll t2 = mypow(Y, j);
			if (t1 + t2 >= L && t1 + t2 <= R) Sx.insert(t1 + t2);
		}
	}

	ll st = L, ans = 0;
	Sx.insert(R + 1);
	while (st <= R) {
		auto it = Sx.lower_bound(st);
		ans = max(ans, *it - st);
		st = *it + 1;
	}
	return !printf("%lld\n", ans);
}