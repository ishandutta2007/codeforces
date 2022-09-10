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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n;
vector<PII> g[N];
pair<int, PII> e[N];
int sz[N];
int batya[N];
LL dp[N][2];

void dfs_sz(int v, int p)
{
	sz[v] = 1;
	batya[v] = p;
	for(auto i: g[v]) if (i.X != p)
	{
		dfs_sz(i.X, v);
		sz[v] += sz[i.X];
	}
}

void dfs_dp(int v, int p)
{
	vector<int> odd, even;
	FOR(I, 0, SZ(g[v]))
	{
		PII i = g[v][I];
		if (i.X != p)
		{
			dfs_dp(i.X, v);
			if (sz[i.X] & 1) odd.PB(I);
			else even.PB(I);
		}
	}
	
	if (sz[v] % 2 == 0) dp[v][1] = LINF;
	else
	{
		dp[v][1] = 0;
		for(auto id: even)
			dp[v][1] += dp[g[v][id].X][0];
		for(auto id: odd)
			dp[v][1] += g[v][id].Y + dp[g[v][id].X][1];
	}
	
	if (sz[v] & 1) dp[v][0] = LINF;
	else
	{
		dp[v][0] = 0;
		for(auto id: even)
			dp[v][0] += dp[g[v][id].X][0];
		for(auto id: odd)
			dp[v][0] += g[v][id].Y + dp[g[v][id].X][1];
	}
}

void solve()
{
	cin >> n;
	FOR(i, 0, 2 * n) g[i].clear();
	FOR(i, 0, 2 * n - 1)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		e[i] = {w, {u, v}};
		g[u].PB({v, w});
		g[v].PB({u, w});
	}
	
	dfs_sz(0, -1);
	
	LL b = 0;
	FOR(i, 0, 2 * n - 1)
	{
		int u = e[i].Y.X, v = e[i].Y.Y, w = e[i].X;
		if (batya[u] == v) swap(u, v);
		b += w * (LL) min(sz[v], 2 * n - sz[v]);
	}	
	
	dfs_dp(0, -1);
	
	cout << dp[0][0] << ' ' << b << endl;	
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}