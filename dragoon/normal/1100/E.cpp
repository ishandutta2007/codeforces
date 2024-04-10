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
//typedef __int128 LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;
typedef long double ld;

int n, m;
struct Edge {
	int u, v, d;
	int id;
};
bool operator<(Edge A, Edge B) {
	return A.d < B.d;
}

VI adj[100005];
vector<Edge> E;
int in[100005];
int id[100005];

int possible(int lim, int Z = 0) {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		in[i] = 0;
	}
	for (int i = m - 1; i >= 0; i--) {
		if (E[i].d < lim) break;
		adj[E[i].u].push_back(E[i].v);
		in[E[i].v]++;
	}
	int z = 0;
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		id[u] = ++z;
		for (int v : adj[u]) {
			in[v]--;
			if (in[v] == 0) {
				Q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (in[i]) {
			return 0;
		}
	}
	if (Z) {
		VI ANS;
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if (E[i].d < lim) {
				ans = E[i].d;
				if (id[E[i].u] > id[E[i].v]) ANS.push_back(E[i].id);

			}
		}
		printf("%d %d\n", ans, SZ(ANS));
		for (int i : ANS) printf("%d ", i);
		printf("\n");

	}
	return 1;
}

void solve(int ks) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		Edge e;
		scanf("%d %d %d", &e.u, &e.v, &e.d);
		e.id = i;
		E.push_back(e);
	}

	sort(ALL(E));
	int lo = E[0].d, hi = E[m - 1].d + 1;
	while (lo < hi) {
		int m = (lo + hi) / 2;
		if (possible(m)) {
			hi = m;
		}
		else {
			lo = m + 1;
		}
	}
	possible(lo, 1);
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
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}