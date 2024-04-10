#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n, m;
VI g[N];
int tin[N];
int tout[N];
int timer;
int a[N];
int d[N];

struct SegTree
{
	int t[N << 1];
	
	void add(int v, int tl, int tr, int l, int r, int ADD)
	{
		if (l > r || tl > tr)
			return;
			
		if (tl == l && tr == r)
		{
			t[v] += ADD;
			return;
		}
		
		int tm = (tl + tr) >> 1;
		add(v * 2, tl, tm, l, min(r, tm), ADD);
		add(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, ADD);
	}
	
	int query(int v, int tl, int tr, int pos)
	{
		if (tl == tr)
			return t[v];
		int tm = (tl + tr) >> 1;
		if (pos <= tm)	
			return t[v] + query(2 * v, tl, tm, pos);
		else
			return t[v] + query(2 * v + 1, tm + 1, tr, pos);
	}
};

SegTree even, odd;

void dfs_init(int v, int p = -1)
{
	tin[v] = timer++;
	for(auto i: g[v])
		if (i != p)
		{
			d[i] = d[v] + 1;
			dfs_init(i, v);
		}
		
	tout[v] = timer - 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i];
		
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	dfs_init(0, -1);
	while(m--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x, val;
			cin >> x >> val;
			--x;
			int from = tin[x], to = tout[x];
			if (d[x] & 1)
			{
				odd.add(1, 0, n - 1, from, to, val);
				even.add(1, 0, n - 1, from, to, -val);
			}
			else
			{
				odd.add(1, 0, n - 1, from, to, -val);
				even.add(1, 0, n - 1, from, to, val);
			}
		}
		else
		{
			int x;
			cin >> x;
			--x;
			int res = a[x];
			if (d[x] & 1)
				res += odd.query(1, 0, n - 1, tin[x]);
			else
				res += even.query(1, 0, n - 1, tin[x]);
				
			cout << res << endl;
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}