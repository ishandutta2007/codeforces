#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n;
int a[N], b[N], c[N];
VI g[N];
LL ans;
int need1[N], need0[N];

void dfs_sz(int v, int p){
	
	if (b[v] != c[v]){
		if (b[v] == 0) need1[v]++;
		else need0[v]++;
	}
	
	if (p >= 0){
		setmin(a[v], a[p]);
	}
	
	for(auto i: g[v]) if (i != p){
		dfs_sz(i, v);
		need0[v] += need0[i];
		need1[v] += need1[i];
	}
	
	int mn = min(need0[v], need1[v]);
	need0[v] -= mn;
	need1[v] -= mn;
	ans += 2 * mn * (LL) a[v];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i] >> b[i] >> c[i];
	FOR(i, 0, n - 1){
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	dfs_sz(0, -1);
	if (need0[0] || need1[0]) ans = -1;
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}