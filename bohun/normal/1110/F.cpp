#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) ((int)v.size())
#define fi first
#define se second
using namespace std;
int n, q;
int a, b, c;
const int nax = 500005;
vector <pair < int, int> > v[nax];
struct ee{
	int l, r, id;
};
ll res[nax];
vector < ee > e[nax];
int j = (1 << 19);
ll t[(1 << 20) + 5];
ll lazy[(1 << 20) + 5];
ll dp[nax];
void akt(int u)
{
	t[u] = min(t[2 * u], t[2 * u + 1]);
}
int w[nax][2];
void push(int u)
{
	t[2 * u] += lazy[u];
	t[2 * u + 1] += lazy[u];
	lazy[2 * u] += lazy[u];
	lazy[2 * u + 1] += lazy[u];
	lazy[u] = 0;
}
void add(int u, int lewo, int prawo, int x, int y, int ile)
{
	if(x > y)
		return ;
	if(y >= prawo and lewo >= x)
	{
		t[u] += ile;
		lazy[u] += ile;
		return ;
	}
	int mid = (lewo + prawo) / 2;
	push(u);
	if(mid >= x)
		add(2 * u, lewo, mid, x, y, ile);
	if(y > mid)
		add(2 * u + 1, mid + 1, prawo, x, y, ile);
	akt(u);
}
ll mini(int u, int lewo, int prawo, int x, int y)
{
	if(y >= prawo and lewo >= x)
		return t[u];
	ll wynik = 1e18;
	int mid = (lewo + prawo) / 2;
	push(u);
	if(mid >= x)
		wynik = mini(2 * u, lewo, mid, x, y);
	if(y > mid)
		wynik = min(wynik, mini(2 * u + 1, mid + 1, prawo, x, y));
	return wynik;
}
void dfs(int u)
{
	w[u][0] = w[u][1] = u;
	for(auto it: v[u])
	{
		dp[it.fi] = dp[u] + it.se;
		dfs(it.fi);
		w[u][1] = max(w[u][1], w[it.fi][1]);
	}	
}
void go(int u)
{
	for(auto it: v[u])
	{
		add(1, j, 2 * j - 1, j + w[it.fi][0], j + w[it.fi][1], -it.se);
		add(1, j, 2 * j - 1, j + 1, j + w[it.fi][0] - 1, it.se);
		add(1, j, 2 * j - 1, j + w[it.fi][1] + 1, j + n, it.se);
		go(it.fi);
		add(1, j, 2 * j - 1, j + w[it.fi][0], j + w[it.fi][1], it.se);
		add(1, j, 2 * j - 1, j + 1, j + w[it.fi][0] - 1, -it.se);
		add(1, j, 2 * j - 1, j + w[it.fi][1] + 1, j + n, -it.se);
	}	
	for(auto it: e[u])
	{
		res[it.id] = mini(1, j, 2 * j - 1, j + it.l, j + it.r);
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 0; n - 1 > i; ++i)
	{
		cin >> a >> b;
		v[a].push_back({i + 2, b});
	}
	for(int i = 1; q >= i; ++i)
	{
		ee p;
		cin >> a >> p.l >> p.r ;
		p.id = i;
		e[a].pb(p);
	}
	dfs(1);
	for(int i = 1; n >= i; ++i)
	{
		if(i == 1 or ss(v[i]) > 0)
			t[j + i] = 1e18;
		else
			t[j + i] = dp[i];
	}
	for(int i = j - 1; i >= 1; --i)
	{
		akt(i);
	}
	go(1);
	
	for(int i = 1; q >= i; ++i)
		cout << res[i] << " ";
		
	
	return 0;
}