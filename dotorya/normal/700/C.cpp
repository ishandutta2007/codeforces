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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int ANS = 2 * INF;
vector <int> ans;

class edge {
public:
	int s, e, c;
	int ec;
	edge() {
		*this = edge(0, 0, 0, 0);
	}
	edge(int s, int e, int c, int ec) : s(s), e(e), c(c), ec(ec) {}
};
edge in[30050];
vector <int> conn[1050];

bool vchk[1050];
int rev[1050];
vector <int> V;
vector <int> Ve;
bool BFS(int N, int S, int E) {
	V.clear();
	fill(vchk + 1, vchk + N + 1, false);
	fill(rev + 1, rev + N + 1, -1);
	V.push_back(S);
	vchk[S] = true;
	for (int i = 0; i < V.size(); i++) {
		for (auto it : conn[V[i]]) {
			int v = 1;
			if (in[it].e == V[i]) v = 2;
			if (in[it].ec & v) continue;

			int n = in[it].s^in[it].e^V[i];
			if (!vchk[n]) {
				vchk[n] = true;
				rev[n] = it;
				V.push_back(n);
			}
		}
	}
	V.clear();
	if (!vchk[E]) return false;

	while (E != S) {
		int v = 1;
		if (in[rev[E]].s == E) v = 2;
		in[rev[E]].ec |= v;

		Ve.push_back(rev[E]);
		E = in[rev[E]].s ^ in[rev[E]].e ^ E;
	}
	return true;
}

int par[1050];
int dep[1050];
int low[1050];
bool echk[50050];
void aa(int n) {
	vchk[n] = true;
	low[n] = dep[n];

	for (auto it : conn[n]) {
		if (in[it].ec == 3) continue;
		int v = in[it].s ^ in[it].e ^ n;
		if (par[n] == it) continue;
		if (vchk[v]) low[n] = min(low[n], dep[v]);
		else {
			par[v] = it;
			dep[v] = dep[n] + 1;
			aa(v);
			if (low[v] > dep[n]) echk[it] = true;
			low[n] = min(low[n], low[v]);
		}
	}
}

int r[1050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int gcnt;
int G[1050];
vector <int> gconn[1050];
int gch[1050];
void getBCC(int N, int M) {
	int i;

	fill(vchk + 1, vchk + N + 1, false);
	fill(G + 1, G + N + 1, 0);
	fill(echk + 1, echk + M + 1, false);

	for (i = 1; i <= N; i++) {
		if (!vchk[i]) {
			dep[i] = 0;
			par[i] = -1;
			aa(i);
		}
	}
	for (i = 1; i <= N; i++) r[i] = i;
	for (i = 1; i <= M; i++) {
		if (in[i].ec == 3) continue;
		if (echk[i]) continue;
		int s = root(in[i].s);
		int e = root(in[i].e);
		r[s] = e;
	}

	for (i = 1; i <= N; i++) gch[i] = 0;
	gcnt = 0;
	for (i = 1; i <= N; i++) {
		if (gch[root(i)] == 0) gch[root(i)] = ++gcnt;
		G[i] = gch[root(i)];
	}
	for (i = 1; i <= N; i++) gconn[i].clear();
	for (i = 1; i <= M; i++) {
		if (in[i].ec == 3) continue;
		if (!echk[i]) continue;
		gconn[G[in[i].s]].push_back(i);
		gconn[G[in[i].e]].push_back(i);
	}
}

void getans(int N, int M, int S, int E) {
	if (S == E) return;

	Ve.clear();
	BFS(N, S, E);
	BFS(N, S, E);
	
	int i;
	for (i = 1; i <= M; i++) in[i].ec = 0;
	for (auto it2 : Ve) {
		in[it2].ec = 3;
		getBCC(N, M);
		in[it2].ec = 0;
		if (G[S] == G[E]) continue;

		V.clear();
		fill(vchk + 1, vchk + gcnt + 1, false);
		fill(rev + 1, rev + gcnt + 1, -1);
		vchk[G[S]] = true;
		V.push_back(G[S]);
		for (i = 0; i < V.size(); i++) {
			for (auto it : gconn[V[i]]) {
				int t = G[in[it].s] ^ G[in[it].e] ^ V[i];
				if (!vchk[t]) {
					vchk[t] = true;
					rev[t] = it;
					V.push_back(t);
				}
			}
		}

		V.clear();
		int e = G[E];
		while (e != G[S]) {
			V.push_back(rev[e]);

			e = G[in[rev[e]].s] ^ G[in[rev[e]].e] ^ e;
		}
		for (auto it : V) {
			if (in[it].c + in[it2].c < ANS) {
				ANS = in[it].c + in[it2].c;
				ans.clear();
				ans.push_back(it);
				ans.push_back(it2);
			}
		}
		V.clear();
	}
	Ve.clear();
}

vector <int> V1;
int Gt[1050];
int main() {
	int N, M, S, E, i, j, t1, t2, t3;

	scanf("%d %d", &N, &M);
	scanf("%d %d", &S, &E);
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		in[i] = edge(t1, t2, t3, 0);
		conn[t1].push_back(i);
		conn[t2].push_back(i);
	}

	if (!BFS(N, S, E)) return !printf("0\n0\n\n");
	Ve.clear();
	for (i = 1; i <= M; i++) in[i].ec = 0;

	getBCC(N, M);
	if (G[S] == G[E]) getans(N, M, S, E);
	else {
		V.clear();
		fill(vchk + 1, vchk + gcnt + 1, false);
		fill(rev + 1, rev + gcnt + 1, -1);
		vchk[G[S]] = true;
		V.push_back(G[S]);
		for (i = 0; i < V.size(); i++) {
			for (auto it : gconn[V[i]]) {
				int t = G[in[it].s] ^ G[in[it].e] ^ V[i];
				if (!vchk[t]) {
					vchk[t] = true;
					rev[t] = it;
					V.push_back(t);
				}
			}	
		}

		V.clear();
		int e = G[E];
		while (e != G[S]) {
			V.push_back(rev[e]);
			
			e = G[in[rev[e]].s] ^ G[in[rev[e]].e] ^ e;
		}
		for (auto it : V) {
			if (in[it].c < ANS) {
				ANS = in[it].c;
				ans.clear();
				ans.push_back(it);
			}
		}
		
		V1.push_back(S);
		for (i = V.size() - 1; i >= 0; i--) {
			int t2 = in[V[i]].e;
			if (G[V1.back()] != G[t2]) t2 = in[V[i]].s;
			V1.push_back(t2);
			V1.push_back(in[V[i]].s ^ in[V[i]].e ^ t2);
		}
		V1.push_back(E);
		for (i = 1; i <= N; i++) Gt[i] = G[i];
		
		for (i = 0; i + 1 < V1.size(); i++) if(Gt[V1[i]] == Gt[V1[i+1]]) getans(N, M, V1[i], V1[i + 1]);
	}

	if (ANS == INF * 2) return !printf("-1\n");

	printf("%d\n", ANS);
	printf("%d\n", ans.size());
	for (auto it : ans) printf("%d ", it);
	return !printf("\n");
}