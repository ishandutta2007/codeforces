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
#define SIZE(V) (int )V.size()
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

/**********************************/
#define SZ 50004

struct NODE
{
	int u, cost;
	NODE(int a, int b) { u = a; cost = b; }
	NODE(){}

};

bool operator<(NODE A, NODE B)
{
	if (A.cost > B.cost) return 1;
	return 0;
}

struct EDGE
{
	int u, cf, cost, id, ini;

	EDGE(int a, int b, int c, int d)
	{
		u = a; cf = b; cost = c; id = d; ini = cf;
	}

	EDGE() {}
};

struct Min_Cost_Flow
{
	int d[SZ], p[SZ], id[SZ];
	int source, sink;


	vector<EDGE> V[SZ];
	int maxNode = 0;

	void add_edge(int a, int b, int cost, int cf)
	{
//		printf(">>>%d %d %d %d\n", a, b, cost, cf);
		int sz1 = V[a].size();
		int sz2 = V[b].size();

		V[a].push_back(EDGE(b, cf, cost, sz2));
		V[b].push_back(EDGE(a, 0, -cost, sz1));
		maxNode = MAX(maxNode, a);
		maxNode = MAX(maxNode, b);
	}


	PII augment()
	{
		priority_queue<NODE> Q;
		NODE X;
		int sz, j, a, b, now, i, flag, k;

		for (i = 0; i <= maxNode; i++) p[i] = -1, d[i] = 10000000;

		d[source] = 0;
		p[source] = -1;

		for (i = 0; i<maxNode; i++)
		{
			flag = 0;

			for (j = 0; j <= maxNode; j++)
			{
				sz = V[j].size();
				for (k = 0; k<sz; k++) if (V[j][k].cf > 0)
				{
					if (d[V[j][k].u] > d[j] + V[j][k].cost)
					{
						d[V[j][k].u] = d[j] + V[j][k].cost;
						p[V[j][k].u] = j;
						id[V[j][k].u] = k;
						flag = 1;
					}
				}
			}

			if (flag == 0)
				break;
		}

		if (p[sink] == -1) return PII(0, 0);

		int ans = d[sink], flow = 1000000000;
		now = sink;

		while (p[now] != -1)
		{
			a = p[now];
			b = now;

			flow = MIN(flow, V[a][id[b]].cf);

			now = p[now];
		}

		now = sink;
		//printf("---\n");
		while (p[now] != -1)
		{
			//printf(">>%d\n", now);
			a = p[now];
			b = now;

			V[a][id[b]].cf -= flow;
			V[b][V[a][id[b]].id].cf += flow;

			now = p[now];
		}
		
		return PII(flow, ans*flow);

	}

	//returns total cost, flow is not counted here.
	int total_flow, total_cost;

	void flow()
	{
		PII temp;

		total_cost = total_flow = 0;

		while ((temp = augment()).first)
		{
			total_cost += temp.second;
			total_flow += temp.first;
		}

	}

	void clear()
	{
		for (int i = 0; i<SZ; i++)
			V[i].clear();
	}

	void set(int a, int b)
	{
		source = a;
		sink = b;
	}
};

/*
Min_Cost_Flow A;
A.set(source, sink);
A.add_edge(s, t, cost, cap);
A.clear();
A.flow();
A.total_cost;
A.total_flow;
*/
/**********************************/

Min_Cost_Flow A;

int n;
char S[505];
int m;
int SOURCE, SINK;
int point;
char P[505];

int pre[505];
int Z;

void check() {
	pre[0] = -1;
	int now = -1;
	int lenP = strlen(P), lenS = strlen(S);
	for (int i = 1; i < lenP; i++) {
		while (now != -1 && P[i] != P[now + 1])
			now = pre[now];
		if (P[i] == P[now + 1]) now = pre[i] = now + 1;
		else now = pre[i] = -1;
	}

	now = -1;
	for (int i = 0; i < lenS; i++) {
		while (now != -1 && S[i] != P[now + 1])
			now = pre[now];
		if (S[i] == P[now + 1]) now++;
		else now = -1;

		if (now == lenP - 1) {
			// match: S[now - lenS + 1, now]
			A.add_edge(SOURCE, Z, 0, 1);
			A.add_edge(Z, i - lenP + 1, -point, 1);
			A.add_edge(Z, i + 1, 0, 1);
			A.add_edge(i + 1, SINK, 0, 1);
			Z++;
			now = pre[now];
		}
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", S);

	SOURCE = n + 1;
	SINK = n + 2;
	Z = n + 3;
	A.set(SOURCE, SINK);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s %d", P, &point);
		check();
	}

	int x;
	scanf("%d", &x);
	for (int i = 0; i < n; i++) {
		A.add_edge(i, i + 1, 0, x);
	}

	A.flow();
//	printf(">>>%d\n", A.total_flow);
	int ans = A.total_cost;
	printf("%d\n", -ans);
	return 0;
}