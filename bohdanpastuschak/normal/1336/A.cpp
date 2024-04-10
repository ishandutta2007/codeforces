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

const int N = 1 << 18;
int n, k;
VI g[N];
int d[N];
int sz[N];
int idx[N];

void dfs(int v, int p)
{
	sz[v] = 1;
	for(auto i: g[v]) if (i != p)
	{
		d[i] = d[v] + 1;
		dfs(i, v);
		sz[v] += sz[i];
	}
}

int cmp(int x, int y)
{
	return d[x] - sz[x] > d[y] - sz[y];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	cin >> n >> k;
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	dfs(0, -1);
	iota(idx, idx + n, 0);
	sort(idx, idx + n, cmp);
	
	LL ans = 0;
	FOR(I, 0, k)
	{
		int i = idx[I];
		ans += d[i];
		ans -= sz[i] - 1;
	}
	
	assert(ans >= 0);
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}