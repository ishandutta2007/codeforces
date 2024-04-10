//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int128 LLL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef long double ld;

struct Q {
	int l, r, id;
};
//#define MAXN 100
#define MAXN 500005

int n, q;
VP adj[MAXN];
vector<Q> qs[MAXN];
LL ans[MAXN];
LL dist[MAXN];
PII my_childs[MAXN];

void dfs(int at, LL cost) {
	dist[at] = cost;
	my_childs[at] = { 1000000, -1 };
	if (adj[at].empty()) {
		my_childs[at] = { at, at };
	}
	for (auto& v : adj[at]) {
		dfs(v.first, cost + v.second);
		my_childs[at].first = MIN(my_childs[at].first, my_childs[v.first].first);
		my_childs[at].second = MAX(my_childs[at].second, my_childs[v.first].second);
	}
}

LL tree[4 * 500005];
VI leaves;
VL init;
LL lazy[4 * 500005];

void build(int at, int l, int r) {
	if (l == r) {
		tree[at] = init[l];
		lazy[at] = 0;
		return;
	}
	lazy[at] = 0;
	int m = (l + r) / 2;
	build(at * 2, l, m);
	build(at * 2 + 1, m + 1, r);
	tree[at] = MIN(tree[at * 2], tree[at * 2 + 1]);
}

LL Query(int at, int l, int r, int L, int R) {
	if (r < l || R < leaves[l] || L > leaves[r]) return 100000000000000000LL;
	if (L <= leaves[l] && leaves[r] <= R) {
		return tree[at];
	}
	int m = (l + r) / 2;
	LL a = Query(at * 2, l, m, L, R);
	LL b = Query(at * 2 + 1, m + 1, r, L, R);
	return MIN(a, b) + lazy[at];
}

void Update(int at, int l, int r, int L, int R, LL v) {
	if (r < l || R < leaves[l] || L > leaves[r]) return;
	if (L <= leaves[l] && leaves[r] <= R) {
		lazy[at] += v;
		tree[at] += v;
		return;
	}
	int m = (l + r) / 2;
	Update(at * 2, l, m, L, R, v);
	Update(at * 2 + 1, m + 1, r, L, R, v);
	LL now = MIN(tree[at * 2], tree[at * 2 + 1]) + lazy[at];
	tree[at] = now;
}

void Solve(int at) {
	for (auto& qq : qs[at]) {
		ans[qq.id] = Query(1, 0, SZ(leaves) - 1, qq.l, qq.r);
	}
	for (auto& v : adj[at]) {
		Update(1, 0, SZ(leaves) - 1, leaves[0], leaves[SZ(leaves) - 1], v.second);
		Update(1, 0, SZ(leaves) - 1, my_childs[v.first].first, my_childs[v.first].second, -v.second * 2);
		Solve(v.first);
		Update(1, 0, SZ(leaves) - 1, my_childs[v.first].first, my_childs[v.first].second, v.second * 2);
		Update(1, 0, SZ(leaves) - 1, leaves[0], leaves[SZ(leaves) - 1], -v.second);
	}
}

void solve(int ks) {
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int p, w;
		scanf("%d %d", &p, &w);
		adj[p].push_back({ i, w });
	}
	for (int i = 1; i <= q; i++) {
		Q qq; int v;
		scanf("%d %d %d", &v, &qq.l, &qq.r);
		qs[v].push_back({ qq.l, qq.r, i });
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		if (SZ(adj[i]) == 0) {
			leaves.push_back(i);
			init.push_back(dist[i]);
		}
	}
	build(1, 0, SZ(leaves) - 1);
	Solve(1);

	for (int i = 1; i <= q; i++) {
		printf("%lld\n", ans[i]);
	}
}

int main()
{
#ifdef LOCAL
	double start_time = clock();
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	if (0) {
		int T;
		scanf("%d", &T);
		for (int ks = 1; ks <= T; ks++) solve(ks);
	}
	else {
		/*
		n = 30, m = 1000;
		for (int i = 1; i <= n/3; i++) {
			int x = rand() % 7 + 1;
			if (rand() % 2) cnt[x]+=3;
			else cnt[x]++, cnt[x + 1]++, cnt[x + 2]++;
		}
		cnt[1] = 0;
		*/
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}