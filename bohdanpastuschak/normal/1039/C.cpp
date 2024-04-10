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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const LL mod = 1e9 + 7;

inline LL mult(LL x, LL y)
{
	x %= mod;
	y %= mod;
	return (x * y) % mod;
}

inline LL sub(LL x, LL y)
{
	return ((x - y) % mod + mod) % mod;
}

inline LL add(LL x, LL y)
{
	return (x + y) % mod;
}

LL power(LL x, LL y)
{
	LL r = 1;
	while(y)
	{
		if (y & 1)
			r = mult(r, x);
		
		x = mult(x, x);
		y >>= 1;
	}
	
	return r;
}

const int MAX = 1 << 20;
int n, m, k;
VI g[MAX];
LL a[MAX];
char used[MAX];
LL treba;

void dfs(int v)
{
	used[v] = 1;
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (used[to])
			continue;
		
		if ((a[to] ^ a[v]) == treba)
			dfs(to);
	}	
}

map<LL, VI> xory;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m >> k;
	FOR(i, 0, n)
		cin >> a[i];
	
	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
		xory[a[u] ^ a[v]].PB(u);
		xory[a[u] ^ a[v]].PB(v);
	}
	
	LL ans = 0;
	
	for(auto i: xory)
	{
		VI vec = i.Y;
		sort(ALL(vec));
		vec.resize(unique(ALL(vec)) - vec.begin());
		
		LL rest = power(2, n - SZ(vec));
		treba = i.X;
		LL cntr = 0;
		LL dobutok = 1;
		for(auto j: vec)
		{
			if (used[j])
				continue;
			
			++cntr;
			dfs(j);
		}
		
		for(auto j: vec)
			used[j] = 0;
		
		dobutok = mult(dobutok, power(2, cntr));
		ans = add(ans, mult(rest, dobutok));
	}
	
	LL invyh = 1LL << k;
	invyh -= SZ(xory);
	
	ans = add(ans, mult(power(2, n), invyh));
	cout << ans << endl;	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}