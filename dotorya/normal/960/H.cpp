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

int IT_MAX = 1 << 20;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
//#define Se second
#define Fi first

namespace otree {
	vector <int> son[50050];
	int par[50050][20];
	int dep[50050];
	int lr[50050][2];
	int tus = 0;
	void DFS(int n) {
		lr[n][0] = ++tus;
		for (auto it : son[n]) {
			dep[it] = dep[n] + 1;
			par[it][0] = n;
			for (int i = 1; i < 20; i++) par[it][i] = par[par[it][i - 1]][i - 1];
			DFS(it);
		}
		lr[n][1] = tus;
	}
	int lca(int a, int b) {
		if (dep[a] > dep[b]) swap(a, b);
		int c = dep[b] - dep[a];
		for (int i = 0; i < 20; i++) if (c & (1 << i)) b = par[b][i];
		if (a == b) return a;

		for (int i = 19; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				a = par[a][i];
				b = par[b][i];
			}
		}
		return par[a][0];
	}
}

namespace segtree {
	class Node {
	public:
		ll v, sum;
		Node() {
			*this = Node(0, 0);
		}
		Node(ll v, ll sum) : v(v), sum(sum) {}	
	};
	Node indt[300000];

	ll val[300000];
	ll sum[300000];
	void propagate(int n, int S, int E) {
		ll v = indt[n].v;
		int M = (S + E) / 2;
		indt[2 * n].v += v;
		indt[2 * n].sum += (sum[M] - sum[S-1]) * v;
		indt[2 * n + 1].v += v;
		indt[2 * n + 1].sum += (sum[E] - sum[M]) * v;
		indt[n].v = 0;
	}
	void update(int st, int en, int S, int E, int n, ll v) {
		if (en < S || E < st) return;
		if (st <= S && E <= en) {
			indt[n].v += v;
			indt[n].sum += (sum[E] - sum[S-1])*v;
			return;
		}
		propagate(n, S, E);

		int M = (S + E) / 2;
		update(st, en, S, M, 2 * n, v);
		update(st, en, M + 1, E, 2 * n + 1, v);
		indt[n].sum = indt[2 * n].sum + indt[2 * n + 1].sum;
	}
	ll getsum(int st, int en, int S, int E, int n) {
		if (en < S || E < st) return 0;
		if (st <= S && E <= en) return indt[n].sum;
		propagate(n, S, E);

		int M = (S + E) / 2;
		return getsum(st, en, S, M, 2*n) + getsum(st, en, M + 1, E, 2 * n + 1);
	}
}
int ansc = 0;
db ans[50050];
int F[50050];
int fval[50050];

vector <pii> Qu[50050];

vector <int> Vx;
int ch1[50050];
vector <int> son[50050];
int par[50050];
int gpar[50050];
int sz[50050];
int val[50050];
int vsum[50050];
int lr[50050][2];
int tus = 0;
void DFS(int n) {
	lr[n][0] = ++tus;
	for (auto it : son[n]) DFS(it);
	lr[n][1] = tus;
}
int main() {
	int N, M, Q, C, i, j;
	scanf("%d %d %d %d", &N, &M, &Q, &C);
	for (i = 1; i <= N; i++) {
		scanf("%d", &F[i]);
		Qu[F[i]].emplace_back(1, i);
	}
	for (i = 2; i <= N; i++) {
		int t;
		scanf("%d", &t);
		otree::son[t].push_back(i);
	}
	for (i = 1; i <= M; i++) scanf("%d", &fval[i]);

	while (Q--) {
		int t1, t2, t3;
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d %d", &t2, &t3);
			Qu[F[t2]].emplace_back(2, t2);
			F[t2] = t3;
			Qu[F[t2]].emplace_back(1, t2);
		}
		else {
			scanf("%d", &t2);
			Qu[t2].emplace_back(3, ++ansc);
		}
	}
	for (i = 0; i < 20; i++) otree::par[1][i] = 1;
	otree::DFS(1);

	for (int co = 1; co <= M; co++) {
		if (Qu[co].empty()) continue;
		Vx.clear();
		for (auto it : Qu[co]) if (it.first != 3) Vx.push_back(it.second);
		Vx.push_back(1);
		sort(all(Vx), [](int a, int b) {
			return otree::lr[a][0] < otree::lr[b][0];
		});
		Vx.erase(unique(all(Vx)), Vx.end());
		
		int xc = Vx.size();
		for (int i = 0; i + 1 < xc; i++) {
			int t1 = Vx[i], t2 = Vx[i + 1];
			int r = otree::lca(t1, t2);
			if (r != t1 && r != t2) Vx.push_back(r);
		}
		sort(all(Vx), [](int a, int b) {
			return otree::lr[a][0] < otree::lr[b][0];
		});
		Vx.erase(unique(all(Vx)), Vx.end());

		int nc = Vx.size();
		for (int i = 0; i < nc; i++) ch1[Vx[i]] = i;

		vector <int> Vu;
		Vu.push_back(Vx[0]);
		for (int i = 1; i < nc; i++) {
			while (!Vu.empty()) {
				if (otree::lca(Vu.back(), Vx[i]) == Vu.back()) break;
				Vu.pop_back();
			}
			assert(!Vu.empty());
			son[ch1[Vu.back()]].push_back(i);
			par[i] = ch1[Vu.back()];
			Vu.push_back(Vx[i]);
		}
		for (i = 0; i < nc; i++) {
			if (Vx[i] == 1) val[i] = 1;
			else val[i] = otree::dep[Vx[i]] - otree::dep[Vx[par[i]]];
		}
		
		for (i = 0; i < nc; i++) {
			vsum[i] = val[i];
			if (i) vsum[i] += vsum[par[i]];
		}
		for (i = nc - 1; i >= 0; i--) {
			sz[i]++;
			for (auto it : son[i]) sz[i] += sz[it];
		}
		for (i = 0; i < nc; i++) {
			sort(all(son[i]), [](int a, int b) {
				return sz[a] > sz[b];
			});
		}
		DFS(0);
		for (i = 0; i < nc; i++) {
			gpar[i] = i;
			if (i && lr[par[i]][0] + 1 == lr[i][0]) gpar[i] = gpar[par[i]];
			segtree::val[lr[i][0]] = val[i];
		}
		for (i = 1; i <= nc; i++) segtree::sum[i] = segtree::sum[i - 1] + segtree::val[i];

		for (IT_MAX = 2; IT_MAX <= nc; IT_MAX *= 2);
		for (i = 1; i <= 2 * IT_MAX; i++) segtree::indt[i] = segtree::Node();
		
		ll s0 = N, s1 = 0, s2 = 0;
		for (auto it : Qu[co]) {
			int t1 = it.first, t2 = it.second;
			if (t1 == 1) {
				int n = ch1[t2];

				s1 += vsum[n];
				s2 += vsum[n];

				int t = n;
				while (1) {
					int x = gpar[t];
					s2 += 2 * segtree::getsum(lr[x][0], lr[t][0], 1, IT_MAX, 1);
					if (x == 0) break;
					t = par[x];
				}
				t = n;
				while (1) {
					int x = gpar[t];
					segtree::update(lr[x][0], lr[t][0], 1, IT_MAX, 1, 1);
					if (x == 0) break;
					t = par[x];
				}
			}
			if (t1 == 2) {
				int n = ch1[t2];

				int t = n;
				while (1) {
					int x = gpar[t];
					segtree::update(lr[x][0], lr[t][0], 1, IT_MAX, 1, -1);
					if (x == 0) break;
					t = par[x];
				}

				s1 -= vsum[n];
				s2 -= vsum[n];

				t = n;
				while (1) {
					int x = gpar[t];
					s2 -= 2 * segtree::getsum(lr[x][0], lr[t][0], 1, IT_MAX, 1);
					if (x == 0) break;
					t = par[x];
				}
			}
			if (t1 == 3) {
				db v = (db)s2 * fval[co] * fval[co] - (db)2 * C*s1*fval[co] + (db)C*C*s0;
				v /= N;
				ans[t2] = v;
			}
		}

		//vector <int> Vx;
		//int ch1[50050];
		//vector <int> son[50050];
		//int par[50050];
		//int gpar[50050];
		//int sz[50050];
		//int val[50050];
		//int vsum[50050];
		//int lr[50050][2];
		//int tus = 0;
		for (auto it : Vx) ch1[it] = 0;
		for (int i = 0; i < nc; i++) {
			son[i].clear();
			par[i] = gpar[i] = sz[i] = val[i] = vsum[i] = lr[i][0] = lr[i][1] = tus = 0;
		}
		Vx.clear();
	}
	for (int i = 1; i <= ansc; i++) printf("%.20lf\n", ans[i]);
	return 0;
}