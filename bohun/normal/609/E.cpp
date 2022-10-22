#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 200005;
vector <pair <int, int> > v[nax];
vector < pair < int , pair <int, int > > > ed;
map < pair < int, int>, int > mapa;
pair < pair <int, int> , int > ha[nax];
int par[nax];
int Find(int x)
{
	if(par[x] != x)
		par[x] = Find(par[x]);
	return par[x];
}
int lca[nax][18], maxi[nax][18], h[nax];
void dfs(int node, int par)
{
	for(auto it: v[node])
	{
		if(it.fi == par)
			continue;
		h[it.fi] = h[node] + 1;
		lca[it.fi][0] = node;
		maxi[it.fi][0] = it.se;
		dfs(it.fi, node);
	}
}
void Onion(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x != y)
	{
		par[x] = y;
	}
}
int daj(int x, int y)
{
	if(h[y] > h[x])
		swap(x, y);
	int wynik = 0;
	for(int i = 17; i >= 0; --i)
		if(h[x] - (1 << i) >= h[y])
		{
			wynik = max(wynik, maxi[x][i]);
			x = lca[x][i];
		}
	if(x == y)
		return wynik;
	for(int i = 17; i >= 0; --i)
		if(lca[x][i] != lca[y][i])
		{
			wynik = max(wynik, maxi[x][i]);
			wynik = max(wynik, maxi[y][i]);
			x = lca[x][i];
			y = lca[y][i];
		}
	wynik = max(wynik, maxi[x][0]);
	wynik = max(wynik, maxi[y][0]);
	return wynik;
}
ll sum = 0;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; m >= i; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ed.pb({c, {a, b}});
		ha[i] = {{a, b}, c};
	}
	sort(ed.begin(), ed.end());
	for(int i = 1; n >= i; ++i)
		par[i] = i;
	for(auto it: ed)
	{
		int A = it.se.fi;
		int B = it.se.se;
		if(Find(A) == Find(B))
			continue;
		mapa[{A, B}] = mapa[{B, A}] = 1;
		v[A].pb({B, it.fi});
		v[B].pb({A, it.fi});
		Onion(A, B);
		sum += it.fi;
	}
	dfs(1, -1);
	for(int j = 1; 17 >= j; ++j)
		for(int i = 1; n >= i; ++i)
		{
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
			maxi[i][j] = max(maxi[i][j - 1], maxi[lca[i][j - 1]][j - 1]);
		}
	
	for(int i = 1; m >= i; ++i)
	{
		int x = ha[i].fi.fi;
		int y = ha[i].fi.se;
		if(mapa[{x, y}] == 1)
		{
			cout << sum << endl;
			continue;
		}
		cout << sum + ha[i].se - daj(x, y) << endl;
	}
	
	
	return 0;
}