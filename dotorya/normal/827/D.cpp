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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()

class edge {
public:
	int s, e, c;
	edge() {
		*this = edge(1, 2, 1);
	}
	edge(int s, int e, int c) : s(s), e(e), c(c) {}
};
vector <edge> Ve;
bool echk[200050];

int r[200050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

vector <int> conn[200050];
int tus = 0;
int lr[200050][2];
int dep[200050];
int par[200050][20][2];
void DFS(int n) {
	lr[n][0] = ++tus;
	int i, j;
	for (auto it : conn[n]) {
		int n2 = Ve[it].s ^ Ve[it].e ^ n;
		if (lr[n2][0]) continue;
		dep[n2] = dep[n] + 1;
		par[n2][0][0] = n;
		par[n2][0][1] = Ve[it].c;
		for (i = 1; i < 20; i++) {
			int tp = par[n2][i - 1][0];
			par[n2][i][0] = par[tp][i - 1][0];
			par[n2][i][1] = max(par[n2][i - 1][1], par[tp][i - 1][1]);
		}
		DFS(n2);
	}
	lr[n][1] = tus;
}
int getdis(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	int c = dep[b] - dep[a], i;

	int rv = 0;
	for (i = 19; i >= 0; i--) {
		if (c & (1 << i)) {
			rv = max(rv, par[b][i][1]);
			b = par[b][i][0];
		}
	}
	if (a == b) return rv;

	for (i = 19; i >= 0; i--) {
		if (par[a][i][0] != par[b][i][0]) {
			rv = max(rv, par[a][i][1]);
			rv = max(rv, par[b][i][1]);
			a = par[a][i][0];
			b = par[b][i][0];
		}
	}
	rv = max(rv, par[a][0][1]);
	rv = max(rv, par[b][0][1]);
	return rv;
}

class Node {
public:
	int it_max;
	vector <int> Vxn;
	vector <int> Vit;
	Node() {}
	void init() {
		sort(all(Vxn));
		Vxn.erase(unique(all(Vxn)), Vxn.end());
		for (it_max = 2; it_max < Vxn.size(); it_max *= 2);
		Vit.resize(2 * it_max);
		for (auto &it : Vit) it = INF;
	}
	void nupdate(int p, int v) {
		p = lower_bound(all(Vxn), p) - Vxn.begin();
		p += it_max;
		Vit[p] = min(Vit[p], v);
		for (p /= 2; p; p /= 2) Vit[p] = min(Vit[2 * p], Vit[2 * p + 1]);
	}
	int ngetmn(int p1, int p2) {
		p1 = lower_bound(all(Vxn), p1) - Vxn.begin();
		p2 = lower_bound(all(Vxn), p2 + 1) - Vxn.begin();
		p2--;

		int rv = INF;
		p1 += it_max;
		p2 += it_max;
		for (; p1 <= p2; p1 /= 2, p2 /= 2) {
			if (p1 % 2 == 1) rv = min(rv, Vit[p1++]);
			if (p2 % 2 == 0) rv = min(rv, Vit[p2--]);
		}
		return rv;
	}
};

Node indt[600000];
void update(int p1, int p2, int v) {
	p1 += IT_MAX - 1;
	for (; p1; p1 /= 2) indt[p1].nupdate(p2, v);
}
int getmn(int p1, int p2, int p3, int p4) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;

	int rv = INF;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = min(rv, indt[p1++].ngetmn(p3, p4));
		if (p2 % 2 == 0) rv = min(rv, indt[p2--].ngetmn(p3, p4));
	}
	return rv;
}

map <pii, int> ans;
int oin[200050][2];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		Ve.emplace_back(t1, t2, t3);
		oin[i][0] = t1, oin[i][1] = t2;
	}
	sort(all(Ve), [](edge a, edge b) {
		return a.c < b.c;
	});
	
	// Step 1 : Build MST + DFS, LCA
	for (i = 1; i <= N; i++) r[i] = i;
	for (i = 0; i < M; i++) {
		auto it = Ve[i];
		if (root(it.s) == root(it.e)) continue;
		r[root(it.s)] = root(it.e);
		conn[it.s].push_back(i);
		conn[it.e].push_back(i);
		echk[i] = true;
	}
	DFS(1);

	// Step 2 : Build 2D Segtree
	for (i = 0; i < M; i++) {
		if (echk[i]) continue;
		int s = Ve[i].s, e = Ve[i].e;
		if (lr[s][0] > lr[e][0]) swap(s, e);
		s = lr[s][0], e = lr[e][0];
		
		for (j = IT_MAX + s - 1; j; j /= 2) indt[j].Vxn.push_back(e);
	}
	for (i = 1; i < 2 * IT_MAX; i++) indt[i].init();
	for (i = 0; i < M; i++) {
		if (echk[i]) continue;
		int s = Ve[i].s, e = Ve[i].e;
		if (lr[s][0] > lr[e][0]) swap(s, e);
		s = lr[s][0], e = lr[e][0];
		update(s, e, Ve[i].c);
	}

	// Step 3 : Get answer
	for (i = 0; i < M; i++) {
		if (!echk[i]) {
			int s = Ve[i].s, e = Ve[i].e;
			assert(!ans.count(pii(s, e)));
			ans[pii(s, e)] = ans[pii(e, s)] = getdis(s, e);
			continue;
		}

		int s = Ve[i].s, e = Ve[i].e;
		if (dep[s] > dep[e]) swap(s, e);
		int rv = INF;
		rv = min(rv, getmn(1, lr[e][0] - 1, lr[e][0], lr[e][1]));
		rv = min(rv, getmn(lr[e][0], lr[e][1], lr[e][1] + 1, N));
		assert(!ans.count(pii(s, e)));
		ans[pii(s, e)] = ans[pii(e, s)] = rv;
	}

	for (i = 0; i < M; i++) {
		int x = ans[pii(oin[i][0], oin[i][1])];
		if (x == INF) printf("-1 ");
		else printf("%d ", x - 1);
	}
	return !printf("\n");
}