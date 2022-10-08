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

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <pair<int, pii>> Vx[600000];
void initupdate(int st, int en, int S, int E, int n, pair<int, pii> v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		Vx[n].push_back(v);
		return;
	}

	int M = (S + E) / 2;
	initupdate(st, en, S, M, 2 * n, v);
	initupdate(st, en, M + 1, E, 2 * n + 1, v);
}


map <pii, int> Mp;
map <pii, int> Mv;
int Qu[200050][2];

int val[30];
int r[200050][2];
int sz[200050];

int cur = 0;
vector <pair<pii, int>> Vr[600050];
vector <pair<int, int>> Vsz[600050];
vector <pair<int, int>> Vval[600050];

void updateval(int x) {
	int i;
	for (i = 29; i >= 0; i--) {
		if (x & (1 << i));
		else continue;

		if (val[i]) x ^= val[i];
		else {
			Vval[cur].emplace_back(i, val[i]);
			val[i] = x;
			return;
		}
	}
}
pii root(int x) {
	int ro = x, v = 0;
	while (ro != r[ro][0]) {
		v ^= r[ro][1];
		ro = r[ro][0];
	}
	return pii(ro, v);
}
void mymerge(int a, int b, int c) {
	pii u1 = root(a);
	pii u2 = root(b);

	int r1 = u1.first, r2 = u2.first;
	c ^= u1.second ^ u2.second;
	if (r1 != r2) {
		if (sz[r1] > sz[r2]) swap(r1, r2);
		Vr[cur].emplace_back(pii(r1, 0), r[r1][0]);
		Vr[cur].emplace_back(pii(r1, 1), r[r1][1]);
		Vsz[cur].emplace_back(r2, sz[r2]);
		r[r1][0] = r2;
		r[r1][1] = c;
		sz[r2] += sz[r1];
	}
	else updateval(c);
}
void getans(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return;
	
	cur = n;
	for (auto it : Vx[n]) {
		int c = it.first, x = it.second.first, y = it.second.second;
		mymerge(x, y, c);
	}
	if (S == E) {
		int x = Qu[S][0], y = Qu[S][1];
		pii u1 = root(x), u2 = root(y);
		
		int c = u1.second ^ u2.second;
		for (int i = 29; i >= 0; i--) {
			if (!(c & (1 << i))) continue;
			if (!val[i]) continue;
			c ^= val[i];
		}
		printf("%d\n", c);
	}
	else {
		int M = (S + E) / 2;
		getans(st, en, S, M, 2 * n);
		getans(st, en, M + 1, E, 2 * n + 1);
	}
	reverse(all(Vr[n]));
	reverse(all(Vsz[n]));
	reverse(all(Vval[n]));
	for (auto it : Vr[n]) r[it.first.first][it.first.second] = it.second;
	for (auto it : Vsz[n]) sz[it.first] = it.second;
	for (auto it : Vval[n]) val[it.first] = it.second;
	Vr[n].clear();
	Vsz[n].clear();
	Vval[n].clear();
}

int ux[200050][4];
int main() {
	int N, M, Q, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 > t2) swap(t1, t2);
		Mp[pii(t1, t2)] = 1;
		Mv[pii(t1, t2)] = t3;
	}
	
	int qc = 0, cc = 0;
	scanf("%d", &Q);
	for (i = 1; i <= Q; i++) {
		scanf("%d %d %d", &ux[i][0], &ux[i][1], &ux[i][2]);
		if (ux[i][0] == 1) scanf("%d", &ux[i][3]);
		if (ux[i][0] == 3) cc++;
	}
	for (IT_MAX = 2; IT_MAX <= cc; IT_MAX *= 2);
	for(i = 1; i <= Q; i++) {
		int t1 = ux[i][0], t2 = ux[i][1], t3 = ux[i][2], t4 = ux[i][3];
		if (t2 > t3) swap(t2, t3);
		if (t1 == 1) {
			Mp[pii(t2, t3)] = qc + 1;
			Mv[pii(t2, t3)] = t4;
		}
		else if (t1 == 2) {
			int st = Mp[pii(t2, t3)], en = qc;
			initupdate(st, en, 1, IT_MAX, 1, mp(Mv[pii(t2, t3)], pii(t2, t3)));
			Mp.erase(pii(t2, t3));
			Mv.erase(pii(t2, t3));
		}
		else if (t1 == 3) {
			qc++;
			Qu[qc][0] = t2, Qu[qc][1] = t3;
		}
	}
	for (auto it : Mp) initupdate(it.second, qc, 1, IT_MAX, 1, mp(Mv[it.first], it.first));

	for (i = 1; i <= N; i++) r[i][0] = i, r[i][1] = 0, sz[i] = 1;
	getans(1, qc, 1, IT_MAX, 1);
	return 0;
}