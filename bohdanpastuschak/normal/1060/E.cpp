#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

const int MAX = 200000 + 7;
int n;
VI g[MAX];
int sz[MAX];

LL ans = 0;

void dfssz(int v, int p = -1)
{
	sz[v] = 1;
	for(auto i: g[v])
		if (i != p)
		{
			dfssz(i, v);
			sz[v] += sz[i];
		}
}	

char color[MAX];

void dfs(int v, int c, int p)
{
	color[v] = c;
	for(auto i: g[v])
		if (i != p)
			dfs(i, 3 - c, v);
}

void dfscnt(int v, int p = -1)
{
	for(auto i: g[v])
		if (i != p)
		{
			ans += sz[i] * (LL) (n - sz[i]);
			dfscnt(i, v);
		}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int u, v;
	cin >> n;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	dfssz(0);
	dfs(0, 1, -1);
	dfscnt(0);
	
	int w = 0, b = 0;
	FOR(i, 0, n)
		if (color[i] == 1)
			++w;
		else
			++b;
	
	LL cnt_odd = 2 * (LL)w * b;
	ans *= 2;
	ans += cnt_odd;
	assert(ans % 4 == 0);
	ans /= 4;
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}