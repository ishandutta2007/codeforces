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

const int N = 2000043;

int add(int x, int y)
{
	x += y;
	while(x >= MOD) x -= MOD;
	while(x < 0) x += MOD;
	return x;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int n, m, n2;
vector<pt> g[N];

void add_edge(int x, int y, int i)
{
	vector<int> digs;
	while(i)
	{
		digs.pb(i % 10);
		i /= 10;
	}
	reverse(all(digs));
	int cur = x;
	int lst = digs.back();
	digs.pop_back();
	for(auto d : digs)
	{
		g[cur].pb(mp(n2, d));
		cur = n2;
		n2++;
	}
	g[cur].pb(mp(y, lst));
}

void add_road(int x, int y, int i)
{
	add_edge(x, y, i);
	add_edge(y, x, i);
}

bool read()
{
	scanf("%d %d", &n, &m);
	n2 = n;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		add_road(x, y, i + 1);
	}
	return true;
}

int d[N];
pt c[N];
int newc[N];
int ans[N];
int lastc = 0;

void solve()
{
	for(int i = 0; i < n2; i++)
		d[i] = INF;
	d[0] = 0;
	queue<int> q;
	q.push(0);
	int md = 0;
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		for(auto y : g[k])
			if(d[y.x] == INF)
			{
				q.push(y.x);
				d[y.x] = d[k] + 1;
				md = max(md, d[y.x]);
			}
	}

	vector<vector<int> > z(md + 1);
	assert(md == *max_element(d, d + n2));
	for(int i = 0; i < n2; i++)
	{
		if(d[i] < md)
			z[d[i]].push_back(i);
		c[i] = mp(INF, 0);
	}
	c[0] = mp(0, 0);
	for(int i = 0; i <= md; i++)
	{
		vector<pt> cc;
		vector<int> cur = z[i];
		for(auto x : cur) cc.push_back(c[x]);
		sort(all(cc));
		cc.erase(unique(all(cc)), cc.end());
		for(auto x : cur) newc[x] = lower_bound(all(cc), c[x]) - cc.begin();
		for(auto x : cur)
		{
			for(auto y : g[x])
			{
				if(d[y.x] != d[x] + 1)
					continue;
				pt nc = mp(newc[x], y.y);
				if(nc < c[y.x])
				{
					c[y.x] = nc;
					ans[y.x] = add(mul(ans[x], 10), y.y);
				}
			}
		}		
	}
	for(int i = 1; i < n; i++)
		printf("%d\n", ans[i]);
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