#pragma GCC optimize("Ofast")
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
const int INF = 1e9;
const int MaXN = 150;
const int N = 5e5 + 1000;
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
#define int ll
struct T
{
	struct Node
	{
		int mx0;
		int mx1;
		bool flip;
	};
	Node f(Node a, Node b)
	{
		return { max(a.mx0, b.mx0), max(a.mx1, b.mx1), false };
	}
	int n;
	vector<Node> t;
	T(int n, vector<int>& dep, vector<int>& par) : n(n), t(4 * n)
	{
		build(1, 0, n - 1, dep, par);
	}
	void build(int v, int l, int r, vector<int>& dep, vector<int>& par)
	{
		if (l == r)
		{
			t[v] = (par[l] == 1 ? Node{ 0, dep[l], false } : Node{ dep[l], 0, false });
		}
		else
		{
			int m = (l + r) / 2;
			build(v * 2, l, m, dep, par);
			build(v * 2 + 1, m + 1, r, dep, par);
			t[v] = f(t[v * 2], t[v * 2 + 1]);
		}
	}
	int get()
	{
		return t[1].mx0;
	}
	void push(int v)
	{
		if (!t[v].flip)
		{
			return;
		}
		t[v].flip = false;
		swap(t[v * 2].mx0, t[v * 2].mx1);
		swap(t[v * 2 + 1].mx0, t[v * 2 + 1].mx1);
		t[v * 2].flip = !t[v * 2].flip;
		t[v * 2 + 1].flip = !t[v * 2 + 1].flip;
	}
	void flip(int v, int l, int r, int l1, int r1)
	{
		if (r < l1 || r1 < l)
		{
			return;
		}
		if (l1 <= l && r <= r1)
		{
			t[v].flip = !t[v].flip;
			swap(t[v].mx0, t[v].mx1);
			return;
		}
		push(v);
		int m = (l + r) / 2;
		flip(v * 2, l, m, l1, r1);
		flip(v * 2 + 1, m + 1, r, l1, r1);
		t[v] = f(t[v * 2], t[v * 2 + 1]);
	}
};
int n;
vector<vector<int>> g;
vector<int> uu, vv, tt;
int m;
vector<int> id;
vector<int> dep;
vector<int> par;
vector<int> in;
vector<int> out;
int timer;
void dfs(int v, int p)
{
	in[v] = timer++;
	for (int i : g[v])
	{
		int to = v ^ uu[i] ^ vv[i];
		if (to != p)
		{
			dep[to] = dep[v] + 1;
			par[to] = par[v] ^ tt[i];
			dfs(to, v);
		}
	}
	out[v] = timer;
}
bool upper(int u, int v, vector<int>& in, vector<int>& out)
{
	return (in[u] <= in[v] && out[v] <= out[u]);
}
void solve()
{
	dep.resize(n);
	par.resize(n);
	in.resize(n);
	out.resize(n);
	dfs(0, -1);
	int du = max_element(dep.begin(), dep.end()) - dep.begin();
	dep[du] = 0;
	timer = 0;
	par[du] = 0;
	dfs(du, -1);
	auto udep = dep;
	auto upar = par;
	auto uin = in;
	auto uout = out;
	int dv = max_element(dep.begin(), dep.end()) - dep.begin();
	dep[dv] = 0;
	timer = 0;
	par[dv] = 0;
	dfs(dv, -1);
	vector<int> _dep(n);
	vector<int> _par(n);
	for (int i = 0; i < n; i++)
	{
		_dep[uin[i]] = udep[i];
		_par[uin[i]] = upar[i];
	}
	T ut = T(n, _dep, _par);
	for (int i = 0; i < n; i++)
	{
		_dep[in[i]] = dep[i];
		_par[in[i]] = par[i];
	}
	T t = T(n, _dep, _par);
	for (int i : id)
	{
		int u = uu[i];
		int v = vv[i];
		if (!upper(u, v, uin, uout))
		{
			swap(u, v);
		}
		ut.flip(1, 0, n - 1, uin[v], uout[v] - 1);
		if (!upper(u, v, in, out))
		{
			swap(u, v);
		}
		t.flip(1, 0, n - 1, in[v], out[v] - 1);
		cout << max(ut.get(), t.get()) << '\n';
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n);
	uu.resize(n - 1);
	vv.resize(n - 1);
	tt.resize(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> uu[i] >> vv[i] >> tt[i];
		--uu[i]; --vv[i];
		g[uu[i]].push_back(i);
		g[vv[i]].push_back(i);
	}
	cin >> m;
	id.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> id[i];
		id[i]--;
	}
	solve();
	return 0;
}