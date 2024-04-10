#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m , q;
const int nax = 300005;
int par[nax];
int wynik[nax];
vector < int > e[nax];
int ans = 0;
int Find(int x)
{
	if(par[x] != x)
		par[x] = Find(par[x]);
	return par[x];
}
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x == y)
		return ;
	int xx = wynik[x];
	int yy = wynik[y];
	int zz = xx / 2 + (xx & 1) + yy / 2 + (yy & 1) + 1;
	xx = max(xx, yy);
	zz = max(zz, xx);
	par[x] = y;
	wynik[y] = zz;
}
bool odw[nax];
int dp[nax];
void go(int node)
{
	odw[node] = 1;
	int naj1 = 0, naj2 = 0;
	for(auto it: e[node])
		if(!odw[it])
			{
				go(it);
				int x = dp[it] + 1;
				if(x > naj1)
					swap(x, naj1);
				if(x > naj2)
					swap(x, naj2);
			}
	dp[node] = naj1;
	ans = max(ans, naj1 + naj2);
}
int main()
{	
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; n >= i; ++i)
		par[i] = i;
	for(int i = 1; m >= i; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			e[a].pb(b);
			e[b].pb(a);
			Union(a, b);
		}
	for(int i = 1; n >= i; ++i)
		if(!odw[i])
			{
				ans = 0;
				go(i);
				wynik[Find(i)] = ans;
			}
	while(q--)
	{
		int t, x;
		scanf("%d %d", &t, &x);
		if(t == 1)
			printf("%d\n", wynik[Find(x)]);
		else
			{
				int y;
				scanf("%d", &y);
				Union(x, y);
			}
	}
		
	
}