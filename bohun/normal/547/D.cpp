#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 400005, mod = 1e9 + 7;
const ll inf = 1e18;
int n;
int x, y;
vector <pair<int, int>> v[nax];
int odw[nax];
int wsk[nax];
void dfs(int node)
{
	for(int &i = wsk[node]; ss(v[node]) > i; ++i)
	{
		if(!odw[v[node][i].se])
		{
			odw[v[node][i].se] = 1 + (node > 200000);
			dfs(v[node][i].fi);
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> x >> y;
		y += 200000;
		v[x].pb({y, i});
		v[y].pb({x, i});
	}
	vector <int> magic;
	int N = n + 1;
	for(int i = 1; nax > i; ++i)
	{
		if(ss(v[i]) & 1)
		{
			if(ss(magic))
			{
				int u = magic[0];
				magic.clear();
				v[i].pb({u, N});
				v[u].pb({i, N});
				++N;
			}
			else
				magic.pb(i);
		}
	}
	for(int i = 1; n + 200000 >= i; ++i)
		dfs(i);
							
	for(int i = 1; n >= i; ++i)
		cout << (odw[i] == 1 ? 'b' : 'r');
		
		
    return 0;
}