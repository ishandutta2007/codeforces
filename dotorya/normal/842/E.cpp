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
const ll MOD = 1000000007;
const int INF = 0x1f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <pii> Vu;
vector <pii> Vu2;
pair<pii, pii> operator + (pair<pii, pii> a, pair<pii, pii> b) {
	if (a > b) swap(a, b);

	pair<pii, pii> rv;
	if (a.first.first == b.first.first) {
		rv.first = pii(a.first.first, a.first.second + b.first.second);
		if (a.second.first != b.second.first) rv.second = max(a.second, b.second);
		else rv.second = pii(a.second.first, a.second.second + b.second.second);
	}
	else {
		rv.first = b.first;
		if (b.second.first != a.first.first) rv.second = max(b.second, a.first);
		else rv.second = pii(b.second.first, b.second.second + a.first.second);
	}
	return rv;
}
class Node {
public:
	int v;
	pair<pii, pii> mx;
	Node() {
		v = 0;
		mx = mp(pii(-INF, 1), pii(-2 * INF, 1));
	}
};
Node indt[1100000];
void propagate(int n) {
	int v = indt[n].v;
	indt[2 * n].v += v;
	indt[2 * n].mx.first.first += v;
	indt[2 * n].mx.second.first += v;
	indt[2 * n + 1].v += v;
	indt[2 * n + 1].mx.first.first += v;
	indt[2 * n + 1].mx.second.first += v;
	indt[n].v = 0;
}
void update(int st, int en, int S, int E, int n, int v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].v = indt[n].v + v;
		indt[n].mx.first.first += v;
		indt[n].mx.second.first += v;
		return;
	}
	propagate(n);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].mx = indt[2 * n].mx + indt[2 * n + 1].mx;
}
pair<pii, pii> getmx(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return mp(pii(-3 * INF, 1), pii(-3 * INF - 1, 1));
	if (st <= S && E <= en) return indt[n].mx;
	propagate(n);

	int M = (S + E) / 2;
	return getmx(st, en, S, M, 2 * n) + getmx(st, en, M + 1, E, 2 * n + 1);
}

int lr[300050][2];
int rlr[300050];
int par[300050][20];
int dep[300050];
int tus;
vector <int> son[300050];
bool dchk[300050];
void DFS(int n) {
	dchk[n] = true;
	lr[n][0] = ++tus;
	rlr[tus] = n;
	for (auto it : son[n]) {
		for (int i = 1; i <= 19; i++) par[it][i] = par[par[it][i - 1]][i - 1];
		dep[it] = dep[n] + 1;
		DFS(it);
	}
	lr[n][1] = tus;
}
int dis(int a, int b) {
	int rv = 0;
	if (dep[a] > dep[b]) swap(a, b);

	int c = dep[b] - dep[a];
	rv += c;
	for (int i = 19; i >= 0; i--) if (c & (1 << i)) b = par[b][i];
	if (a == b) return rv;
	for (int i = 19; i >= 0; i--) {
		if (par[a][i] == par[b][i]) continue;
		rv += 1 << (i + 1);
		a = par[a][i];
		b = par[b][i];
	}
	return rv + 2;
}
int getnxt(int a, int b) {
	if (dep[a] >= dep[b] || dep[b] - dep[a] != dis(a, b)) return par[a][0];

	int c = dep[b] - dep[a] - 1;
	for (int i = 19; i >= 0; i--) if (c & (1 << i)) b = par[b][i];
	return b;
}

int deg[300050];
int main() {
	int N, i;
	scanf("%d", &N);
	//N = 300000;
	for (i = 0; i <= 19; i++) par[1][i] = 1;
	for (i = 2; i <= N + 1; i++) {
		scanf("%d", &par[i][0]);
		//par[i][0] = 1;
		son[par[i][0]].push_back(i);
	}
	DFS(1);

	update(1, 1, 1, IT_MAX, 1, INF);
	int n = 1, r = 0;
	for (i = 2; i <= N + 1; i++) {
		int p = par[i][0], x = i;
		int pmx = 0;
		int t = getnxt(n, x);
		if (par[t][0] == n) pmx = getmx(lr[t][0], lr[t][1], 1, IT_MAX, 1).first.first;
		else pmx = max(getmx(1, lr[n][0] - 1, 1, IT_MAX, 1).first.first, getmx(lr[n][1] + 1, IT_MAX, 1, IT_MAX, 1).first.first);
		pmx = max(pmx, 0);

		int nd = dis(n, x);
		t = getmx(lr[x][0], lr[x][0], 1, IT_MAX, 1).first.first;
		update(lr[x][0], lr[x][0], 1, IT_MAX, 1, nd - t);

		if (pmx >= r / 2 && nd > pmx) {
			r++;
			if (nd * 2 > r) {
				int nn = getnxt(n, x);
				if (par[n][0] == nn) {
					update(1, IT_MAX, 1, IT_MAX, 1, -1);
					update(lr[n][0], lr[n][1], 1, IT_MAX, 1, 2);
				}
				else {
					update(1, IT_MAX, 1, IT_MAX, 1, 1);
					update(lr[nn][0], lr[nn][1], 1, IT_MAX, 1, -2);
				}
				n = nn;
			}
		}

		deg[p]++;
		deg[x]++;
		if (deg[p] == 2) update(lr[p][0], lr[p][0], 1, IT_MAX, 1, -INF);

		auto u = indt[1].mx;
		int ans = 0;
		if (r % 2 == 0) {
			if (u.first.first >= r / 2) ans += u.first.second;
			if (u.second.first >= r / 2) ans += u.second.second;
		}
		else {
			int st = 1, en = IT_MAX, mi, nx = 1, rv = IT_MAX;
			while (st < en) {
				int mi = (st + en) / 2;
				propagate(nx);

				if (indt[2*nx].mx.first.first >= (r + 1) / 2) {
					nx = 2 * nx;
					en = mi;
				}
				else {
					nx = 2 * nx + 1;
					st = mi + 1;
				}
			}
			int t = rlr[st];

			int nn = getnxt(n, t);
			pair<pii, pii> u1, u2;
			if (par[n][0] == nn) {
				u1 = getmx(lr[n][0], lr[n][1], 1, IT_MAX, 1);
				u2 = getmx(1, lr[n][0] - 1, 1, IT_MAX, 1) + getmx(lr[n][1] + 1, IT_MAX, 1, IT_MAX, 1);
			}
			else {
				u1 = getmx(1, lr[nn][0] - 1, 1, IT_MAX, 1) + getmx(lr[nn][1] + 1, IT_MAX, 1, IT_MAX, 1);
				u2 = getmx(lr[nn][0], lr[nn][1], 1, IT_MAX, 1);
			}
			if (u1.first.first >= r / 2) ans += u1.first.second;
			if (u1.second.first >= r / 2) ans += u1.second.second;
			if (u2.first.first >= (r + 1) / 2) ans += u2.first.second;
			if (u2.second.first >= (r + 1) / 2) ans += u2.second.second;
		}
		printf("%d\n", ans);
	}
	return 0;
}