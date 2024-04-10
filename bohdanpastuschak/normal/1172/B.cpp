#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
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

const int mod = 998244353;

inline int mult(int x, int y)
{
	return x * (LL) y % mod;
}

const int N = 1 << 18;
int n;
VI g[N];
int sz[N];
int f[N];

void dfs1(int v, int p)
{
	sz[v] = 1;
	for(auto i: g[v])
		if (i != p)
		{
			dfs1(i, v);
			sz[v] += sz[i];
		}
}

int dfs2(int v, int p)
{
	int res = f[SZ(g[v])];
	
	for(auto i: g[v])
		if (i != p)
			res = mult(res, dfs2(i, v));
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	f[0] = 1;
	FOR(i, 1, N)
		f[i] = mult(f[i - 1], i);
	
	cin >> n;
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	dfs1(1, -1);
	int ans = f[SZ(g[1])];
	for(auto i: g[1])
		ans = mult(ans, dfs2(i, 1));

	ans = mult(ans, n);
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}