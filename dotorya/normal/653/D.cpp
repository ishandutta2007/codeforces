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
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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

int IT_MAX = 1 << 17;
const ll MOD = 987654321;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

class edge {
public:
	int s, e;
	ll f;
	edge() {
		*this = edge(0, 0, 0);
	}
	edge(int s, int e, ll f) : s(s), e(e), f(f){};
};
vector <edge> E;
vector <int> conn[55];
void einit(int snk) {
	E.clear();
	for (int i = 1; i <= snk; i++) conn[i].clear();
}
void epush(int s, int e, ll f) {
	edge e1 = edge(s, e, f);
	edge e2 = edge(e, s, 0);
	conn[s].push_back(E.size());
	conn[e].push_back(E.size() + 1);
	E.push_back(e1);
	E.push_back(e2);
}

int X;
ll dchk[55];
ll DFS(int n, int snk, ll C, ll cf) {
	if (n == snk) return cf;
	dchk[n] = C;
	for (auto it : conn[n]) {
		edge &ed = E[it];
		if (dchk[ed.e] == C || ed.f == 0) continue;
		ll t;
		if ((t = DFS(ed.e, snk, C, min(cf, ed.f))) != 0) {
			ed.f -= t;
			E[it ^ 1].f += t;
			return t;
		}
	}
	return 0;
}
ll getFlow(int snk) {

	fill(dchk + 1, dchk + snk + 1, 0);
	ll f = 0, t;
	while ((t = DFS(1, snk, f + 1, X)) != 0) {
		f += t;
		if (f >= X) return X;
	}
	return f;
}

int in[505][3];
int main() {
	int N, M, i, j;
	scanf("%d %d %d", &N, &M, &X);
	for (i = 1; i <= M; i++) scanf("%d %d %d", &in[i][0], &in[i][1], &in[i][2]);
	
	ldb st = ERR, en = INF, mi;
	for (i = 1; i <= 200; i++) {
		mi = (st + en) / 2;

		einit(N);
		for (j = 1; j <= M; j++) {
			ll u = (ll)(in[j][2] / mi);
			epush(in[j][0], in[j][1], min(u, (ll)X));
		}
		if (getFlow(N) >= X) st = mi;
		else en = mi;
	}
	printf("%.20lf\n", (db)(mi*X));
	return 0;
}
//*/