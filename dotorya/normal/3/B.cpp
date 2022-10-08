#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

vector <pll> Vin[3];
ll sum[3][2000050];
int main() {
	int N, V, i, j, t1, t2;
	scanf("%d %d", &N, &V);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &t1, &t2);
		Vin[t1].emplace_back(t2, i);
	}
	for (i = 1; i <= 2; i++) sort(all(Vin[i]), [](pll a, pll b) { return a > b; });
	for (i = 1; i <= 2; i++) {
		if (Vin[i].empty()) continue;
		sum[i][1] = Vin[i][0].first;
		for (j = 1; j < Vin[i].size(); j++) sum[i][j + 1] = sum[i][j] + Vin[i][j].first;
	}

	ll mx = -INF, a1 = 0, a2 = 0;
	for (i = 0; i <= Vin[2].size(); i++) {
		int t = min((int)Vin[1].size(), V - 2 * i);
		if (t < 0) break;

		ll v = sum[1][t] + sum[2][i];
		if (v > mx) {
			mx = v;
			a1 = t;
			a2 = i;
		}
	}
	printf("%lld\n", mx);
	for (i = 0; i < a1; i++) printf("%lld ", Vin[1][i].second);
	for (i = 0; i < a2; i++) printf("%lld ", Vin[2][i].second);
	return !printf("\n");
}