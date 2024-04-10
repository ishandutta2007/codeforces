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

const int N = 1 << 19;
int n, m;
VI g[N];

vector<VI> comps;
VI comp;
int ans[N];
char u[N];

void dfs(int v)
{
	u[v] = 1;
	comp.PB(v);
	for(auto i: g[v])
		if (!u[i])
			dfs(i);
}

inline void add(int x, int y)
{
	g[x].PB(y);
	g[y].PB(x);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int k;
		cin >> k;
		VI tut(k);
		FOR(j, 0, k)
			cin >> tut[j];
		
		FOR(j, 1, k)
			add(tut[j] - 1, tut[j - 1] - 1);
	}
	
	FOR(i, 0, n)
		if (!u[i])
		{
			comp.clear();
			dfs(i);
			comps.PB(comp);
		}
	
	for(auto i: comps)
		for(auto j: i)
			ans[j] = SZ(i);
	
	FOR(i, 0, n)
		cout << ans[i] << ' ';
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}