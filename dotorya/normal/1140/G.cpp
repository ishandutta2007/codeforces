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

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class Node {
public:
	ll v;
	ll mn;
};
Node indt[1100000];
void propagate(int n) {
	ll v = indt[n].v;
	indt[2 * n].v += v;
	indt[2 * n].mn += v;
	indt[2 * n + 1].v += v;
	indt[2 * n + 1].mn += v;
	indt[n].v = 0;
}

void update(int st, int en, int S, int E, int n, ll v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].v += v;
		indt[n].mn += v;
		return;
	}

	propagate(n);
	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].mn = min(indt[2 * n].mn, indt[2 * n + 1].mn);
}
ll getmn(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return LL_INF;
	if (st <= S && E <= en) return indt[n].mn;

	propagate(n);
	int M = (S + E) / 2;
	return min(getmn(st, en, S, M, 2 * n), getmn(st, en, M + 1, E, 2 * n + 1));
}

vector <pair<pll, int>> conn[300050];
vector <pair<pll, int>> son[300050];
bool dchk[300050];
int lr[300050][2];
int tus;

ll DEP[300050];
void DFS1(int n) {
	dchk[n] = true;
	lr[n][0] = ++tus;
	for (auto it : conn[n]) {
		if (dchk[it.second]) continue;
		DEP[it.second] = DEP[n] + it.first.first + it.first.second;
		son[n].push_back(it);
		DFS1(it.second);
	}
	lr[n][1] = tus;
}

ll val[300050];
void DFS2(int n, int N) {
	val[n] = getmn(1, N, 1, IT_MAX, 1);
	for (auto it : son[n]) {
		int nn = it.second;
		ll v = it.first.first + it.first.second;

		update(1, N, 1, IT_MAX, 1, v);
		update(lr[nn][0], lr[nn][1], 1, IT_MAX, 1, -2 * v);
		DFS2(it.second, N);

		update(1, N, 1, IT_MAX, 1, -v);
		update(lr[nn][0], lr[nn][1], 1, IT_MAX, 1, 2 * v);
	}
}

int dep[300050];
int par[300050][20];
ll dp[300050][20][2][2];
void DFS3(int n) {
	for (auto it : son[n]) {
		int nn = it.second;
		ll v[2] = { it.first.first, it.first.second };
		par[nn][0] = n;
		dp[nn][0][0][0] = min(v[0], val[n] + v[1] + val[nn]);
		dp[nn][0][0][1] = min(v[0] + val[n], val[nn] + v[1]);
		dp[nn][0][1][0] = min(v[1] + val[n], val[nn] + v[0]);
		dp[nn][0][1][1] = min(v[0] + val[n] + val[nn], v[1]);

		dep[nn] = dep[n] + 1;
		for (int i = 1; i < 20; i++) {
			int p = par[nn][i - 1];
			par[nn][i] = par[p][i - 1];
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					dp[nn][i][j][k] = LL_INF;
					for (int l = 0; l < 2; l++) dp[nn][i][j][k] = min(dp[nn][i - 1][j][l] + dp[p][i - 1][l][k], dp[nn][i][j][k]);
				}
			}
		}
		DFS3(nn);
	}
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

pll getdp(int nn, int sp, int n) {
	pll u = pll(0, val[nn]);
	if (sp == 1) u = pll(val[nn], 0);

	int c = dep[nn] - dep[n];
	for (int i = 19; i >= 0; i--) {
		if (c & (1 << i)) {
			pll u2 = pll(LL_INF, LL_INF);
			u2.first = min(u.first + dp[nn][i][0][0], u.second + dp[nn][i][1][0]);
			u2.second = min(u.first + dp[nn][i][0][1], u.second + dp[nn][i][1][1]);

			nn = par[nn][i];
			u2.first = min(u2.first, u2.second + val[nn]);
			u2.second = min(u2.second, u2.first + val[nn]);
			u = u2;
		}
	}
	return u;
}
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		ll t;
		scanf("%lld", &t);
		val[i] = t;
	}

	for (i = 1; i < N; i++) {
		ll t1, t2, t3, t4;
		scanf("%lld %lld %lld %lld", &t1, &t2, &t3, &t4);
		conn[t1].emplace_back(pll(t3, t4), t2);
		conn[t2].emplace_back(pll(t3, t4), t1);
	}
	DFS1(1);

	for (i = 1; i <= N; i++) update(lr[i][0], lr[i][0], 1, IT_MAX, 1, val[i] + DEP[i]);
	DFS2(1, N);

	for (int i = 0; i < 20; i++) {
		par[1][i] = 1;
		dp[1][i][0][0] = dp[1][i][1][1] = 0;
		dp[1][i][0][1] = dp[1][i][1][0] = val[1];
	}
	DFS3(1);
	 
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);

		int n1, s1, n2, s2;
		n1 = (t1 + 1) / 2;
		s1 = 1 - t1 % 2;
		n2 = (t2 + 1) / 2;
		s2 = 1 - t2 % 2;

		int p = lca(n1, n2);

		pll u1 = getdp(n1, s1, p);
		pll u2 = getdp(n2, s2, p);
		
		ll ans = LL_INF;
		ans = min(ans, u1.first + u2.first);
		ans = min(ans, u1.second + u2.second);
		ans = min(ans, u1.first + u2.second + val[p]);
		ans = min(ans, u2.first + u1.second + val[p]);
		printf("%lld\n", ans);
	}
	return 0;
}