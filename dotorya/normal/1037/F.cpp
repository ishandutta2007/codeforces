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
#pragma comment(linker, "/STACK:3336777216")  
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

set <int> Sx;
ll in[1000050];
ll u[1000050];

ll getcnt(int L, int K) {
	if (L < K) return 0;

	ll mx = (L - 1) / (K - 1);
	return L * mx - (K - 1) * mx * (mx + 1) / 2;

}
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		u[i] = i;
	}
	sort(u + 1, u + N + 1, [](ll a, ll b) {
		return in[a] > in[b];
	});

	Sx.insert(0);
	Sx.insert(N + 1);

	ll ans = 0;
	for (i = 1; i <= N; i++) {
		int p = u[i];
		auto it = Sx.lower_bound(p);

		int S = *prev(it), E = *it;

		ll c = getcnt(E - S - 1, K) - getcnt(p - S - 1, K) - getcnt(E - p - 1, K);
		c %= MOD;
		ans = (ans + c * in[p]) % MOD;
		Sx.insert(p);
	}
	return !printf("%lld\n", ans);
}