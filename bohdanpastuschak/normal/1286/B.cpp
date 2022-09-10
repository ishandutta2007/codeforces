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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 11;
int n;
int c[N];
int p[N];
VI g[N];
int root;
int sz[N];
int ans[N];
vector<int> she;

void dfs_sz(int v)
{
	sz[v] = 1;
	for(auto i: g[v]) 
	{
		dfs_sz(i);
		sz[v] += sz[i];
	}
}

void dfs_ans(int v)
{
	assert(SZ(she) > c[v]);
	ans[v] = she[c[v]];
	FOR(i, c[v], SZ(she) - 1)
		swap(she[i], she[i + 1]);
	she.pop_back();
	for(auto i: g[v])
		dfs_ans(i);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> p[i] >> c[i];
		--p[i];
		if (p[i] < 0) root = i;
		else g[p[i]].PB(i);
	}
	
	dfs_sz(root);
	
	FOR(i, 0, n) if (c[i] >= sz[i])
	{
		cout << "NO\n";
		return 0;
	}
	
	FOR(i, 1, n + 1) she.PB(i);	
	dfs_ans(root);
	
	cout << "YES\n";
	FOR(i, 0, n) cout << ans[i] << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}