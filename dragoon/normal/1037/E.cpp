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
//typedef __int64 LL;

typedef pair<int,int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

set<int> adj[200005];
PII ed[200005];
int n, m, k;

int in[200005], fr[200005];
int ans[200005];
int total;

void init() {
	for (int i = 1; i <= n; i++) in[i] = 1;
	for (int i = 1; i <= n; i++) {
		fr[i] = adj[i].size();
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (fr[i] < k) {
			in[i] = 0;
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i : adj[u]) {
			fr[i]--;
			if (fr[i] == k - 1 && in[i]) {
				in[i] = 0;
				Q.push(i);
			}
		}
	}
}

queue<int> Q;
void process() {
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i : adj[u]) {
			fr[i]--;
			if (fr[i] == k - 1 && in[i]) {
				in[i] = 0;
				total--;
				Q.push(i);
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		ed[i] = { u, v };
		adj[u].insert(v);
		adj[v].insert(u);
	}

	init();
	ans[m] = 0;
	for (int i = 1; i <= n; i++) ans[m] += in[i];
	total = ans[m];

	for (int i = m; i > 1; i--) {
		int u = ed[i].first;
		int v = ed[i].second;
		adj[u].erase(v);
		adj[v].erase(u);

		if (in[v]) fr[u]--;
		if (in[u]) fr[v]--;
		int z = 0; if (in[u] && in[v]) z = 1;
		if (fr[u] == k - 1 && z) {
			in[u] = 0;
			total--;
			Q.push(u);
		}
		if (fr[v] == k - 1 && z) {
			in[v] = 0;
			total--;
			Q.push(v);
		}
		process();
		ans[i - 1] = total;
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}