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

	template<class c, int = 0> typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
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

#define MAXN 100005
const LL MOD = 1000000007;
//const LL MOD = 998244353;

int n, m;
LL w[502][502];

struct Edge {
	int u, v, d;
};
vector<Edge> E;
VP adj[505];
const LL INF = 1000000000000000;

int id;
LL glbl = INF;

void Update(int at, LL now) {
	if (glbl > now) {
		glbl = now;
		id = at;
	}
}

void mdst(int at) {
	VP V;
	int u = E[at].u, v = E[at].v;
	for (int i = 0; i < n; i++) V.push_back({ w[u][i], w[v][i] });
	sort(ALL(V));
	int j = n - 1;
	LL now = 2 * V[j].first;
	Update(at, now);
	for (int i = n - 2; i >= 0; i--) {
		if (V[i].first < V[j].first && V[i].second > V[j].second) {
			now = V[i].first + V[j].second + E[at].d;
			Update(at, now);
			j = i;
		}
	}
	now = V[j].second * 2;
	Update(at, now);
}

struct Node {
	int u; LL d;
};
bool operator < (Node A, Node B) {
	return A.d > B.d;
}

LL dist[505]; int back[505];

VI find() {
	priority_queue<Node> PQ;
	PQ.push({ E[id].u, 0 });
	PQ.push({ E[id].v, 0 });
	FORN(i, n) dist[i] = INF;
	dist[E[id].u] = dist[E[id].v] = 0;
	back[E[id].u] = back[E[id].v] = -1;
	while (!PQ.empty()) {
		Node u = PQ.top();
		PQ.pop();

		for (auto& p : adj[u.u]) {
			LL now = u.d + E[p.second].d;
			if (dist[p.first] > now) {
				dist[p.first] = now;
				back[p.first] = p.second;
				PQ.push({ p.first, now });
			}
		}
	}
	VI V = { id };
	for (int i = 0; i < n; i++) {
		if (dist[i]) {
			V.push_back(back[i]);
		}
	}
	return V;
}

void solve(int ks) {
	scanf("%d %d", &n, &m);
	FORN(i, n) FORN(j, n) w[i][j] = INF;
	FORN(i, n) w[i][i] = 0;
	FORN(u, m) {
		Edge e;
		scanf("%d %d %d", &e.u, &e.v, &e.d);
		e.u--, e.v--;
		E.push_back(e);
		w[e.u][e.v] = w[e.v][e.u] = e.d;
		adj[e.u].push_back({ e.v, u });
		adj[e.v].push_back({ e.u, u });
	}
	FORN(k, n) FORN(i, n) FORN(j, n) {
		w[i][j] = MIN(w[i][j], w[i][k] + w[k][j]);
	}
	FORN(i, m) mdst(i);
	VI V = find();
	printf("%I64d.%d\n", glbl/2, glbl%2 == 0 ? 0 : 5);
//	for (int i : V) printf("%d %d\n", E[i].u + 1, E[i].v + 1);
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