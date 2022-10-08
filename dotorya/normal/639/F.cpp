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
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

class edge {
public:
	int x, y;
	edge() {
		*this = edge(0, 0);
	}
	edge(int x, int y) : x(x), y(y) {};
};
inline void epush(vector <edge>& E, vector <int>* c, int s, int e) {
	if (s == e) return;
	edge ed = edge(s, e);
	c[s].push_back(E.size());
	c[e].push_back(E.size());
	E.push_back(ed);
}


bool Echk[300050];
bool dchk[300050];
int low[300050];
int dep[300050];
int par[300050];
int r[300050];
int tmpch[300050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
void DFS(vector <edge>& E, vector <int>* c, bool* echk, int n) {
	dchk[n] = true;
	low[n] = dep[n];
	for (auto it : c[n]) {
		edge& ed = E[it];
		if (ed.y == n) swap(ed.x, ed.y);
		if (it == par[n]) continue;
		if (dchk[ed.y]) low[n] = min(low[n], dep[ed.y]);
		else {
			int t = ed.y;
			dep[t] = dep[n] + 1;
			par[t] = it;
			DFS(E, c, echk, t);
			if (low[t] > dep[n]) echk[it] = true;
			low[n] = min(low[n], low[t]);
		}
	}
}
bool getbcc(vector <edge>& E, vector <int>* c, bool* vchk, bool* echk, int n, int* g, int* gc) {
	int i, j;
	fill(dchk + 1, dchk + n + 1, false);
	fill(echk, echk + E.size(), false);
	fill(par + 1, par + n + 1, -1);

	for (i = 1; i <= n; i++) if (!dchk[i]) DFS(E, c, echk, i);

	for (i = 1; i <= n; i++) r[i] = i;
	for (i = 0; i < E.size(); i++) {
		if (echk[i]) continue;
		int t1 = root(E[i].x);
		int t2 = root(E[i].y);
		if (t1 != t2) r[t1] = t2;
	}

	*gc = 0;
	fill(tmpch + 1, tmpch + n + 1, -1);
	for (i = 1; i <= n; i++) {
		if (root(i) != i) continue;
		tmpch[i] = ++(*gc);
	}

	for (i = 1; i <= n; i++) g[i] = tmpch[root(i)];

	int v = -1;
	for (i = 1; i <= n; i++) {
		if (!vchk[i]) continue;
		if (v == -1) v = g[i];
		else if (v != g[i]) break;
	}
	return i > n;
}
vector <edge> Ex;
vector <int> conn[300050];
int ch[300050];
vector <edge> Ex2;
vector <int> conn2[300050];
bool dchk2[300050];
int ch2[300050];
int c2 = 0;
int par2[300050][20];
int dep2[300050];
void DFS2(int n) {
	dchk2[n] = true;
	ch2[n] = ++c2;
	for (auto it : conn2[n]) {
		edge &ed = Ex2[it];
		if (ed.x != n) swap(ed.x, ed.y);

		if (dchk2[ed.y]) continue;
		dep2[ed.y] = dep2[n] + 1;
		par2[ed.y][0] = n;
		for (int i = 1; i < 20; i++) par2[ed.y][i] = par2[par2[ed.y][i - 1]][i - 1];
		DFS2(ed.y);
	}
}
int lca(int a, int b) {
	if (dep2[a] > dep2[b]) swap(a, b);
	
	int c = dep2[b] - dep2[a];
	for (int i = 19; i >= 0; i--) if (c & (1 << i)) b = par2[b][i];

	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (par2[a][i] != par2[b][i]) {
			a = par2[a][i];
			b = par2[b][i];
		}
	}
	if (par2[a][0] != par2[b][0]) return -1;
	else return par2[a][0];
}

inline int rotate1(int e, int R, int N) {
	e = (e + R) % N;
	if (e == 0) e = N;
	return e;
}
vector <int> V;
vector <pii> ED;
vector <edge> Ex3;
vector <int> conn3[300050];
int ch3[300050];
int bchk[300050];
bool bchk2[300050];
int ch4[300050];
int main() {
	int N, M, Q, i, j, t1, t2, t3, R = 0, oN;
	int* gcnt = (int*) calloc(1, sizeof(int));
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		epush(Ex, conn, t1, t2);
	}

	getbcc(Ex, conn, bchk2, Echk, N, ch, gcnt);
	oN = N;
	N = *gcnt;
	for (i = 0; i < Ex.size(); i++) {
		if (!Echk[i]) continue;
		epush(Ex2, conn2, ch[Ex[i].x], ch[Ex[i].y]);
	}
	for (i = 1; i <= N; i++) {
		if (dchk2[i]) continue;
		for (j = 0; j < 20; j++) par2[i][j] = i;
		DFS2(i);
	}
	for(int q = 1; q <= Q; q++) {
		int t5;
		scanf("%d %d", &t1, &t5);
		for (i = 1; i <= t1; i++) {
			scanf("%d", &t2);
			t2 = rotate1(t2, R, oN);
			V.push_back(ch[t2]);
			bchk[ch[t2]] = q;
		}
		for (i = 1; i <= t5; i++) {
			scanf("%d %d", &t2, &t3);
			t2 = ch[rotate1(t2, R, oN)];
			t3 = ch[rotate1(t3, R, oN)];
			if (t2 == t3) continue;

			ED.push_back(pii(t2, t3));
			V.push_back(t2);
			V.push_back(t3);
		}
		sort(V.begin(), V.end(), [](int a, int b) {return ch2[a] < ch2[b]; });
		V.erase(unique(V.begin(), V.end()), V.end());

		int t10 = V.size() - 1;
		for (i = 0; i < t10; i++) {
			int t6 = lca(V[i], V[i + 1]);
			if (t6 != -1) V.push_back(t6);
		}
		sort(V.begin(), V.end(), [](int a, int b) {return ch2[a] < ch2[b]; });
		V.erase(unique(V.begin(), V.end()), V.end());

		for (i = 0; i < V.size(); i++) ch3[V[i]] = i + 1;

		for (i = 0; i < V.size(); i++) {
			t1 = -1, t2 = -1;
			if (i != 0) t1 = lca(V[i - 1], V[i]);
			if (i + 1 != V.size()) t2 = lca(V[i], V[i + 1]);

			if (t1 == -1) swap(t1, t2);
			if (t1 == -1) continue;
			if (t2 != -1 && t2 != V[i] && dep2[t2] > dep2[t1]) swap(t1, t2);
			if (V[i] != t1) epush(Ex3, conn3, ch3[V[i]], ch3[t1]);
		}
		for (auto it : ED) epush(Ex3, conn3, ch3[it.first], ch3[it.second]);
		for (i = 0; i < V.size(); i++) {
			if (bchk[V[i]] == q) bchk2[i + 1] = true;
			else bchk2[i + 1] = false;
		}
		if (getbcc(Ex3, conn3, bchk2, Echk, V.size(), ch4, gcnt)) {
			R = (R + q) % oN;
			printf("YES\n");
		}
		else printf("NO\n");

		Ex3.clear();
		for (i = 1; i <= V.size(); i++) conn3[i].clear();
		ED.clear();
		V.clear();
	}
	return 0;
}
//*/