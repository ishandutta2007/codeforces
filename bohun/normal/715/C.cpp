#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)
using namespace std;


const int nax = 100005;
int n, m;
vector <pair<int, int>> v[nax];	
int h[nax], dp[nax], alive[nax];
int nn = 0;
map <int, int> mapa;
int pot[nax];
ll ans = 0;


void licz(int node, int par)
{
	++nn;
	dp[node] = 1;
	for(auto it: v[node])
	{
		if(alive[it.fi] == 0 || par == it.fi)
			continue;
		licz(it.fi, node);
		dp[node] += dp[it.fi];
	}
}

int daj(int node, int par)
{
	for(auto it: v[node])
	{
		if(it.fi != par && alive[it.fi] && dp[it.fi] > nn / 2)
			return daj(it.fi, node);
	}
	return node;
}

int war[nax];

void dfs(int node, int par, int val)
{
	val %= m;
	war[node] = val;
	mapa[val]++;
	for(auto it: v[node])
	{
		if(it.fi == par || !alive[it.fi])
			continue;
		h[it.fi] = h[node] + 1;
		dfs(it.fi, node, (ll) it.se * pot[h[it.fi] - 1] % m + val);
	}
}

void remove(int node, int par, int plus)
{
	mapa[war[node]] += plus;
	for(auto it: v[node])
	{
		if(alive[it.fi] && it.fi != par)
			remove(it.fi, node, plus);
	}
}

int euklid(ll a, ll b, ll &x, ll &y)
{
	if(!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll nx, ny;
	ll d = euklid(b, a % b, nx, ny);
	x = ny;
	y = nx - (a / b) * ny;
	return d;
}
	

void go(int node, int par, int val)
{
	val %= m;
	ll x , y;
	euklid(pot[h[node]], m, x, y);
	x += (ll) m * 1000000;
	x %= m;
	ll X = (ll) (m - val) * x % m;
	ans += mapa[X];
	for(auto it: v[node])
	{
		if(alive[it.fi] && it.fi != par)
		{
			go(it.fi, node, (ll) val * 10 % m + it.se);
		}
	}
}

void decomp(int x)
{
	nn = 0;
	licz(x, -1);
	int cen = daj(x, -1);
	alive[cen] = 0;
	h[cen] = 0;
	mapa.clear();
	dfs(cen, -1, 0);
	//int X = ans;
	ans += mapa[0];
	
	for(auto it: v[cen])
	{
		if(alive[it.fi])
		{
			remove(it.fi, cen, -1);
			go(it.fi, cen, it.se);
			remove(it.fi, cen, 1);
		}
	}
	//cout << cen << " " << ans - X << endl;
	for(auto it: v[cen])
	{
		if(alive[it.fi])
			decomp(it.fi);
	}
}
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	
	scanf("%d %d", &n, &m);
	
	for(int i = 0; n - 1 > i; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		++a;
		++b;
		v[a].pb(mp(b, c));
		v[b].pb(mp(a, c));
	}
	
	for(int i = 1; n >= i; ++i)
		alive[i] = 1;
		
	pot[0] = 1 % m;
	for(int i = 1; n >= i; ++i)
		pot[i] = (ll) pot[i - 1] * 10 % m;
		
	decomp(1);
	
	printf("%lld", ans - n);
	
	
	
	
	
	
			
				
    return 0;
}