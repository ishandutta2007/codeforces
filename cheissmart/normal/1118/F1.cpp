#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[300005], r, b, ans;

vi G[300005];

pi dfs(int u, int p = -1) {
	int cr = 0, cb = 0;
	for(int v:G[u]) {
		if(v == p) continue;
		pi p = dfs(v, u);
		if((p.F == 0 && p.S == b) || (p.S == 0 && p.F == r)) 
			ans++;
		cr += p.F, cb += p.S;
	}
	if(a[u] == 1) cr++;
	if(a[u] == 2) cb++;
	return {cr, cb};
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i] == 1) r++;
		if(a[i] == 2) b++;
	}
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	cout << ans << endl;
}