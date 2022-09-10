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

const int MAX = 1 << 19;
int n, m, k;
vector<pair<int, PII>> g[MAX];
LL d[MAX];
int batya[MAX];

void dijkstra()
{
	FOR(i, 1, n)
		d[i] = LINF;
	
	set<pair<LL, int>> S;
	FOR(i, 0, n)
		S.insert(MP(d[i], i));
	
	while(SZ(S))
	{
		auto v = *S.begin();
		S.erase(v);
		
		for(auto i: g[v.Y])
			if (d[i.X] > i.Y.Y + d[v.Y])
			{
				S.erase(MP(d[i.X], i.X));
				d[i.X] = i.Y.Y + d[v.Y];
				batya[i.X] = v.Y;
				S.insert(MP(d[i.X], i.X));
			}
	}
}

vector<PII> graph[MAX];
VI ans;
char U[MAX];

void dfs(int v)
{	
	U[v] = 1;
	for(auto i: graph[v])
		if (!U[i.X] && k > 0)
		{
			--k;	
			ans.PB(i.Y + 1);
			dfs(i.X);
		}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m >> k;
	int u, v, w;
	FOR(i, 0, m)
	{
		cin >> u >> v >> w;
		--u; --v;
		g[u].PB(MP(v, MP(i, w)));
		g[v].PB(MP(u, MP(i, w)));
	}
	
	dijkstra();
	
	FOR(i, 1, n)
	{
		int b = batya[i];
		for(auto x: g[i])
			if (x.X == b)
			{
				graph[i].PB(MP(b, x.Y.X));
				graph[b].PB(MP(i, x.Y.X));
			}
	}
	
	dfs(0);
	cout << SZ(ans) << endl;
	sort(ALL(ans));
	for(auto i: ans)
		cout << i << " ";
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}