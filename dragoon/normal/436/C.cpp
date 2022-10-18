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
//typedef long long int LL;
//typedef __int64 LL;

struct Edge
{
	int u, v, d;
	Edge() {}
	Edge(int _u, int _v, int _d)
	{
		u = _u, v = _v, d = _d;
	}
};

bool operator < (Edge A, Edge B)
{
	return A.d < B.d;
}

int n, m, k, w;
char field[1001][12][12];
int d[1002][1002];
vector<Edge> E;
int p[1002];

int Parent(int a)
{
	if(p[a] == a) return a;
	return p[a] = Parent(p[a]);
}

void merge(int a, int b)
{
	a = Parent(a);
	b = Parent(b);
	p[p[a]] = p[b];
}

VI V[1002];

void DFS(int at, int par)
{
	if(par == -1)
		printf("%d %d\n", at + 1, 0);
	else
		printf("%d %d\n", at + 1, par + 1);

	int sz = SZ(V[at]);
	for(int i = 0; i < sz; i++)
	{
		if(par == V[at][i]) continue;
		DFS(V[at][i], at);
	}
}

int main()
{
	int i, j, a, b;
	int u, v, d;
	
	scanf("%d %d %d %d", &n, &m, &k, &w);
	for(i = 0; i < k; i++)
	{
		for(j = 0; j < n; j++) scanf("%s", field[i][j]);
	}

	for(i = 0; i < k; i++)
	{
		for(j = i + 1; j < k; j++)
		{
			d = 0;
			for(a = 0; a < n; a++)
				for(b = 0; b < m; b++)
					d += (field[j][a][b] != field[i][a][b]);
			d *= w;

			E.push_back(Edge(i, j, d));
		}
	}

	sort(ALL(E));

	for(i = 0; i < k; i++) p[i] = i;
	int sz = SZ(E);
	int cost = n * m * k;

	for(i = 0; i < sz; i++)
	{
		u = E[i].u;
		v = E[i].v;
		d = E[i].d;

		if(Parent(u) == Parent(v)) continue;
		if(d >= n * m) break;

		cost = cost - n * m + d;
		merge(u, v);
		V[u].push_back(v);
		V[v].push_back(u);
	}

	printf("%d\n", cost);
	for(i = 0; i < k; i++) if(p[i] == i) DFS(i, -1);

	return 0;
}