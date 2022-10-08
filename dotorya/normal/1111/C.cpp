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
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll N, K, A, B;
vector <ll> Vl;
ll getans(ll S, ll E) {
	int c = lower_bound(all(Vl), E + 1) - lower_bound(all(Vl), S);
	if (c == 0) return A;
	if (S == E) return B * c;

	ll M = (S + E) / 2;
	ll rv = B * (E - S + 1) * c;
	rv = min(rv, getans(S, M) + getans(M + 1, E));
	return rv;
}

int main() {
	scanf("%lld %lld %lld %lld", &N, &K, &A, &B);

	for (ll i = 0; i < K; i++) {
		ll t;
		scanf("%lld", &t);
		Vl.push_back(t);
	}
	sort(all(Vl));

	return !printf("%lld\n", getans(1, (1ll << N)));
}