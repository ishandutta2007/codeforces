// Author: Little09
// Problem: D. The Beach
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
#define ll long long
const ll inf=1e18;
int n,m;
ll a,b;
vector<char>c[N];

#define num(x,y) (((x+1)-1)*(m)+(y+1))

ll dis[N];
bool vis[N];
struct point
{
	ll t,v;
	bool operator < (const point & o) const
	{
		return v>o.v;
	}
};
vector<point>t[N];
priority_queue<point>q;
void dij()
{
	for (int i=1;i<=n*m;i++) dis[i]=inf,vis[i]=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (c[i][j]=='.')
			{
				dis[num(i,j)]=0;
				point u;
				u.t=num(i,j),u.v=0;
				q.push(u);
			}
		}
	}
	while (!q.empty())
	{
		point v=q.top();
		q.pop();
		//cout << v.t << endl;
		if (vis[v.t]==1) continue;
		vis[v.t]=1;
		for (int i=0;i<t[v.t].size();i++) 
		{
			point to=t[v.t][i];
			if (dis[to.t]>dis[v.t]+to.v) 
			{
				dis[to.t]=dis[v.t]+to.v;
				point nxt={to.t,dis[to.t]};
				q.push(nxt);
			}
		}
	}
}
void add(int x,int y,int z)
{
	t[x].push_back({y,z});
}
void add(int x,int y,int X,int Y,int z)
{
	if (x<0||y<0||x>=n||y>=m) return;
	if (X<0||Y<0||X>=n||Y>=m) return;
	if (c[x][y]=='#'||c[X][Y]=='#') return;
	add(num(x,y),num(X,Y),z);
}
const int det[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> a >> b;
	
	for (int i=0;i<n;i++)
	{
		c[i].clear();
		for (int j=0;j<m;j++)
		{
			char x;
			cin >> x;
			c[i].push_back(x);
		}
	}
	for (int i=1;i<=n*m;i++) t[i].clear();
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (c[i][j]=='L') add(i,j+2,i,j,b),add(i,j-1,i,j+1,b),add(i+1,j,i,j+1,a),add(i-1,j,i,j+1,a);
			else if (c[i][j]=='U') add(i-1,j,i+1,j,b),add(i+2,j,i,j,b),add(i,j-1,i+1,j,a),add(i,j+1,i+1,j,a);
			else if (c[i][j]=='D') add(i,j+1,i-1,j,a),add(i,j-1,i-1,j,a);
			else if (c[i][j]=='R') add(i+1,j,i,j-1,a),add(i-1,j,i,j-1,a);
		}
	}
	dij();
	ll ans=inf;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			for (int k=0;k<4;k++)
			{
				int x=i+det[k][0],y=j+det[k][1];
				if (x<0||y<0||x>=n||y>=m) continue;
				ans=min(ans,dis[num(i,j)]+dis[num(x,y)]);
			}
		}
	}
	if (ans==inf) cout << -1;
	else cout << ans;
	return 0;
}