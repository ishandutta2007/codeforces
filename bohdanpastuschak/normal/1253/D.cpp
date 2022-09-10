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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n, m;
VI g[N];
int used[N];
int kin[N];

void dfs(int v, int cl)
{
	used[v] = cl;
	for(auto i: g[v]) if (!used[i]) dfs(i, cl);
}

void onowy(int& x, int y)
{
	x = max(x, y);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	int colir = 1;
	FOR(i, 1, n + 1)
		if (!used[i])
			dfs(i, colir++);
	
	FOR(i, 1, n + 1)
		onowy(kin[used[i]], i);
	
	int ans = 0;
	int najdali = 1;
	FOR(i, 1, n + 1)
	{
		najdali = max(najdali, kin[used[i]]);
		if (najdali == i)
		{
			ans++;
			continue;
		}		
	}
	
	cout << colir - ans - 1 << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}