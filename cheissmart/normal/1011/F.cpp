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

const int INF = 1e9 + 7;

string tp[1000006];
int state[1000006], dp[1000006][2];
vi G[1000006];
vi in;
int p[1000006];

bool go(int u, bool x, bool y = 1) {
	if(tp[u] == "AND") return x & y;
	if(tp[u] == "OR") return x | y;
	if(tp[u] == "XOR") return x ^ y;
	if(tp[u] == "NOT") return !x;
}

void dfs(int u) {
	for(int v:G[u]) dfs(v);
	if(G[u].size() == 2)
		state[u] = go(u, state[G[u][0]], state[G[u][1]]);
	if(G[u].size() == 1)
		state[u] = go(u, state[G[u][0]]);
}

void dfs1(int u) {
	if(u != 1) {
		for(int i=0;i<2;i++) {
			int pa = p[u];
			bool ps;
			if(G[pa].size() == 2) ps = go(pa, i, state[G[pa][0] ^ G[pa][1] ^ u]);
			if(G[pa].size() == 1) ps = go(pa, i);
			dp[u][i] = dp[pa][ps];
		}
	}
	for(int v:G[u]) dfs1(v);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> tp[i];
		if(tp[i] == "IN") {	
			cin >> state[i];
			in.PB(i);
		}
		else if(tp[i] != "NOT") {
			int u, v;
			cin >> u >> v;
			p[u] = p[v] = i;
			G[i].PB(u);
			G[i].PB(v);
		} else {
			int u;
			cin >> u;
			p[u] = i;
			G[i].PB(u);
		}
	}
	dfs(1);
	dp[1][1] = 1, dp[1][0] = 0;
	dfs1(1);
	for(int u:in)
		cout << dp[u][!state[u]];
}