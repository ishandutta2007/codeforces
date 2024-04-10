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
const LL INF = 1e9;
const LL LINF = INF * INF;

const int MAX = 1 << 18;
int n;
VI g[MAX];
int p[MAX];
int s[MAX];
int a[MAX];

void bad()
{
	cout << -1 << endl;
	exit(0);
}

void dfs(int v, bool even)
{
	int batya = p[v];
	if (even)
	{
		int mx = INF;
		if (SZ(g[v]) == 0)
			return;
		
		for(auto i: g[v])
			mx = min(mx, s[i]);
		
		mx -= s[batya];
		if (mx < 0)
			bad();
		
		a[v] = mx;	
		for(auto i: g[v])
			dfs(i, even ^ 1);
	}
	else
	{
		int pp = p[p[v]];
		int bude = s[v] - s[pp];
		bude -= a[batya];
		
		if (bude < 0)
			bad();
		
		a[v] = bude;
		for(auto i: g[v])
			dfs(i, even ^ 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 2, n + 1)
	{
		cin >> p[i];
		g[p[i]].PB(i);
	}

	FOR(i, 1, n + 1)
		cin >> s[i];
	
	a[1] = s[1];
	for(auto i: g[1])
		dfs(i, 1);

	LL ans = 0;
	FOR(i, 1, n + 1)
		ans += a[i];
	
	cout << ans << endl;	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}