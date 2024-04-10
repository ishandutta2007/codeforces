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

const int N = 1 << 18;
int n, m, k;
vector<PII> g[N];
int r[N];
LL d[N];
int mn[N];
bool treba[N];
bool used[N];
char keks[N];

void dijkstra()
{
	set<pair<LL, int>> s;
	FOR(i, 0, n)
		s.insert({d[i], i});
		
	FOR(i, 1, n)
		if (mn[i] != -1)
			s.insert({mn[i], INF - i});
			
	while(SZ(s))
	{
		int v = s.begin()->Y;
		s.erase(s.begin());
		
		if (v > N)
		{
			v = INF - v;
			if (used[v])	
				continue;
			
			s.erase({d[v], v});
			d[v] = mn[v];
			treba[v] = 1;
			assert(r[v]);
		}
		
		used[v] = 1;
		for(auto i: g[v])
			if (d[i.X] > d[v] + i.Y)
			{
				s.erase({d[i.X], i.X});
				d[i.X] = d[v] + i.Y;
				s.insert({d[i.X], i.X});
			}	
	}	
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m >> k;
	FOR(i, 0, m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u; -- v;
		g[u].PB({v, w});
		g[v].PB({u, w});
	}
	
	FOR(i, 1, n)
		d[i] = LINF;
	
	FILL(mn, -1);	
	FOR(i, 0, k)
	{
		int u, w;
		cin >> u >> w;
		--u;
		if (mn[u] == -1)
			mn[u] = w;
		else
			mn[u] = min(mn[u], w);
		r[u]++;
	}	
	
	dijkstra();
	
	int ans = 0;
	FOR(i, 1, n)
		ans += r[i] - treba[i];
		
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}