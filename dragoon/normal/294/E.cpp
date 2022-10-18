#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;


struct PTT
{
	int u, v, w;
	PTT(int a, int b, int c)
	{
		u = a, v = b, w = c;
	}

	PTT(){}
};

typedef __int64 LL;
typedef pair<int, LL> PII;

vector<PII> V[5003];
vector<PTT> E;
PII info_dfs1[5003];
PII info_dfs2[5003];

PII DFS1(int u, int par)
{
	int node = 1;
	LL cost = 0;

	int i, v, sz = V[u].size();
	PII now;

	for(i = 0; i < sz; i++)
	{
		v = V[u][i].first;

		if(v == par)
			continue;

		now = DFS1(v, u);

		node += now.first;
		cost += now.second + V[u][i].second*now.first;
	}

	return info_dfs1[u] = PII(node, cost);
}

LL ans, total, costs;
void DFS2(int u, int par, LL c)
{
	LL now = c + info_dfs1[u].second;
	if(ans > now)
		ans = now;

	int i, v, sz = V[u].size();
	LL cost;
	for(i = 0; i < sz; i++)
	{
		v = V[u][i].first;

		if(v == par)
			continue;

		cost = c + info_dfs1[u].second - info_dfs1[v].second - V[u][i].second*info_dfs1[v].first + V[u][i].second*(total - info_dfs1[v].first);

//		cost = c + info_dfs1[u].second - info_dfs1[v].first*V[u][i].second + V[u][i].second*(total - info_dfs1[v].first); 
		costs += info_dfs1[v].first*(total - info_dfs1[v].first)*V[u][i].second;

		DFS2(v, u, cost);
	}
}

int main()
{
	int n, a, b, i, sz;
	PII x, y;
	LL w, ans1, now;
	LL xcost, ycost;

	scanf("%d", &n);
	for(i = 1; i < n; i++)
	{
		scanf("%d %d %I64d", &a, &b, &w);
		V[a].push_back(PII(b, w));
		V[b].push_back(PII(a, w));
		E.push_back( PTT(a, b, w) );
	}

	ans1 = 1000000000;
	ans1 *= ans1;
	sz = E.size();
	for(i = 0; i < sz; i++)
	{
		w = E[i].w;

		DFS1(E[i].u, E[i].v);
		x.first = info_dfs1[E[i].u].first;
		ans = 1000000000;
		ans *= ans;
		total = x.first;
		costs = 0;
		DFS2(E[i].u, E[i].v, 0);
		x.second = ans;
		xcost = costs;

		DFS1(E[i].v, E[i].u);
		y.first = info_dfs1[E[i].v].first;
		ans = 1000000000;
		ans *= ans;
		total = y.first;
		costs = 0;
		DFS2(E[i].v, E[i].u, 0);
		y.second = ans;
		ycost = costs;

		now = x.first*y.first*w + x.second*y.first + y.second*x.first + xcost + ycost;

		if( ans1 > now )
			ans1 = now;
	}

	printf("%I64d\n", ans1);

	return 0;
}