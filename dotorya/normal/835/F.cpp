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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

class segtree {
public:
	ll* indt;
	segtree() {
		indt = new ll[600000];
		memset(indt, 0, sizeof(indt));
	}
	void update(int p, ll v) {
		p += IT_MAX - 1;
		indt[p] = v;
		for (p /= 2; p; p /= 2) indt[p] = max(indt[2 * p], indt[2 * p + 1]);
	}
	ll getmx(int p1, int p2) {
		p1 += IT_MAX - 1;
		p2 += IT_MAX - 1;
		ll rv = -LL_INF;
		for (; p1 <= p2; p1 /= 2, p2 /= 2) {
			if (p1 % 2 == 1) rv = max(rv, indt[p1++]);
			if (p2 % 2 == 0) rv = max(rv, indt[p2--]);
		}
		return rv;
	}
};

ll A, B, D;
vector <pll> conn[200050];
vector <ll> Vu[200050];
int lr[200050][2];
int tus;
int par[200050];
ll dis[200050];
ll dp[200050];
ll dp2[200050];
bool dchk[200050];
void DFS(int n) {
	lr[n][0] = ++tus;
	dchk[n] = true;
	for (auto it : conn[n]) {
		ll d = dis[n] + it.first, x = it.second;
		if (par[n] == x) continue;
		if (dchk[x]) {
			A = n, B = x, D = it.first;
			continue;
		}
		dis[x] = d;
		par[x] = n;
		DFS(x);
		dp[n] = max(dp[n], dp[x]);
		dp2[n] = max(dp2[n], dp2[x] + it.first);
		Vu[n].push_back(dp2[x] + it.first);
	}
	dp[n] = max(dp[n], dp2[n]);
	sort(all(Vu[n]));
	if (Vu[n].size() >= 2) dp[n] = max(dp[n], Vu[n][Vu[n].size() - 1] + Vu[n][Vu[n].size() - 2]);
	lr[n][1] = tus;
}
void init(int N) {
	for (int i = 1; i <= N; i++) Vu[i].clear();
	memset(lr, 0, sizeof(lr));
	tus = 0;
	memset(par, 0, sizeof(par));
	memset(dis, 0, sizeof(dis));
	memset(dp, 0, sizeof(dp));
	memset(dp2, 0, sizeof(dp2));
	memset(dchk, false, sizeof(dchk));
}

ll val[2][200050];
ll valD[2][200050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		conn[t1].emplace_back(t3, t2);
		conn[t2].emplace_back(t3, t1);
	}
	DFS(1);

	for (i = 0; i < conn[A].size(); i++) if (conn[A][i].second == B) swap(conn[A][i], conn[A].back());
	conn[A].pop_back();
	for (i = 0; i < conn[B].size(); i++) if (conn[B][i].second == A) swap(conn[B][i], conn[B].back());
	conn[B].pop_back();

	init(N);
	DFS(B);
	for (i = 1; i <= N; i++) val[1][i] = dp[i], valD[1][i] = dis[i];

	init(N);
	DFS(A);
	for (i = 1; i <= N; i++) val[0][i] = dp[i], valD[0][i] = dis[i];

	segtree seg[2];
	seg[0] = segtree(), seg[1] = segtree();
	for (i = 0; i < 2; i++) for (j = 1; j <= N; j++) seg[i].update(lr[j][0], valD[i][j]);

	ll ans = dp[A];
	vector <int> Vq;
	int tu = B;
	Vq.push_back(B);
	while (tu != A) {
		tu = par[tu];
		Vq.push_back(tu);
	}
	for (i = 0; i + 1 < Vq.size(); i++) {
		int n1 = Vq[i + 1], n2 = Vq[i];
		ll v = max(val[1][n1], val[0][n2]);
		
		ll d1 = seg[1].getmx(lr[n2][0], lr[n2][1]);
		ll d2 = max(seg[0].getmx(1, lr[n2][0] - 1), seg[0].getmx(lr[n2][1] + 1, N));
		v = max(v, d1 + d2 + D);
		ans = min(ans, v);
	}
	return !printf("%lld\n", ans);
}