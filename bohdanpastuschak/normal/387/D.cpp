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

const int MAX = 1 << 9;
int n, m;
set<int> g[MAX];
vector<int> graph[MAX];
int mt[MAX];
char U[MAX];

bool kuhn(int v)
{
	if (U[v])
		return 0;
	
	U[v] = 1;
	
	for(auto i: graph[v])
		if (mt[i] == -1)
		{
			mt[i] = v;
			return 1;
		}
	
	for(auto i: graph[v])
		if (kuhn(mt[i]))
		{
			mt[i] = v;
			return 1;
		}
	
	return 0;
}

int matching()
{
	FILL(mt, -1);
	int ans = 0;
	FOR(i, 1, n + 1)
	{
		FILL(U, 0);
		ans += kuhn(i);
	}		
	
	return ans;
}

int calc(int v)
{
	int ans = 0;
	FOR(i, 1, n + 1)
	{
		if (i == v)
			continue;
		ans += !g[i].count(v);
		ans += !g[v].count(i);
	}

	ans += !g[v].count(v);
	FOR(i, 1, n + 1)
		graph[i].clear();
	
	int CNT = 0;
	FOR(i, 1, n + 1)
	{
		if (i == v)
			continue;
		
		for(auto j: g[i])
		{
			if (j == v)
				continue;
			graph[i].PB(j);
			++CNT;
		}
	}

	ans += n - 1 - matching() * 2 + CNT;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		g[u].insert(v);
	}

	int ans = INF;
	FOR(i, 1, n + 1)
		ans = min(ans, calc(i));
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}