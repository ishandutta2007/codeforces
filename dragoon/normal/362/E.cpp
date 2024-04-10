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
//typedef __int64 LL;

struct Node
{
	int u, cost;
	Node(){}
	Node(int a, int b){u = a; cost = b;}
};

bool operator<(Node A, Node B)
{
	return A.cost > B.cost;
}

struct EDGE
{
	int u, cf, id, ini;

	EDGE(int a, int b, int d)
	{
		u=a;
		cf=b;
		id=d;
		ini = cf;
	}

	EDGE()
	{
	}
};

#define SIZE 205

struct Max_Flow
{
	int vis[SIZE], p[SIZE], id[SIZE];
	int source, sink;
	int n;

	vector<EDGE> V[SIZE];

	void add_edge(int a, int b, int cf)
	{
		int sz1 = V[a].size();
		int sz2 = V[b].size();

		V[a].push_back(EDGE(b, cf, sz2));
		V[b].push_back(EDGE(a, 0, sz1));
	}


	int augment()
	{
		queue<int> Q;
		int X;
		int sz, j, a, b, now, i;

		for(i = 0; i <= n; i++) p[i] = -1, vis[i] = 0;

		Q.push(source);
		p[source] = -1;
		vis[source] = 1;

		while(!Q.empty())
		{
			X = Q.front();
			Q.pop();

			sz=V[X].size();
			for(j=0;j<sz;j++)
				if(V[X][j].cf>0)
				{
					if(!vis[V[X][j].u])
					{
						vis[ V[X][j].u ] = 1;
						p[ V[X][j].u ] = X;
						id[ V[X][j].u ] = j;
						Q.push( V[X][j].u );
					}
				}
		}

		if(p[sink]==-1) return 0;

		int flow = 1000000000;
		now = sink;

		while(p[now]!=-1)
		{
			a = p[now];
			b = now;

			flow = MIN(flow, V[a][ id[b] ].cf);

			now = p[now];
		}

		now = sink;
		while(p[now]!=-1)
		{
			a = p[now];
			b = now;

			V[a][ id[b] ].cf -= flow;
			V[b][ V[a][id[b]].id ].cf += flow;

			now = p[now];
		}

		return flow;
	}

	//returns total cost, flow is not counted here.
	int total_flow;

	int flow()
	{
		int temp;

		total_flow = 0;

		while( temp = augment() )
		{
			total_flow+=temp;
		}

		return total_flow;
	}

	void clear()
	{
		for(int i = 0; i < SIZE; i++)
			V[i].clear();
	}

	void set(int a, int b)
	{
		source = a;
		sink = b;
	}

	void setN(int a)
	{
		n = a;
	}
};

/*
Max_Flow A;
A.setN(n);
A.set(source, sink);
A.add_edge(s, t, cap);
A.clear();
A.flow();
A.total_flow;
*/

Max_Flow A;
priority_queue<Node> Q;
int back[55], dist[55];

int main()
{
	int n, k;
	int i, j, a;
	int ans;
	Node X;
	int d, u, sz;
	int v, dd, id;

	scanf("%d %d", &n, &k);
	A.setN(n);
	A.set(1, n);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &a);
			if(a) A.add_edge(i, j, a);
		}

	ans = A.flow();
	while(k)
	{
		for(i = 1; i <= n; i++) dist[i] = 1000000;

		while(!Q.empty()) Q.pop();
		MEM(back, -1);
		Q.push(Node(1, 0));
		dist[1] = 0;
		while(!Q.empty())
		{
			X = Q.top();
			Q.pop();

			u = X.u;
			d = X.cost;

			sz = A.V[u].size();
			for(i = 0; i < sz; i++)
			{
				v = A.V[u][i].u;


				if(!A.V[u][i].cf)
				{
					if(A.V[u][i].ini == 0) continue;
					dd = d + 1;
				}
				else
				{
					dd = d;
				}

				if(dist[v] > dd)
				{
					dist[v] = dd;
					Q.push( Node(v, dd) );
					back[v] = A.V[u][i].id;
				}
			}
		}


		if(dist[n] > k) break;
		k -= dist[n];
		ans++;
		v = n;
		while(v != 1)
		{
			u = A.V[v][back[v]].u;
			id = A.V[v][back[v]].id;

			if(!A.V[u][id].cf)
			{
				A.V[v][back[v]].cf++;
			}
			else
			{
				A.V[u][id].cf--;
				A.V[v][back[v]].cf++;
			}

			v = u;
		}
	}

	printf("%d\n", ans);



	return 0;
}