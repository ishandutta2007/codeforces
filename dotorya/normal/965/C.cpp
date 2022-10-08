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

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

int main() {
	ll N, K, M, D, i, j;
	scanf("%lld %lld %lld %lld", &N, &K, &M, &D);

	vector <ll> Vl;
	Vl.push_back(M);
	for (i = 1; i <= D; i++) {
		ll t = (i - 1)*K + 1;
		if (t > N) break;

		Vl.push_back(min(N / t, M));
	}
	
	ll dk = LL_INF;
	if (LL_INF / D >= K) dk = min(dk, D*K);
	ll ans = 0;
	for (auto it : Vl) {
		ll u = N / it;
		if (u > dk) continue;

		ll cc = (u + K - 1) / K;
		ans = max(ans, cc * it);
	}
	return !printf("%lld\n", ans);
}