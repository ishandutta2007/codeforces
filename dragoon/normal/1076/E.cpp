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
//typedef __int128 LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

typedef long double ld;

#define MaxVal 600006
LL tree[600005];
//return cf[idx]
LL read(int idx)
{
	idx = MIN(idx, 600002);
	LL sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

//add val to f[idx].
//MaxVal = Just max value of index
void update(int idx, LL val)
{
	//printf(">>%d %lld\n", idx, val);
	idx = MIN(idx, 600002);
	while (idx <= MaxVal)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

VI V[300005];
VP op[300005];
LL ans[300005];

void dfs(int at, int par, int dep) {
	for (auto& p : op[at]) {
		update(dep, p.second);
		update(dep + p.first + 1, -p.second);
	}
	ans[at] = read(dep);
	for (int v : V[at]) {
		if (par == v) continue;
		dfs(v, at, dep + 1);
	}
	for (auto& p : op[at]) {
		update(dep, -p.second);
		update(dep + p.first + 1, p.second);
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	int m; scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int v, d, x;
		scanf("%d %d %d", &v, &d, &x);
		d = MIN(d, 300000);
		op[v].push_back({ d, x });
	}
	dfs(1, 0, 1);
	for (int i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}
#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}