#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
int n;
VI g[N];
int color[N];

void dfs(int v, int p, int c)
{
	color[v] = c;
	for(auto i: g[v]) if (i != p)
		dfs(i, v, 3 - c);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	dfs(0, -1, 1);
	int all = 0, c1 = 0;
	FOR(i, 0, n) if (SZ(g[i]) == 1)
		all++, c1 += color[i] == 1;
		
	if (all == c1 || c1 == 0)
		cout << "1 ";
	else
		cout << "3 ";
	
	int ans = n - 1;
	FOR(i, 0, n)
	{
		int cnt = 0;
		for(auto j: g[i]) cnt += SZ(g[j]) == 1;
		if (cnt) ans -= cnt - 1;
	}
	
	cout << ans << endl;	
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}