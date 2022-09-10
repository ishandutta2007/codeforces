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

void bad()
{
	cout << "No" << endl;
	exit(0);
}

const int MAX = 1 << 17;
int n, k;
set<int> g[MAX];
int d[MAX];
int par[MAX];

VI tut;

void dfs(int v, int p = -1)
{
	tut.PB(v);
	for(auto i: g[v])
		if (i != p)
			par[i] = v, d[i] = d[v] + 1, dfs(i, v);
}

void check(int v, int level)
{
	tut.clear();
	d[v] = 0;
	dfs(v);
	
	if (level == 1)
	{
		int cnt = 0;
		if (SZ(tut) < 4)
			bad();
		for(auto i: tut)
			if (SZ(g[i]) > 1)
				++cnt;
		if (cnt > 1)
			bad();
		
		return;
	}
	
	if (SZ(tut) < 4)
		bad();
	
	int leaf = -1;
	for(auto i: tut)
		if (SZ(g[i]) == 1)
		{
			leaf = i;
			break;
		}
	
	tut.clear();
	d[leaf] = 0;
	dfs(leaf);
	int ins = -1;
	for(auto i: tut)
		if (ins == -1 || d[ins] < d[i])
			ins = i;
	
	if (d[ins] != level * 2)
		bad();
	
	v = ins;
	FOR(i, 0, level)
		v = par[v];
	
	if (SZ(g[v]) < 3)
		bad();
	
	for(auto i: g[v])
	{
		g[i].erase(v);
		check(i, level - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> k;
	int u, v;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		--u; --v;
		g[u].insert(v);
		g[v].insert(u);
	}
	
	if (k > 12)
		bad();
	
	check(0, k);	
	cout << "Yes" << endl;	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}