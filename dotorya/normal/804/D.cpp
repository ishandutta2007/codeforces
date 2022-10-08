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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

class Node {
public:
	int mx, v;
	Node() { mx = 0, v = 0; }
};
Node indt[300050];
void update(int st, int en, int S, int E, int n, int v) {
	if (st > en) return;
	if (st == S && en == E) {
		indt[n].v += v;
		indt[n].mx += v;
		return;
	}

	indt[2 * n].v += indt[n].v;
	indt[2 * n].mx += indt[n].v;
	indt[2 * n + 1].v += indt[n].v;
	indt[2 * n + 1].mx += indt[n].v;
	indt[n].v = 0;

	int M = (S + E) / 2;
	update(st, min(en, M), S, M, 2 * n, v);
	update(max(M + 1, st), en, M + 1, E, 2 * n + 1, v);
	indt[n].mx = max(indt[2 * n].mx, indt[2 * n + 1].mx);
}

vector <int> conn[100050];
vector <int> son[100050];
int G[100050];
int gsz[100050];
vector <ll> gv[100050];
vector <ll> gvs[100050];
int dis[100050];

int lr[100050][2];
bool dchk[100050];
int lrc = 0;
void DFS1(int n) {
	dchk[n] = true;
	lr[n][0] = ++lrc;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		DFS1(it);
	}
	lr[n][1] = lrc;
}
void DFS2(int n, int g, int gs) {
	gv[g].push_back(indt[1].mx);
	gsz[g]++;

	for (auto it : son[n]) {
		update(1, gs, 1, IT_MAX, 1, 1);
		update(lr[it][0], lr[it][1], 1, IT_MAX, 1, -2);
		DFS2(it, g, gs);
		update(1, gs, 1, IT_MAX, 1, -1);
		update(lr[it][0], lr[it][1], 1, IT_MAX, 1, 2);
	}
}

int main() {
	int N, M, Q, i, j;
	scanf("%d %d %d", &N, &M, &Q);
	while (M--) {
		scanf("%d %d", &i, &j);
		conn[i].push_back(j);
		conn[j].push_back(i);
	}

	int gc = 0;
	for (i = 1; i <= N; i++) dis[i] = INF;
	for (i = 1; i <= N; i++) {
		if (G[i]) continue;
		G[i] = ++gc;
		vector <int> Vu;
		Vu.push_back(i);
		dis[i] = 0;
		for (j = 0; j < Vu.size(); j++) {
			for (auto it : conn[Vu[j]]) {
				if (G[it]) continue;
				G[it] = gc;
				dis[it] = dis[Vu[j]] + 1;
				Vu.push_back(it);
			}
		}
		lrc = 0;
		DFS1(i);

		for (IT_MAX = 2; IT_MAX < Vu.size(); IT_MAX *= 2);
		for (auto it : Vu) update(lr[it][0], lr[it][0], 1, IT_MAX, 1, dis[it]);
		DFS2(i, gc, Vu.size());
		for (j = 1; j <= 2 * IT_MAX; j++) indt[j].mx = indt[j].v = 0;
	}

	for (i = 1; i <= gc; i++) {
		sort(all(gv[i]));
		gvs[i].push_back(gv[i][0]);
		for (j = 1; j < gv[i].size(); j++) gvs[i].push_back(gvs[i].back() + gv[i][j]);
	}
	
	map <pii, db> Mx;
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		t1 = G[t1], t2 = G[t2];
		if (pii(gsz[t1], t1) > pii(gsz[t2], t2)) swap(t1, t2);
		if (t1 == t2) {
			printf("-1\n");
			continue;
		}
		if (Mx.count(pii(t1, t2))) {
			printf("%.20lf\n", Mx[pii(t1, t2)]);
			continue;
		}

		db s = 0;
		for (auto it : gv[t1]) {
			ll v = max(gv[t1].back(), gv[t2].back()) - it - 1;
			int p = lower_bound(all(gv[t2]), (int)v) - gv[t2].begin();

			s += (db)p * max(gv[t1].back(), gv[t2].back());
			s += gvs[t2].back() + (it+1) * (gv[t2].size() - p);
			if (p) s -= gvs[t2][p - 1];
		}
		s /= gv[t1].size();
		s /= gv[t2].size();
		Mx[pii(t1, t2)] = s;
		printf("%.20lf\n", s);
	}
	return 0;
}