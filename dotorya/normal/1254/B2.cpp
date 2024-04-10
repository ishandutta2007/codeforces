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
int IT_MAX = 1 << 12;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll in[1000050];
ll tin[1000050];
ll getans(ll N, ll d) {
	ll rv = 0;
	for (ll i = 1; i <= N; i++) tin[i] = in[i];
	for (ll i = 1; i < N; i++) {
		ll v = tin[i] % d;
		v = (v + d) % d;
		if (v <= d - v) {
			rv += v;
			tin[i + 1] += v;
		}
		else {
			rv += (d - v);
			tin[i + 1] -= (d - v);
		}
	}
	return rv;
}
int main() {
	int N, i, j;
	scanf("%d", &N);

	ll sum = 0;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		sum += in[i];
	}

	if (sum == 1) return !printf("-1\n");

	ll ans = LL_INF;
	for (i = 2; (ll)i * i <= sum; i++) {
		if (sum%i) continue;
		ans = min(ans, getans(N, i));
		while (sum%i == 0) sum /= i;
	}
	if (sum != 1) ans = min(ans, getans(N, sum));
	return !printf("%lld\n", ans);
}