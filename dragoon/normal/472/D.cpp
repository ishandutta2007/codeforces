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

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;
typedef vector<pair<int, LL > > VP;

int n;
int w[2003][2003];
int Y[2003], Z[2003], V[2003];
LL W[2003][2003];

VP tree[2003];

void addEdge(int u, int v, int c)
{
	tree[u].push_back(PII(v, c));
	tree[v].push_back(PII(u, c));
}

void reconstruct()
{
	for(int i = 0; i < n; i++)
	{
		queue<int> Q;
		int vis[2003]; CLR(vis);
		Q.push(i);
		vis[i] = 1;
		W[i][i] = 0;
		while(!Q.empty())
		{
			int u = Q.front(); Q.pop();
			for(int j = 0; j < tree[u].size(); j++)
			{
				int v = tree[u][j].first;
				if(vis[v]) continue;
				vis[v] = 1;
				Q.push(v);
				W[i][v] = W[i][u] + tree[u][j].second;
			}
		}
	}

}

int checkP(int p, int q, int parent)
{
	if(q < p) return 1;

	int child = -1, cost = 2000000000;
	for(int i = p; i <= q; i++)
	{
		int x = V[i];
		if(cost > w[parent][x])
		{
			cost = w[parent][x];
			child = x;
		}
	}

	addEdge(parent, child, w[parent][child]);

	int a = 0, b = 0;
	for(int i = p; i <= q; i++)
	{
		int x = V[i];
		if(x == child) continue;
		if(w[child][x] == w[parent][x] - w[parent][child]) Y[a++] = x;
		else if(w[parent][x] == w[child][x] - w[parent][child]) Z[b++] = x;
		else return 0;
	}

	int c = p;
	for(int i = 0; i < a; i++)
		V[c++] = Y[i];
	for(int i = 0; i < b; i++)
		V[c++] = Z[i];
	if(!checkP(p, p + a - 1, child)) return 0;
	if(!checkP(p + a, c - 1, parent)) return 0;
	return 1;
}

int solve()
{
	int i, j;
	int ans = 2000000000;
	int ni, nj;

	FORN(i, n) FORN(j, n) if(w[i][j] != w[j][i] || (i != j && w[i][j] == 0) || (i == j && w[i][j] != 0)) return 0;

	if(n == 1) return 1;

	FORN(i, n) FORN(j, n) if(i != j)
		if(ans > w[i][j])
		{
			ans = w[i][j];
			ni = i;
			nj = j;
		}

	int szV = 0;
	for(i = 0; i < n; i++) if(i != ni && i != nj)
		V[szV++] = i;

	int szY = 0, szZ = 0;
	for(i = 0; i < szV; i++)
	{
		int x = V[i];
		if(w[ni][x] == w[nj][x] - w[ni][nj]) Y[szY++] = x;
		else if(w[nj][x] == w[ni][x] - w[ni][nj]) Z[szZ++] = x;
		else return 0;
	}

	addEdge(ni, nj, w[ni][nj]);
	szV = 0;
	for(i = 0; i < szY; i++)
	{
		V[szV++] = Y[i];
	}
	for(i = 0; i < szZ; i++)
	{
		V[szV++] = Z[i];
	}

	if(!checkP(0, szY - 1, ni)) return 0;
	if(!checkP(szY, szY + szZ - 1, nj)) return 0;

	reconstruct();

	FORN(i, n) FORN(j, n) if(w[i][j] != W[i][j]) return 0;
	return 1;
}

int main()
{
	int i, j;

	scanf("%d", &n);
	FORN(i, n) FORN(j, n) scanf("%d", &w[i][j]);
	//FORN(i, n) FORN(j, n) w[i][j] = ABS(i - j);
	if(solve()) printf("YES\n");
	else printf("NO\n");

	return 0;
}