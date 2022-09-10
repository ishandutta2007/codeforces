#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
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
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 19;
int n, k;
vector<PII> g[N];
LL dp[N][2];

int cmp(pair<LL, LL> x, pair<LL, LL> y)
{
	return x.Y - x.X > y.Y - y.X;
}

LL get(int treba, vector<pair<LL, LL>>& vec)
{
	LL ans = 0;
	FOR(i, 0, treba)
		ans += max(vec[i].X, vec[i].Y);
	
	FOR(i, treba, SZ(vec))
		ans += vec[i].X;
	
	return ans;
}

void dfs(int v, int p)
{
	int sz = SZ(g[v]);
	if (v)
		--sz;
		
	vector<pair<LL, LL>> vec(sz);
	int ptr = 0;
	for(auto i: g[v])
		if (i.X != p)
		{
			dfs(i.X, v);
			vec[ptr++] = {dp[i.X][0], dp[i.X][1] + i.Y};
		}
		
	sort(ALL(vec), cmp);
	int zara = min(SZ(vec), k);
	dp[v][0] = get(zara, vec);
	zara = min(SZ(vec), k - 1);
	dp[v][1] = get(zara, vec);
}

void solve()
{
	cin >> n >> k;
	FOR(i, 0, n)
		g[i].clear();
	
	FOR(i, 0, n - 1)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].PB({v, w});
		g[v].PB({u, w});
	}
	
	dfs(0, -1);
		
	cout << dp[0][0] << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--)
		solve();
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}