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

int IT_MAX = 1 << 17;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

class edge {
public:
	int s, e, f;
	edge() {
		s = e = f = 0;
	}
	edge(int s, int e, int f) : s(s), e(e), f(f) {}
};
vector <edge> Ve;
vector <int> conn[10050];
void epush(int s, int e, int f) {
	conn[s].push_back(Ve.size());
	conn[e].push_back(Ve.size() + 1);
	Ve.emplace_back(s, e, f);
	Ve.emplace_back(e, s, 0);
}

int dis[10050];
int dchk[10050];
int pos[10050];
int DFS(int n, int snk, int C) {
	if (n == snk) return 1;
	dchk[n] = C;
	for (; pos[n] < conn[n].size(); pos[n]++) {
		int it = conn[n][pos[n]];
		edge &ed = Ve[it];
		if (ed.f == 0 || dchk[ed.e] == C || dis[ed.e] != dis[ed.s] + 1) continue;
		if (DFS(ed.e, snk, C)) {
			Ve[it].f--;
			Ve[it ^ 1].f++;
			return 1;
		}
	}
	return 0;
}
int getFlow(int src, int snk) {
	int i, j;
	vector <int> Vu;
	for (i = 0; i <= snk; i++) dis[i] = INF, dchk[i] = pos[i] = 0;
	dis[src] = 0;
	Vu.push_back(src);
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			if (Ve[it].f == 0 || dis[Ve[it].e] != INF) continue;
			dis[Ve[it].e] = dis[Ve[it].s] + 1;
			Vu.push_back(Ve[it].e);
		}
	}
	if (dis[snk] == INF) return 0;

	int f = 0;
	while (DFS(src, snk, f + 1)) f++;
	return f;
}

int deg[4050];
int in[2050][2];

vector <int> Vl[4050];
bool echk[2050];
int main() {
	int N1, N2, M, i, j, k;
	scanf("%d %d %d", &N1, &N2, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		deg[t1]++, deg[N1 + t2]++;
		epush(t1, t2 + N1, 1);

		in[i][0] = t1, in[i][1] = t2;
	}
	int src = 0, snk = N1 + N2 + 1;
	for (i = 1; i <= N1; i++) epush(src, i, 0);
	for (i = 1; i <= N2; i++) epush(i + N1, snk, 0);

	int mn = INF;
	for (i = 1; i <= N1 + N2; i++) mn = min(mn, deg[i]);

	printf("0\n");
	for (int q = 1; q <= mn; q++) {
		for (auto &it : Ve) {
			if (it.s == src) it.f++;
			if (it.e == snk) it.f++;
		}

		int f = 0, t;
		while (t = getFlow(src, snk)) f += t;

		for (i = 1; i <= M; i++) echk[i] = false;
		vector <int> Va;
		for (i = 0; i < M; i++) if (Ve[2 * i].f == 0) Va.push_back(i + 1), echk[i + 1] = true;
		for (i = 1; i <= N1 + N2; i++) Vl[i].clear();
		for (i = 1; i <= M; i++) {
			if (echk[i]) continue;
			Vl[in[i][0]].push_back(i);
			Vl[in[i][1] + N1].push_back(i);
		}
		for (auto &it : Ve) {
			if (it.s != src && it.e != snk) continue;

			int t = it.f;
			int n = it.e;
			if (it.e == snk) n = it.s;
			for (i = 0; i < it.f; i++) Va.push_back(Vl[n][i]);
		}

		printf("%d ", (int)Va.size());
		for (auto it : Va) printf("%d ", it);
		printf("\n");
	}
	return 0;
}