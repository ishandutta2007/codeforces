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
#include <array>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
	~debug() { cerr << endl; }
	template<class c> typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
		cerr << boolalpha << i; return *this;
	}

	template<class c, int=0> typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
		return *this << range(begin(i), end(i));
	}

sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
	sim dor(const c&) { ris; }
#endif
};
#define watch(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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
typedef long long LLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PLL > VPL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef long double ld;

const LL MOD = 998244353;

#define NUM_EDGE 400005
#define NUM_VERTEX 200005

struct EDGE {
	int from, to, next;
};

int n;
EDGE edge[2 * NUM_EDGE];
int nedge, nextEdge[NUM_VERTEX];

int bridge[2 * NUM_EDGE];
int start[NUM_VERTEX], low[NUM_VERTEX], vis_time;
int color[NUM_VERTEX][2];

void add_edge(int u, int v) {
	nedge++;
	edge[nedge].from = u;
	edge[nedge].to = v;
	edge[nedge].next = nextEdge[u];
	nextEdge[u] = nedge;
	//printf("%d %d\n", u, v);
	bridge[nedge] = 0;
}

void dfs(int at, int parent)
{
	int i, u;

	low[at] = start[at] = ++vis_time;
	for (i = nextEdge[at]; i != -1; i = edge[i].next)
	{
		u = edge[i].to;

		if (parent == u) continue;

		if (start[u])
		{
			low[at] = MIN(low[at], start[u]);
		}
		else
		{
			dfs(u, at);
			low[at] = MIN(low[at], low[u]);
			if (low[u] > start[at])
				bridge[i] = bridge[i ^ 1] = 1;
		}
	}
}

int comp[NUM_VERTEX];
void visit(int at, int mark)
{
	queue<int> Q;
	int u, i;

	comp[at] = mark;
	Q.push(at);
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();

		for (i = nextEdge[u]; i != -1; i = edge[i].next)
		{
			if (bridge[i]) continue;

			u = edge[i].to;
			if (comp[u]) continue;
			comp[u] = mark;
			Q.push(u);
		}
	}
}

void init() {
	nedge = -1;
	for (int i = 0; i <= n; i++)
	{
		nextEdge[i] = -1;
		start[i] = 0;
		comp[i] = 0;
	}
}

int ncomp;
void bcc() {
	vis_time = 0;
	dfs(0, -1);

	ncomp = 0;
	for (int i = 0; i<n; i++)
		if (!comp[i])
		{
			ncomp++;
			visit(i, ncomp);
		}
}

int m, w[200005];
LL sumW[200005];
VI V[200005];
LL ret[200005], endss[200005];
int cntNode[200005];

int solveDp(int at, int par) {
	int can_i_return = 0;
	if (cntNode[at] > 1) can_i_return = 1;

	ret[at] = sumW[at];
	LL mx = 0;
	for (int u : V[at]) {
		if (u == par) continue;
		if (solveDp(u, at)) can_i_return = 1;
		ret[at] += ret[u];
		mx = MAX(mx, endss[u] - ret[u]);
	}
	endss[at] = ret[at] + mx;
	if (cntNode[at] == 1 && can_i_return == 0) ret[at] = 0;
	return can_i_return;
}

void solve(int ks) {
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		add_edge(u, v);
		add_edge(v, u);
	}

	bcc();
	FORN(i, n) {
		sumW[comp[i]] += w[i];
		cntNode[comp[i]]++;
	}
	for (int i = 1; i <= nedge; i++) {
		if (bridge[i]) {
			V[comp[edge[i].from]].push_back(comp[edge[i].to]);
		}
	}
	FORN(i, n) {
	//	fprintf(stderr, "%d ", comp[i]);
	}
	int q;
	scanf("%d", &q);
	q = comp[q - 1];

	solveDp(q, -1);
	printf("%I64d\n", MAX(ret[q], endss[q]));
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
		//AIN(T, 1, 25);
		for (int ks = 1; ks <= T; ks++) {
			solve(ks);
			fprintf(stderr, "%d done\n", ks);
		}
	}
	else {
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}