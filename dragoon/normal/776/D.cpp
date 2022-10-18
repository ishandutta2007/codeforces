#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
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
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int n, m;
VI A[100005];
int r[100005];

///////////////
bool used[200005];
vector<int> order, component;
vector<int> V[200004];

void dfs1(int v) {
	int i;

	used[v] = true;
	for (i = 0; i<V[v].size(); ++i)
		if (!used[V[v][i]])
			dfs1(V[v][i]);
	order.push_back(v);
}

void dfs2(int v) {
	int i;

	used[v] = true;
	component.push_back(v);
	for (i = 0; i<V[v].size(); ++i)
		if (!used[V[v][i]])
			dfs2(V[v][i]);
}

int mark[200005];

int scc()
{
	int v, i;

	for (int i = 0; i < n; i++) {
		int u = A[i][0];
		int v = A[i][1];

		if (!r[i]) {
			V[2 * u].push_back(2 * v + 1);
			V[2 * v + 1].push_back(2 * u);
			V[2 * v].push_back(2 * u + 1);
			V[2 * u + 1].push_back(2 * v);
		}
		else {
			V[2 * u].push_back(2 * v);
			V[2 * v].push_back(2 * u);
			V[2 * u + 1].push_back(2 * v + 1);
			V[2 * v + 1].push_back(2 * u + 1);
		}
	}

	for (int i = 0; i < 2 * m; i++) used[i] = false;

	for (i = 0; i< 2 * m; ++i)
		if (!used[i])
			dfs1(i);

	for (i = 0; i< 2 * m; i++)
		used[i] = false;

	vector<VI> cs;
	for (i = 0; i<2 *  m; ++i) {
		v = order[2 * m - 1 - i];
		if (!used[v]) {
			dfs2(v);
			cs.push_back(component);
			component.clear();
		}
	}
	int marker = 0;
	for (const VI& V : cs) {
		marker++;
		for (int v : V) mark[v] = marker;
	}

	for (int i = 0; i < m; i++)
		if (mark[2 * i] == mark[2 * i + 1])
			return 0;
	return 1;
}
//////////////

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &r[i]);
	for (int i = 1; i <= m; i++) {
		int k, l;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d", &l);
			A[l - 1].push_back(i - 1);
		}
	}
	if (scc()) printf("YES\n");
	else printf("NO\n");

	return 0;
}