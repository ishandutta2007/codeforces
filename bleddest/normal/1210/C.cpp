#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define all(a) (a).begin(), (a).end() 
#define sz(a) (int((a).size()))

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const int MOD = INF + 7;
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(-1.0);

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B>& p)
{
	return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream& out, const vector<A>& p)
{
	out << "[";
	forn(i, sz(p))
	{
	 	if(i) out << ", ";
		out << p[i];
	}
	return out << "]";

}

const int N = 100043;

li a[N];
vector<int> g[N];
int n;
int ans = 0;

int norm(li x)
{
	return x % MOD;
}

int add(int x, int y)
{
	x += y;
	while(x >= MOD) x -= MOD;
	return x;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

vector<pair<li, int> > upd(vector<pair<li, int> > z, li c)
{
	vector<pair<li, int> > c2;
	forn(i, sz(z))
	{
		li v = __gcd(c, z[i].x);
		if(c2.empty() || c2.back().x != v)
			c2.pb(mp(v, z[i].y));
		else
			c2.back().y += z[i].y;
	}
	if(c2.empty() || c2.back().x != c)
		c2.pb(mp(c, 1));
	else
		c2.back().y++;
	return c2;
}

void dfs(int v, int p, vector<pair<li, int> > cur)
{
	cur = upd(cur, a[v]);
	for(auto x : cur)
	{
		ans = add(ans, mul(norm(x.x), x.y));
	}
	for(auto y : g[v])
		if(y != p)
			dfs(y, v, cur);
}

bool read()
{
 	if(scanf("%d", &n) != 1)
		return false;	
	forn(i, n) scanf("%lld", &a[i]);
	forn(i, n - 1)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		g[x].pb(y);
		g[y].pb(x);
	}
	return true;
}

void solve()
{
	vector<pair<li, int> > cur;
	dfs(0, 0, cur);
	cout << ans << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	ld curt = clock();
#endif        
	cout << setprecision(15) << fixed;
	cerr << setprecision(15) << fixed;
	read();
	solve();
#ifdef _DEBUG
	cerr << (clock() - curt) << endl;
#endif
}