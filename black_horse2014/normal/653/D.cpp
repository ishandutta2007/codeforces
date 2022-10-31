#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define counti(x) (__builtin_popcount(x))
#define clz(x) (__builtin_clz(x))
#define ctz(x) (__builtin_ctz(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define Error(x) cout << #x << " = " << x << endl
#define X first
#define Y second

template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

namespace Dinic {
#define INF (2e9+105)
typedef int F;
#define F_INF (~0u>>1)
#define MAXV 77
#define MAXE 4444 // E*2!
int cap[MAXE];
int to[MAXE], used[MAXV], level[MAXV];
int fst[MAXV], nxt[MAXE];
int V, E;
int Q[MAXV];

void init(int n) {
	V = n;
	E = 0;
	for (int i = 0; i < V; ++i) fst[i] = -1;	
}

void add(int x, int y, F f){
	cap[E] = f; to[E] = y; 
  nxt[E] = fst[x]; fst[x] = E++;
	cap[E] = 0; to[E] = x;
	nxt[E] = fst[y]; fst[y] = E++;
}

bool bfs(int s, int t){
	for (int i = 0; i < V; i++) level[i] = -1;
	int hd = 0, tl = 0;
	Q[tl++] = s; level[s] = 0;
	while (hd < tl){
		int x = Q[hd++];
		for (int e = fst[x]; ~e; e = nxt[e]) {
			if (level[to[e]] == -1 && cap[e]) {
        Q[tl++] = to[e]; level[to[e]] = level[x] + 1;
        if (to[e] == t) return 1;
      }
		}
	}
	return (level[t] != -1);
}

F dfs(int v, int t, F f){
	if(v == t) return f;
	for (int &e = used[v]; ~e; e = nxt[e]){
		if (level[to[e]] > level[v] && cap[e]){
			F tmp = dfs(to[e], t, min(f, cap[e]));
			if (tmp > 0) {cap[e] -= tmp; cap[e^1] += tmp; return tmp;}
		}
	}
	return 0;
}

F maxflow(int s, int t){
  F delta;
  LL ret = 0;
	while (bfs(s, t)){
		for (int i = 0; i < V; i++) used[i] = fst[i];
		while(delta = dfs(s, t, F_INF)) ret += delta;
	}
	return ret;
}
};
int n, m, x;
int a[MAXE], b[MAXE], c[MAXE];
bool can(double mid) {
	Dinic::init(n);
	for (int i = 0; i < m; i++) {
		Dinic::add(a[i] - 1, b[i] - 1, min(LL(c[i] / mid), LL(x) + 5));
	}
	return Dinic::maxflow(0, n - 1) >= x;
}
int main() {
	
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", a + i, b + i, c + i);
	}
	double st = 0.0, en = 1e7 + 5;
	for (int it = 0; it < 100; it++) {
		double mid = 0.5 * (st + en);
		if (can(mid)) st = mid;
		else en = mid;
	}
	printf("%.10lf\n", st * x);
	return 0;
}