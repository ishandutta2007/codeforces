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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace MaxFlow
{
	const int N = 1 << 21;
	struct edge
	{
		int to, cap, flow;
	};
	
	vector<edge> e;
	VI g[N];
	int ptr[N];
	int d[N];
	int n;
	int source;
	int sink;
	
	void add(int u, int v, int w)
	{
		g[u].PB(SZ(e));
		e.PB({v, w, 0});
		g[v].PB(SZ(e));
		e.PB({u, 0, 0});
	}
	
	bool bfs()
	{
		queue<int> q;
		FOR(i, 0, n) d[i] = -1;
		d[source] = 0;
		q.push(source);
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			
			for(auto i: g[v])
			{
				int to = e[i].to;
				if (d[to] == -1 && e[i].cap > e[i].flow)
					d[to] = d[v] + 1, q.push(to);
			}
		}
		
		return d[sink] != -1;
	}
	
	int dfs(int v, int flow)
	{
		if (!flow || v == sink) return flow;
		for(; ptr[v] < SZ(g[v]); ++ptr[v])
		{
			int id = g[v][ptr[v]];
			edge tut = e[id];
			if (d[tut.to] != d[v] + 1) continue;
			int push = dfs(tut.to, min(flow, tut.cap - tut.flow));
			if (!push) continue;
			e[id].flow += push;
			e[id ^ 1].flow -= push;
			return push;
		}
				
		return 0;
	}	
	
	LL dinic()
	{
		LL flow = 0;
		while(bfs())
		{
			FOR(i, 0, n) ptr[i] = 0;
			while(int push = dfs(source, INF))
				flow += push;
		}
		return flow;
	}
	
};

const int N = 1 << 20;
int n, m;
string s[N];
vector<vector<char>> used;

int dx[] = {0, 1};
int dy[] = {1, 0};

bool ok(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

int get(int x, int y)
{
	return x * m + y;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> s[i];
	
	MaxFlow::source = 0;
	MaxFlow::sink = get(n - 1, m - 1) * 2 + 1;
	MaxFlow::n = MaxFlow::sink + 1;
	
	FOR(i, 0, n)
		FOR(j, 0, m)
			MaxFlow::add(2 * get(i, j) + 1, 2 * get(i, j) , 1);
	
	FOR(i, 0, n)
		FOR(j, 0, m)
			FOR(k, 0, 2)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (!ok(x, y) || s[x][y] == '#')
					continue;
				
				MaxFlow::add(2 * get(i, j), 2 * get(x, y) + 1, 1);
			}	
	
	int ans = MaxFlow::dinic();
	assert(ans <= 2);
	cout << ans << endl;	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}