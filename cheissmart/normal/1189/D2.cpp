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

vi G[1024];
vector<pair<pi, int>> e, ans, out;

int dfs(int u, int p) {
	for(int v:G[u])
		if(v != p)
			return dfs(v, u);
	return u;
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v, val;
		cin >> u >> v >> val;
		G[u].PB(v);
		G[v].PB(u);
		e.PB({{u, v}, val/2});
	}
	for(int i=1;i<=n;i++) {
		if(G[i].size() == 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(auto p:e) {
		int u = p.F.F, v = p.F.S, val = p.S;
		vi x, y;
		for(int w:G[u]) {
			if(x.size() == 2) break;
			if(w != v) x.PB(w);
		}
		for(int w:G[v]) {
			if(y.size() == 2) break;
			if(w != u) y.PB(w);
		}
		int a, b, c, d;
		a = b = u, c = d = v;
		if(x.size()) a = dfs(x[0], u), b = dfs(x[1], u);
		if(y.size()) c = dfs(y[0], v), d = dfs(y[1], v);
		
		ans.PB({{a, c}, val});
		ans.PB({{b, d}, val});
		ans.PB({{a, b}, -val});
		ans.PB({{c, d}, -val});
	}
	for(auto p:ans) {
		if(p.F.F != p.F.S)
			out.PB(p);
	}
	cout << out.size() << endl;
	for(auto p:out)
		cout << p.F.F << " " << p.F.S << " " << p.S << endl;

}