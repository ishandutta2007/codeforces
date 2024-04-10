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

const int N = 1 << 17;
int n;
VI g[N];
int a[N];
LL ans[N];
map<int, int> mp[N];
int mx_cnt[N];
int id[N];

void dfs(int v, int p)
{
	int mx_id = -1;
	id[v] = v;
	for(auto i: g[v]) if (i != p) 
	{
		dfs(i, v);
		if (SZ(mp[id[i]]) > SZ(mp[id[mx_id]]))
			mx_id = i;
	}
	
	if (mx_id == -1)
	{
		mp[v][a[v]]++;
		ans[v] = a[v];
		mx_cnt[v] = 1;
		return;
	}
	
	id[v] = id[mx_id];
	mx_cnt[v] = mx_cnt[mx_id];
	ans[v] = ans[mx_id];
	
	for(auto i: g[v]) if (i != p && i != mx_id)
	{
		for(auto j: mp[id[i]])
		{
			mp[id[v]][j.X] += j.Y;
			if (mp[id[v]][j.X] == mx_cnt[v])
			{
				ans[v] += j.X;
				continue;
			}
			
			if (mp[id[v]][j.X] > mx_cnt[v])
			{
				ans[v] = j.X;
				mx_cnt[v] = mp[id[v]][j.X];
			}
		}
	}
	
	mp[id[v]][a[v]]++;
	if (mp[id[v]][a[v]] == mx_cnt[v])
		ans[v] += a[v];
	
	if (mp[id[v]][a[v]] > mx_cnt[v])
	{
		mx_cnt[v] = mp[id[v]][a[v]];
		ans[v] = a[v];
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	dfs(0, -1);		
	FOR(i, 0, n) cout << ans[i] << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}