#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

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

const int INF = 1e9 + 7, N = 20000;

namespace AC {

int t[N][12], ac[N][12], val[N], f[N];
int cnt = 1;

void add(string s, int cost) {
	int u = 0;
	for(char c:s) {
		int cc = c - 'a';
		if(t[u][cc] == 0) t[u][cc] = cnt++;
		u = t[u][cc];
	}
	val[u] += cost;
}

void build() {
	queue<int> q({0});
	while(q.size()) {
		int u = q.front(); q.pop();
		val[u] += val[f[u]];
		for(int c = 0; c < 12; c++) {
			int v = t[u][c];
			if(v) {
				q.push(v);
				f[v] = ac[f[u]][c];
				ac[u][c] = v;
			} else {
				ac[u][c] = ac[f[u]][c];
			}
		}
	}
}

}

using namespace AC;

int dp[1 << 12][N];
pi from[1 << 12][N];

void cmax(int& a, int b) {
	a = max(a, b);
}

string go(string s) {
	bool adj[12][12] = {};
	bool has[12] = {};
	for(int c:s) has[c - 'a'] = 1;
	for(int i = 0; i < SZ(s) - 1; i++) {
		int u = s[i] - 'a', v = s[i + 1] - 'a';
		adj[u][v] = adj[v][u] = 1;
	}
	int ecnt = 0, vcnt = 0;
	for(int u = 0; u < 12; u++) {
		for(int v = 0; v < u; v++)
			ecnt += adj[u][v];
		vcnt += has[u];
	}
	if(ecnt != vcnt - 1) return "";

	int r = -1;
	for(int u = 0; u < 12; u++) {
		int hebe = 0;
		for(int v = 0; v < 12; v++)
			hebe += adj[u][v];
		if(hebe > 2) return "";
		if(hebe == 1)
			r = u;
	}
	assert(r != -1);
	string ans;
	while(r != -1) {
		ans += 'a' + r;
		has[r] = false;
		int tt = -1;
		for(int u = 0; u < 12; u++) {
			if(adj[r][u] && has[u]) {
				tt = u;
			}
		}
		r = tt;
	}
	return ans;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int c;
		string s;
		cin >> c >> s;
		string t = go(s);
		if(SZ(t)) {
			add(t, c);
			reverse(ALL(t));
			add(t, c);
		}
	}
	build();

	memset(dp, -1, sizeof dp);

	dp[0][0] = 0;
	for(int mask = 0; mask < (1 << 12); mask++) {
		for(int s = 0; s < cnt; s++) if(dp[mask][s] >= 0) {
			for(int c = 0; c < 12; c++) if(!(mask >> c & 1)) {
				// cmax(dp[mask | (1 << c)][ac[s][c]], dp[mask][s] + val[ac[s][c]]);
				if(dp[mask | (1 << c)][ac[s][c]] < dp[mask][s] + val[ac[s][c]]) {
					dp[mask | (1 << c)][ac[s][c]] = dp[mask][s] + val[ac[s][c]];
					from[mask | (1 << c)][ac[s][c]] = {c, s};
				}
			}
		}
	}
	int hebe = 0;
	for(int s = 0; s < cnt; s++) if(dp[(1 << 12) - 1][s] > dp[(1 << 12) - 1][hebe])
		hebe = s;

	int mask = (1 << 12) - 1;
	string ans;
	for(int i = 0; i < 12; i++) {
		int c = from[mask][hebe].F;
		ans += 'a' + c;
		mask ^= 1 << c;
		hebe = from[mask ^ (1 << c)][hebe].S;
	}
	reverse(ALL(ans));
	assert(hebe == 0 && mask == 0);

	cout << ans << '\n';
}