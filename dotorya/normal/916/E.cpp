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
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

class Node {
public:
	ll sum, v;
	Node() {
		sum = v = 0;
	}
} indt[300000];
int getlen(int n) {
	int rv = 1;
	while (n < IT_MAX) {
		rv *= 2;
		n *= 2;
	}
	return rv;
}
void propagate(int n) {
	ll v = indt[n].v;

	int L = getlen(n);

	indt[2 * n].v += v;
	indt[2 * n].sum += v * (L / 2);
	indt[2 * n + 1].v += v;
	indt[2 * n + 1].sum += v * (L / 2);
	indt[n].v = 0;
}
void update(int st, int en, int S, int E, int n, ll v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].v += v;
		indt[n].sum += v * (E - S + 1);
		return;
	}
	propagate(n);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].sum = indt[2 * n].sum + indt[2 * n + 1].sum;
}
ll getsum(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return 0;
	if (st <= S && E <= en) return indt[n].sum;
	propagate(n);

	int M = (S + E) / 2;
	return getsum(st, en, S, M, 2 * n) + getsum(st, en, M + 1, E, 2 * n + 1);
}

vector <int> conn[100050];
map <int, int> Mx[100050];
int lr[100050][2];
int par[100050][20];
int dep[100050];
int tus;
bool dchk[100050];
void DFS(int n) {
	dchk[n] = true;
	lr[n][0] = ++tus;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		par[it][0] = n;
		for (int i = 1; i < 20; i++) par[it][i] = par[par[it][i - 1]][i - 1];
		dep[it] = dep[n] + 1;
		DFS(it);
		Mx[n][lr[it][0]] = it;
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

ll oin[100050];
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) scanf("%lld", &oin[i]);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	for (i = 0; i < 20; i++) par[1][i] = 1;
	DFS(1);

	for (i = 1; i <= N; i++) update(lr[i][0], lr[i][0], 1, IT_MAX, 1, oin[i]);

	int ro = 1;
	while (Q--) {
		int t1, t2, t3, t4;
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d", &t2);
			ro = t2;
		}
		else if (t1 == 2) {
			scanf("%d %d %d", &t2, &t3, &t4);

			int lc = lca(t2, t3);
			int lc2 = lca(t2, ro);
			int lc3 = lca(t3, ro);

			if (dep[lc2] > dep[lc]) lc = lc2;
			if (dep[lc3] > dep[lc]) lc = lc3;

			if (lr[lc][0] > lr[ro][0] || lr[lc][1] < lr[ro][0]) update(lr[lc][0], lr[lc][1], 1, IT_MAX, 1, t4);
			else if (lc == ro) update(1, N, 1, IT_MAX, 1, t4);
			else {
				auto it = Mx[lc].lower_bound(lr[ro][0] + 1);
				it--;
				update(1, N, 1, IT_MAX, 1, t4);
				update(lr[it->second][0], lr[it->second][1], 1, IT_MAX, 1, -t4);
			}
		}
		else {
			scanf("%d", &t2);
			if (lr[t2][0] > lr[ro][0] || lr[t2][1] < lr[ro][0]) printf("%lld\n", getsum(lr[t2][0], lr[t2][1], 1, IT_MAX, 1));
			else if (t2 == ro) printf("%lld\n", indt[1].sum);
			else {
				auto it = Mx[t2].lower_bound(lr[ro][0] + 1);
				it--;
				printf("%lld\n", indt[1].sum - getsum(lr[it->second][0], lr[it->second][1], 1, IT_MAX, 1));
			}
		}
	}
	return 0;
}
//*/