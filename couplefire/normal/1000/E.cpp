#include<bits/stdc++.h>

using namespace std;

const int N = 500043;

vector<int> g[N];
vector<int> t[N];
int tin[N], tout[N], fup[N];
int p[N];
int T = 1;
int rnk[N];
vector<pair<int, int> > bridges;
int st;
int d[N];
int n, m;

int get(int x)
{
 	return (p[x] == x ? x : p[x] = get(p[x]));
}

void link(int x, int y)
{
 	x = get(x);
 	y = get(y);
 	if(x == y) return;
 	if(rnk[x] > rnk[y])
 		swap(x, y);
 	p[x] = y;
 	rnk[y] += rnk[x];	
}

int dfs(int x, int par = -1)
{
	tin[x] = T++;
	fup[x] = tin[x];
	for(auto y : g[x])
	{
	 	if(tin[y] > 0)
	 	{
	 		if(par != y)
	 			fup[x] = min(fup[x], tin[y]);
	 	}
	 	else
	 	{
	 	 	int f = dfs(y, x);
	 	 	fup[x] = min(fup[x], f);
	 	 	if(f > tin[x])
	 	 		bridges.push_back(make_pair(x, y));
	 	 	else
	 	 		link(x, y);
	 	}
	}
	tout[x] = T++;                                      
	return fup[x];
}      

void build()
{
 	for(auto z : bridges)
 	{
 	 	int x = get(z.first);
 	 	int y = get(z.second);
 	 	st = x;
 	 	t[x].push_back(y);
 	 	t[y].push_back(x);
 	}
}

pair<int, int> bfs(int x)
{
	for(int i = 0; i < n; i++)
		d[i] = n + 1;
	d[x] = 0;
	queue<int> q;
	q.push(x);
	int last = 0;
	while(!q.empty())
	{
	 	last = q.front();
	 	q.pop();
	 	for(auto y : t[last])
	 		if(d[y] > d[last] + 1)
	 		{
	 		 	d[y] = d[last] + 1;
	 		 	q.push(y);
	 		}
	}
	return make_pair(last, d[last]);
}

int main()
{                
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		rnk[i] = 1, p[i] = i;
	for(int i = 0; i < m; i++)
	{
	 	int x, y;
	 	scanf("%d %d", &x, &y);
	 	--x;
	 	--y;
	 	g[x].push_back(y);
	 	g[y].push_back(x);
	}
	dfs(0);
	build();
	pair<int, int> p1 = bfs(st);
	pair<int, int> p2 = bfs(p1.first);
	printf("%d\n", p2.second);
}