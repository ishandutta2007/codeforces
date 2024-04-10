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

ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}

int main() {
	ll mn = LL_INF, mx = -1;

	ll N, K, A, B;
	scanf("%lld %lld %lld %lld", &N, &K, &A, &B);

	for (ll i = 0; i < 2; i++) {
		for (ll j = 0; j < 2; j++) {
			ll a = A;
			if (i) a = K - A;

			ll b = B;
			if (j) b = K - B;

			ll x = (b - a + K) % K;
			for (ll k = 0; k < N; k++) {
				ll v = gcd(N*K, x + K * k);
				mn = min(mn, N*K / v);
				mx = max(mx, N*K / v);
			}
		}
	}
	return !printf("%lld %lld\n", mn, mx);
}