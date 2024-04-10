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

const int mod = 1e9 + 7;
	
inline int add(int x, int y, int m = mod)
{
	if (x + y < m)
		return x + y;
	return x + y - m;
}

inline int sub(int x, int y, int m = mod)
{
	if (x >= y)
		return x - y;
	return x - y + m;
}

inline int mult(int x, int y, int m = mod)
{
	return x * (LL) y % m;
}

const int LOG = 17;
const int N = 1 << LOG;
int n;
VI g[N];
LL x[N];
int ans;
map<LL, int> mp[N];

void dfs(int v, int p)
{	
	mp[v][x[v]]++;
	if (v != p)
		for(auto i: mp[p])
			mp[v][__gcd(i.X, x[v])] += i.Y;
	
	for(auto i: mp[v])
		ans = add(ans, mult(i.X % mod, i.Y));
		
	for(auto i: g[v])
		if (i != p)
			dfs(i, v);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
		cin >> x[i];
	
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}	
	
	dfs(0, 0);	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}