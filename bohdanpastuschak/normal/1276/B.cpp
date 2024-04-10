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
int n, m;
VI g[N];
char used[2][N];

inline void dfs(int v, bool id)
{
	used[id][v] = 1;
	for(auto i: g[v])
		if (!used[id][i]) dfs(i, id);
}

void solve()
{
	int a, b;
	cin >> n >> m >> a >> b;
	--a; --b;
	FOR(i, 0, n) g[i].clear();
	FOR(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}	

	FOR(j, 0, 2) FOR(i, 0, n) used[j][i] = 0;
	
	used[1][a] = 1;
	used[0][b] = 1;

	dfs(a, 0);
	dfs(b, 1);
	
	int raz = 0, dwa = 0;
	FOR(i, 0, n) if (used[0][i] && !used[1][i]) raz++;
	FOR(i, 0, n) if (used[1][i] && !used[0][i]) dwa++;
	cout << raz * (LL) dwa << '\n';
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