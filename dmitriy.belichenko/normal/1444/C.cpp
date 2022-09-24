#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 998244353;
const int INF = 1e5;
const int MaXN = 150;
const int N = 5e5 + 11;
const int LOG = 25;
const int FACT = 120;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0, (ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
	a += b;
	if (a < 0LL) a += MOD;
	if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
{
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
	return a;

}
int to_i(char c)
{
	return c - 'a';
}
ll mult(ll a, ll b) {
	ll val = a * b - (ll)((ld)a * b / MOD) * MOD;
	if (val < 0) {
		val += MOD;
	}
	if (val >= MOD) {
		val -= MOD;
	}
	return val;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll gcd_eu(ll a, ll b, ll & x, ll & y)
{
	if (a == 0)
	{
		x = 0LL; y = 1LL;
		return b;
	}
	ll x1, y1;
	ll d = gcd_eu(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
long long poww(long long a, long long b)
{
	long long val = 1;
	a %= MOD;
	while (b > 0)
	{
		if (b % 2) val = mult(a, val);
		a = mult(a, a);
		b >>= 1;
	}
	return val % MOD;
}
ll inv(ll a)
{
	return poww(a, MOD - 2);
}
//#define int ll
int n, m, k;
vector<int> col;
vector<vector<int>> g;
void read()
{
	cin >> n >> m >> k;
	col.resize(n);
	for (auto& c : col)
	{
		cin >> c;
		--c;
	}
	g.resize(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
vector<int> par;
bool bad;
vector<int> mapping;
void dfs(int v, int _col, int zero)
{
	if (par[v] == 0)
	{
		mapping[v] = zero;
	}
	else {
		mapping[v] = zero + 1;
	}
	for (int to : g[v])
	{
		if (col[to] != _col)
		{
			continue;
		}
		if (par[to] == -1) {
			par[to] = !par[v];
			dfs(to, _col, zero);
		}
		else if (par[to] != !par[v])
		{
			bad = true;
		}
	}
}
vector<int> another_col;
vector<set<pair<int, int>>> gg;
vector<int> lst;
int timer;
void dfs_govna(int v, int c1, int c2)
{
	while (true)
	{
		auto it = gg[v].lower_bound({ c2, -1 });
		if (it == gg[v].end() || it->first != c2)
		{
			break;
		}
		int to = it->second;
		gg[v].erase(it);
		gg[to].erase({ c1, v });
		if (lst[to] != timer)
		{
			par[to] = !par[v];
			lst[to] = timer;
			dfs_govna(to, c2, c1);
		}
		else if (par[to] != !par[v])
		{
			bad = true;
		}
	}
	if (lst[v ^ 1] != timer)
	{
		par[v ^ 1] = !par[v];
		lst[v ^ 1] = timer;
		dfs_govna(v ^ 1, c1, c2);
	}
	else if (par[v ^ 1] != !par[v])
	{
		bad = true;
	}
}
void solve()
{
	par.resize(n, -1);
	vector<bool> odd(k);
	ll ans = k;
	mapping.resize(n, -1);
	for (int u = 0; u < n; u++)
	{
		if (par[u] == -1)
		{
			bad = false;
			par[u] = 0;
			dfs(u, col[u], another_col.size());
			if (bad)
			{
				if (odd[col[u]] == false)
				{
					odd[col[u]] = true;
					ans--;
				}
			}
			another_col.push_back(col[u]);
			another_col.push_back(col[u]);
		}
	}
	ans = ans * (ans - 1) / 2;
	n = another_col.size();
	gg.resize(n);
	for (int u = 0; u < g.size(); u++)
	{
		if (odd[col[u]])
		{
			continue;
		}
		for (int to : g[u])
		{
			if (odd[col[to]] || col[u] == col[to])
			{
				continue;
			}
			gg[mapping[u]].insert({ another_col[mapping[to]], mapping[to] });
		}
	}
	vector<pair<int, int>> es;
	for (int u = 0; u < n; u++)
	{
		for (auto to : gg[u])
		{
			if (u < to.second)
			{
				es.emplace_back(u, to.second);
			}
		}
	}
	set<pair<int, int>> pairs;
	lst.resize(n);
	par.resize(n);
	for (auto se : es)
	{
		int c1 = another_col[se.first];
		int c2 = another_col[se.second];
		if (c1 > c2)
		{
			swap(c1, c2);
			swap(se.first, se.second);
		}
		if (pairs.count({ c1, c2 }))
		{
			continue;
		}
		timer++;
		bad = false;
		par[se.first] = 0;
		lst[se.first] = timer;
		dfs_govna(se.first, c1, c2);
		if (bad == true)
		{
			pairs.insert({ c1, c2 });
		}
	}
	cout << ans - pairs.size() << "\n";
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	read();
	solve();
}