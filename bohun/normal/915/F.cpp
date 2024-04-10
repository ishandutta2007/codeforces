#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
using namespace std;
int n;
const int nax = 1000005;
int val[nax];
int a, b;
vector <int> v[nax];
ll ans;
int par[nax], siz[nax], odw[nax];
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
	siz[x] += siz[y];
	par[y] = x;
}
void init()
{
	for(int i = 1; n >= i; ++i)
	{
		par[i] = i;
		odw[i] = 0;
		siz[i] = 1;
	}
}
pair <int, int> d[nax];
ll daj()
{
	init();
	for(int i = 1; n >= i; ++i)
		d[i] = {val[i], i};
	sort(d + 1, d + n + 1);
	ll res = 0;
	for(int i = 1; n >= i; ++i)
	{
		int node = d[i].se;
		int ile = 1;
		for(auto it: v[node])
		{
			if(odw[it] == 0)
				continue;
			res += (ll) ile * d[i].fi * siz[Find(it)];
			ile += siz[Find(it)];
			Union(it, node);
		}
		odw[node] = 1;
	}
	return res;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> val[i];
	for(int i = 0; n - 1 > i; ++i)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	ans += daj();
	for(int i = 1; n >= i; ++i)
		val[i] *= -1;
	ans += daj();
	cout << ans;
	
	
	return 0;
}