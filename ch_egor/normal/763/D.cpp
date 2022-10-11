/*













 
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)

const int MAX_N = 1000 * 100 + 5;

const ll Q = 22731;
const ll P = 1000 * 1000 * 1000 + 123;
const ll ebal = 112248973;

int n;
int res = 0;
int at_res = -1;
vector<int> g[MAX_N];
vector<ll> gg[MAX_N];
vector<ll> cch[MAX_N];
ll h[MAX_N];
ll ch[MAX_N];
ll pw[MAX_N];
vector<pii> down[MAX_N];
int cur_ans = 0;
map<ll, int> alive;
vector<ll> ex[MAX_N];

ll rev(ll x)
{
	ll ans = 0;
	for (int i = 0; i < 32; ++i)
	{
		ans |= (((x >> i) & 1) << (32 - i));
	}
	return ans;
}


int get()
{
	return cur_ans;
}

void add(ll x)
{
	if (alive[x] == 0)
	{
		++cur_ans;
	}
	++alive[x];
}

void del(ll x)
{
	if (alive[x] == 1)
	{
		--cur_ans;
	}
	--alive[x];
}

void upd(int v)
{
//	cout << v << " " << get() << endl;
	if (get() > at_res)
	{
		at_res = get();
		res = v;
	}
}

void dfs(int v, int p = -1)
{
	if ((int)g[v].size() == 1 && p != -1)
	{
		ch[v] = h[v] = ebal % P;
		add(h[v]);
		return;
	}
	for (int i = 0; i < (int)g[v].size(); ++i)
	{
		int u = g[v][i];
		if (u != p)
		{
			dfs(u, v);
			down[v].push_back(mp(h[u], u));
		}
	}
	sort(down[v].begin(), down[v].end());
	gg[v].resize(down[v].size() + 1);	
	gg[v][0] = h[v] = ebal % P;
	for (int i = 0; i < (int)down[v].size(); ++i)
	{
		h[v] = (h[v] * Q + rev(down[v][i].fi)) % P;
		gg[v][i + 1] = h[v];
	}
	ch[v] = h[v];
	add(h[v]);	
}

void dfs_ya_ebal(int v, int p = -1)
{
	ch[v] = ebal % P;
	cch[v].resize(down[v].size() + 1);
	cch[v][0] = ch[v];
	sort(down[v].begin(), down[v].end());
	for (int i = 0; i < (int)down[v].size(); ++i)
	{
		ch[v] = (ch[v] * Q + rev(down[v][i].fi)) % P;
		cch[v][i + 1] = ch[v];
	}
	
	if (p != -1)
	{
		del(h[v]);
		add(ch[v]);
	}
	upd(v);

	for (int i = 0; i < (int)down[v].size(); ++i)
	{
		int u = down[v][i].se;
		if (u != p)
		{
			del(ch[v]);
			ll cur_hs = 0;
			
			int sz = (int)down[v].size();
			cur_hs = cch[v][i] * pw[sz - i - 1] % P;
			cur_hs += ch[v] - cch[v][i + 1] * pw[sz - i - 1];
			cur_hs = (cur_hs % P + P) % P;

			add(cur_hs);
			down[u].push_back(mp(cur_hs, v));
			dfs_ya_ebal(u, v);
			del(cur_hs);
			add(ch[v]);
		}
	}

	add(h[v]);
	del(ch[v]);
}

int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	
	pw[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		pw[i] = pw[i - 1] * Q % P;

	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		--u; --v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}

	dfs(0);
	res = 0;
	at_res = get();
	//cout << at_res << endl;
	dfs_ya_ebal(0);

	printf("%d\n", res + 1);
}