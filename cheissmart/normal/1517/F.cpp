#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b?"true":"false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(V<bool> v) {
	string res;
	for(int i=0;i<(int)v.size();i++) res+=char('0'+v[i]);
	return res;
}
template<class T1, class T2> string to_string(pair<T1, T2> p) {return "(" + to_string(p.F) + ", " + to_string(p.S) + ")";}
template<size_t S> string to_string(bitset<S> b) {
	string res;
	for(int i=0;i<S;i++) res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    for(auto x:v){
		if(!f) res+=' ';
		f=0; res+=to_string(x);
	}
    return res;
}

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 303, M = 998244353, inv2 = (M + 1) / 2;

vi G[N];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

vi dp[N];
int n;
	
vi merge(vi a, vi b) {
	vi ans(2 * n + 1);
	{ // x >= 0, y >= 0 => max(x, y - 1)
		for(int x = 0, sum = b[n]; x <= n; x++) {
			// x >= y - 1
			if(x + 1 <= n) add(sum, b[n + x + 1]);
			add(ans[n + x], (ll) sum * a[n + x] % M);
		}
		for(int y = 1, sum = 0; y <= n; y++) {
			// x < y - 1
			add(ans[n + y - 1], (ll) sum * b[n + y] % M);
			add(sum, a[n + y - 1]);
		}
	}
	{ // x < 0, y < 0 => min(x, y - 1)
		for(int x = -1, sum = 0; x >= -n; x--) {
			// x <= y - 1
			if(x + 1 < 0) add(sum, b[n + x + 1]);
			add(ans[n + x], (ll) sum * a[n + x] % M);
		}
		for(int y = -1, sum = 0; y >= -n + 1; y--) {
			// x > y - 1
			add(sum, a[n + y]);
			add(ans[n + y - 1], (ll) sum * b[n + y] % M);
		}
	}
	{ // x >= 0, y < 0
		// x >= -y => x
		for(int x = 1, sum = 0; x <= n; x++) {
			add(sum, b[n - x]);
			add(ans[n + x], (ll) sum * a[n + x] % M);
		}
		// x < -y
		for(int y = -1, sum = 0; y >= -n + 1; y--) {
			add(sum, a[n - y - 1]);
			add(ans[n + y - 1], (ll) sum * b[n + y] % M);
		}
	}
	{ // x < 0, y >= 0
		// y >= -x
		for(int y = 1, sum = 0; y <= n; y++) {
			add(sum, a[n - y]);
			add(ans[n + y - 1], (ll) sum * b[n + y] % M);
		}
		// y < -x
		for(int x = -1, sum = 0; x >= -n; x--) {
			add(sum, b[n - x - 1]);
			add(ans[n + x], (ll) sum * a[n + x] % M);
		}
	}
	// for(int x = -n; x <= n; x++) {
	// 	for(int y = -n; y <= n; y++) {
	// 		int tt = (ll) a[n + x] * b[n + y] % M;
	// 		if(x >= 0 && y >= 0) add(ans[n + max(x, y - 1)], tt);
	// 		else if(x < 0 && y < 0) add(ans[n + min(x, y - 1)], tt);
	// 		else if(x + y >= 0) add(ans[n + max(x, y - 1)], tt);
	// 		else add(ans[n + min(x, y - 1)], tt);
	// 	}
	// }
	return ans;
}

void dfs(int u, int r, int p = -1) {
	dp[u] = vi(2 * n + 1);
	dp[u][n + r] = 1, dp[u][n - 1] = 1;
	for(int v:G[u]) if(v != p) {
		dfs(v, r, u);
		dp[u] = merge(dp[u], dp[v]);
	}
}

signed main()
{
	IO_OP;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int ans = n - 1, pre_ways = 1;
	for(int r = 0; r < n; r++) {
		// count the number of ways <= r
		dfs(1, r + 1);
		int ways = 0;
		for(int i = 0; i <= n; i++)
			add(ways, dp[1][n + i]);
		add(ans, (ll) (ways - pre_ways + M) % M * r % M);
		pre_ways = ways;
	}
	for(int i = 0; i < n; i++)
		ans = (ll) ans * inv2 % M;
	cout << ans << '\n';

}