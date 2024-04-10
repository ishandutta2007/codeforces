/* 	* In the name of GOD  */

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200004;
int dp[N], root, h[N];
vector <int> g[N];

void dfs(int v, int p) {
	int cntb = 0;
	for (int u : g[v]) {
		if (u != p) {
			h[u] = h[v] + 1;
			dfs(u, v);
			dp[v] += dp[u];
			if (dp[u] == 0)
				cntb++;	
		}
	}
	if (cntb)
		dp[v] += cntb - 1;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++)
			dp[i] = 0, g[i].clear(), h[i] = 0;
		root = -1;
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
			if (g[x].size() >= 2)
				root = x;
			if (g[y].size() >= 2)
				root = y;
		}
		if (n <= 3) {
			cout << n - 1 << '\n';
			continue;
		}
		dfs(root, -1);
		int ans = dp[root];
		int mx = 0, in = -1;
		for (int i = 1; i <= n; i++) {
			if (h[i] > mx) {
				mx = h[i];
				in = i;
			}
		}
		for (int i = 0; i <= n; i++)
			dp[i] = 0, h[i] = 0;
		dfs(in, -1);
		ans = min(ans, dp[in]);
		for (int i = 1; i <= 50; i++) {
			int x = (rng() % n) + 1;
			root = x;
			for (int i = 0; i <= n; i++)
				dp[i] = 0, h[i] = 0;
			dfs(root, -1);
			ans = min(ans, dp[root]);
		}
		cout << ans + 1 << endl;
	}
}