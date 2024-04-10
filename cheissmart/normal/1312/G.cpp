#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e6 + 7;

V<pair<char, int>> G[N];
bool ok[N];
int dp[N], a[N], add;
vi v;

void dfs(int u, int p = -1) {
	if(p != -1) {
		dp[u] = dp[p] + 1;
	}
	if(ok[u]) dp[u] = min(dp[u], v.back() + add);
	v.PB(dp[u] + 1 - add);
	if(v.size() >= 2) {
		v[v.size()-1] = min(v[v.size()-1], v[v.size()-2]);
	}
	if(ok[u]) {
		add++;
	}
	sort(ALL(G[u]));
	for(pi t:G[u])
		dfs(t.S, u);
	v.pop_back();
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		int p;
		char c;
		cin >> p >> c;
		G[p].EB(c, i);
	}
	int k;
	cin >> k;
	for(int i=0;i<k;i++) {
		cin >> a[i];
		ok[a[i]] = true;
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	dfs(0);
	for(int i=0;i<k;i++) 
		cout << dp[a[i]] << " ";
}