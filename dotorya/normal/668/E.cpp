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
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-16;

int N;
inline int ch(int x) {
	if (x > 0) return x;
	else return N - x;
}
inline int rch(int x) {
	if (x > N) return -(x - N);
	else return x;
}
vector <pii> in1;
vector <pii> in2;

void input() {
	int M1, M2, i, t1, t2;
	scanf("%d %d %d", &N, &M1, &M2);
	while (M1--) {
		scanf("%d %d", &t1, &t2);
		if (t1 == -t2) continue;
		in1.push_back(pii(t1, t2));
	}
	while (M2--) {
		scanf("%d %d", &t1, &t2);
		if (t1 == -t2) continue;
		in2.push_back(pii(t1, t2));
	}
}

vector <int> conn[2050];
vector <int> rconn[2050];
vector <int> gconn[2050];
vector <int> rgconn[2050];
vector <int> glist[2050];
vector <int> V;
bool dchk[2050];
int tchk[2050];
int G[2050];
int gchk[2050];
bool go[2050][2050];
void DFS1(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) if (!dchk[it]) DFS1(it);
	V.push_back(n);
}
void DFS2(int n, int g) {
	G[n] = g;
	for (auto it : rconn[n]) if (G[it] == 0) DFS2(it, g);
}

void update1(int);
void update2(int);

void update1(int n) {
	if (gchk[n] != 1) {
		gchk[n] = 1;
		for (auto it : glist[n]) {
			if (tchk[it] != 1) tchk[it] = 1;
			if (tchk[ch(-rch(it))] != -1) {
				tchk[ch(-rch(it))] = -1;
				update2(G[ch(-rch(it))]);
			}
		}
	}
	for (auto it : gconn[n]) if (!gchk[it]) update1(it);
}
void update2(int n) {
	if (gchk[n] != -1) {
		gchk[n] = -1;
		for (auto it : glist[n]) {
			if (tchk[it] != -1) tchk[it] = -1;
			if (tchk[ch(-rch(it))] != 1) {
				tchk[ch(-rch(it))] = 1;
				update1(G[ch(-rch(it))]);
			}
		}
	}
	for (auto it : rgconn[n]) if (!gchk[it]) update2(it);
}

void solve() {
	for (auto it : in1) {
		int t1 = it.first, t2 = it.second;
		conn[ch(-t1)].push_back(ch(t2));
		conn[ch(-t2)].push_back(ch(t1));
		rconn[ch(t1)].push_back(ch(-t2));
		rconn[ch(t2)].push_back(ch(-t1));
	}

	int i, j, gcnt = 0;
	for (i = 1; i <= 2 * N; i++) if (!dchk[i]) DFS1(i);
	while (!V.empty()) {
		int t = V.back();
		V.pop_back();
		if (G[t] == 0) DFS2(t, ++gcnt);
	}
	for (i = 1; i <= N; i++) if (G[i] == G[N + i]) return;

	for (i = 1; i <= 2*N; i++) {
		glist[G[i]].push_back(i);
		for (auto it : conn[i]) {
			if (G[i] == G[it]) continue;
			gconn[G[i]].push_back(G[it]);
			rgconn[G[it]].push_back(G[i]);
		}
	}

	for (i = 1; i <= gcnt; i++) {
		V.clear();
		go[i][i] = true;
		V.push_back(i);
		for (j = 0; j < V.size(); j++) {
			for (auto it : gconn[V[j]]) {
				if (go[i][it]) continue;
				V.push_back(it);
				go[i][it] = true;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		if (go[G[i]][G[i + N]]) {
			update1(G[i + N]);
			update2(G[i]);
		}
		if (go[G[i + N]][G[i]]) {
			update1(G[i]);
			update2(G[i + N]);
		}
	}

	for (auto it : in2) {
		int t1 = -it.first, t2 = -it.second;
		if (go[G[ch(t1)]][G[ch(-t2)]]) continue;
		if (go[G[ch(t2)]][G[ch(-t1)]]) continue;
		if (gchk[G[ch(t1)]] == -1 || gchk[G[ch(t2)]] == -1) continue;

		update1(G[ch(t1)]);
		update1(G[ch(t2)]);

		for (i = 1; i <= N; i++) if (tchk[i] == 0) update1(G[i]);
		for (i = 1; i <= N; i++) {
			if (tchk[i] == 1) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
		exit(0);
	}
}
void init() {
	int i, j;
	for (i = 1; i <= 2 * N; i++) {
		conn[i].clear();
		rconn[i].clear();
		gconn[i].clear();
		rgconn[i].clear();
		glist[i].clear();
		dchk[i] = false;
		G[i] = 0;
		for (j = 1; j <= 2 * N; j++) go[i][j] = false;
		gchk[i] = 0;
		tchk[i] = 0;
	}
	V.clear();
}
int main() {
	input();
	solve();
	init();
	swap(in1, in2);
	solve();
	return !printf("SIMILAR\n");
}