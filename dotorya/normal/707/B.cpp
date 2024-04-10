#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-11;

vector <pll> conn[100050];

bool chk[100050];
ll dis[100050];
priority_queue <pll, vector<pll>, greater<pll>> H;
int main() {
	int N, M, K, i, j;
	ll t1, t2, t3;
	scanf("%d %d %d", &N, &M, &K);
	while (M--) {
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		conn[t1].emplace_back(t3, t2);
		conn[t2].emplace_back(t3, t1);
	}

	fill(dis + 1, dis + N + 1, LL_INF);
	while (K--) {
		scanf("%lld", &t1);
		chk[t1] = true;
		dis[t1] = 0;
		H.emplace(0, t1);
	}
	while (!H.empty()) {
		pll u = H.top();
		H.pop();
		if (u.first > dis[u.second]) continue;

		for (auto it : conn[u.second]) {
			pll u2 = pll(u.first + it.first, it.second);
			if (u2.first < dis[u2.second]) {
				dis[u2.second] = u2.first;
				H.push(u2);
			}
		}
	}

	ll mn = LL_INF;
	for (i = 1; i <= N; i++) if (!chk[i]) mn = min(mn, dis[i]);
	if (mn == LL_INF) mn = -1;
	return !printf("%lld\n", mn);
}