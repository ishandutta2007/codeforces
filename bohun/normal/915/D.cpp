#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
using namespace std;
int n, m;
vector <pair <int, int> > v[505];
int odw[505];
pair <int, int> pop[505];
bool jest = 0;
int pocz, kon;
vector <int> id;
int numer = -1;
void dfs(int node, bool keep)
{
	odw[node] = 1;
	for(auto it: v[node])
	{
		if(it.se == numer)
			continue;
		if(odw[it.fi] == 1 && jest == 0)
		{
			jest = 1;
			pocz = it.fi;
			kon = node;
			if(keep)
				id.pb(it.se);
		}
		if(odw[it.fi] == 0)
		{
			pop[it.fi] = {it.se, node};
			dfs(it.fi, keep);
		}
	}
	odw[node] = 2;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; m >= i; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].pb({b, i});
	}
	for(int i = 1; n >= i; ++i)
		if(!odw[i])
			dfs(i, 1);
	if(!jest)
	{
		cout << "YES\n";
		return 0;
	}
	while(kon != pocz)
	{
		id.pb(pop[kon].fi);
		kon = pop[kon].se;
	}
	for(auto it: id)
	{
		jest = 0;
		numer = it;
		for(int i = 1; n >= i; ++i)
			odw[i] = 0;
		for(int i = 1; n >= i; ++i)
			if(!odw[i])
				dfs(i, 0);
		if(!jest)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	
	
	return 0;
}