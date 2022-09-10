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
#define left fake_left

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

const int MAX = 1 << 20;
int n, m;
VI g[MAX];														
char used[MAX];
int tin[MAX];
int up[MAX];
int timer = 0;
int color[MAX];
int curr_color = 0;
int a, b;
VI heavy[MAX];
int has_heavy[MAX];
VI vec[MAX];

void dfs1(int v, int p = -1)
{
	used[v] = 1;
	tin[v] = up[v] = timer++;
	for(auto i: g[v])
	{
		if (i == p)
			continue;
		
		if (used[i])
			up[v] = min(up[v], tin[i]);
		else
		{
			dfs1(i, v);
			up[v] = min(up[v], up[i]);
		}		
	}
}

void dfs2(int v, int c)
{
	color[v] = c;
	vec[c].PB(v);
	for(auto i: g[v])
	{
		if (color[i])
			continue;
		if (up[i] > tin[v])
			dfs2(i, ++curr_color);
		else
			dfs2(i, c);
	}
}

VI graph[MAX];
int par[MAX];
map<PII, int> HEAVY;

void dfs3(int v, int p = -1)
{
	used[v] = 1;
	par[v] = p;
	for(auto i: graph[v])
		if (i != p && !used[i])
			dfs3(i, v);
}

bool is_heavy(int u, int v)
{
	return HEAVY.count(MP(u, v)) || HEAVY.count(MP(v, u));
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m;
	int w;
	while(m--)
	{
		cin >> a >> b >> w;
		--a; --b;
		g[a].PB(b);
		g[b].PB(a);
		if (!w)
			continue;
		heavy[a].PB(b);
		heavy[b].PB(a);
	}
	
	cin >> a >> b;
	--a; --b;
	
	FOR(i, 0, n)
		if (!used[i])
			dfs1(i);
	
	FOR(i, 0, n)
		if (!color[i])
			dfs2(i, ++curr_color);

	FOR(i, 1, curr_color + 1)
	{
		for(auto v: vec[i])
			for(auto u: heavy[v])
				if (color[u] == color[v])
				{
					has_heavy[i] = 1;
					break;
				}
	}
	
	FOR(i, 0, n)
		for(auto v: g[i])
			graph[color[v]].PB(color[i]), graph[color[v]].PB(color[i]); 
	
	FOR(i, 0, n)
		for(auto v: heavy[i])
			HEAVY[MP(color[v], color[i])] = 1;
	
	FILL(used, 0);
	dfs3(color[a]);

	VI path;
	int v = color[b];
	while(v != color[a])
	{
		path.PB(v);
		v = par[v];
	}
	
	path.PB(color[a]);
	bool ok = 0;
	for(auto i: path)
		if (has_heavy[i])
			ok = 1;
	FOR(i, 0, SZ(path) - 1)
		ok |= is_heavy(path[i], path[i + 1]);
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}