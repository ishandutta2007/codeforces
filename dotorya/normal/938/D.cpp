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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <pll> conn[200050];
ll dis[200050];

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		ll t1, t2, t3;
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		conn[t1].emplace_back(t3*2, t2);
		conn[t2].emplace_back(t3*2, t1);
	}

	priority_queue <pll, vector<pll>, greater<pll>> Hx;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &dis[i]);
		Hx.emplace(dis[i], i);
	}
	while (!Hx.empty()) {
		pll u = Hx.top();
		Hx.pop();
		if (u.first != dis[u.second]) continue;

		for (auto it : conn[u.second]) {
			pll u2 = pll(it.first + u.first, it.second);
			if (dis[u2.second] > u2.first) {
				dis[u2.second] = u2.first;
				Hx.push(u2);
			}
		}
	}
	for (i = 1; i <= N; i++) printf("%lld ", dis[i]);
	return !printf("\n");
}