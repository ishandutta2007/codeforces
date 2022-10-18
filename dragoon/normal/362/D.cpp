#pragma warning(disable:4786)
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
#define IN(A, B, C)  (B) <= (A) && (A) <= (C)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
typedef __int64 LL;

struct Node
{
	int node;
	LL cost;
	Node(){}
	Node(int a, LL b) {node = a; cost = b;}
};

bool operator<(Node A, Node B)
{
	return A.cost > B.cost;
}

int vis[100005], id[100005];
vector< PII > V[100005];
priority_queue<Node> Z;

LL dfs(int at)
{
	vis[at] = 1;
	int i, sz = V[at].size();
	LL ret = 0;
	for(i = 0; i < sz; i++)
	{
		ret += V[at][i].second;
		if(vis[V[at][i].first]) continue;
		ret += dfs(V[at][i].first);
	}

	return ret;
}

int main()
{
	int n, m, p, q, u, v;
	LL w;
	int region, i;
	LL ans;

	scanf("%d %d %d %d", &n, &m, &p, &q);
	for(i = 1; i <= m; i++)
	{
		scanf("%d %d %I64d", &u, &v, &w);
		V[u].push_back( PII(v, w) );
		V[v].push_back( PII(u, w) );
	}
/*
	if(m == 0)
	{
		if(q != n || p != 0) printf("NO\n");
		else printf("YES\n");
		return 0;
	}*/

	region = 0;
	for(i = 1; i <= n; i++) if(!vis[i])
	{
		region++;
		id[region] = i;
		Z.push(Node(region, dfs(i)/2));
	}

	if(region < q || (region - q == 0 && p && m == 0)) {printf("NO\n"); return 0;}
	if(region - p > q) {printf("NO\n"); return 0;}
	printf("YES\n");

	Node a, b;
	LL c;
	for(i = 1; i <= region - q; i++)
	{
		a = Z.top(); Z.pop();
		b = Z.top(); Z.pop();
		c = MIN(a.cost + b.cost + 1, 1000000000);

		printf("%d %d\n", id[a.node], id[b.node]);
		u = id[a.node]; v = id[b.node];
		Z.push(Node(a.node, a.cost + b.cost + c));
	}

	for(i = 1; i <= p - (region - q); i++)
		printf("%d %d\n", u, v);








	return 0;
}