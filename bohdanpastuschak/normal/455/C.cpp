#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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

const int N = 1 << 19;
int n;
int p[N];
int ans[N];
int l[N];
int r[N];
VI g[N];

int find(int x)
{
	if (p[x] == x)
		return x;
		
	return find(p[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	
	if (l[x] + r[x] < l[y] + r[y])
		swap(x, y);
	
	p[y] = x;
	
	if (l[x] > r[x])
		swap(l[x], r[x]);
	if (l[y] > r[y])
		swap(l[y], r[y]);
	
	l[x] = max(l[x], r[y] + 1);	
	ans[x] = l[x] + r[x];
}

char u[N];

vector<int> comp;

void dfs(int v)
{
	u[v] = 1;
	comp.PB(v);
	for(auto i: g[v])
		if (!u[i])
			dfs(i);
}

int id(int x)
{
	return lower_bound(ALL(comp), x) - comp.begin();
}

void bfs(int v, vector<int>& dist, vector<int>& batya)
{
	dist.assign(SZ(dist), -1);
	dist[v] = 0;
	queue<int> q;
	q.push(v);
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		
		for(auto i: g[comp[v]])	
		{
			int I = id(i);
			if (dist[I] == -1)
			{
				dist[I] = dist[v] + 1;
				q.push(I);
				batya[I] = v;
			}
		}
	}	
}

void solve()
{
	int k = SZ(comp);
	sort(ALL(comp));
	
	vector<int> dist(k, 0);
	vector<int> batya(k, 0);
	
	bfs(0, dist, batya);
	int mx = 0;
	FOR(i, 1, k)
		if (dist[mx] < dist[i])
			mx = i;
	
	bfs(mx, dist, batya);
	int nmx = 0;
	FOR(i, 1, k)
		if (dist[nmx] < dist[i])
			nmx = i;
	
	int BATKO = nmx;
	int DI = dist[nmx];
	FOR(it, 0, DI / 2)
		BATKO = batya[BATKO];
	
	BATKO = comp[BATKO];
	r[BATKO] = DI / 2;
	l[BATKO] = (DI + 1) / 2;
	for(auto i: comp)
		p[i] = BATKO;
	ans[BATKO] = DI;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int m, q;
	cin >> n >> m >> q;
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		g[a].PB(b);
		g[b].PB(a);		
	}
	
	FOR(i, 1, n + 1)
	{
		if (u[i])	
			continue;
		
		comp.clear();
		dfs(i);
		solve();
	}
	
	while(q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x;
			cin >> x;
			cout << ans[find(x)] << endl;
		}
		else
		{
			int x, y;
			cin >> x >> y;
			unite(x, y);
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}