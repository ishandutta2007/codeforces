#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

vi G[1024];
bool vis1[1024], vis2[1024];
int nxt[1024];

pi dfs1(int u) {
	int mx = -1, ans = u;
	vis1[u] = 1;
	for(int v:G[u]) {
		if(vis1[v]) continue;
		pi c = dfs1(v);
		if(c.F > mx) {
			mx = c.F;
			ans = c.S;
		}
	}
	return {mx + 1, ans};
}

int dfs2(int u) {
	int mx = -1, mxv = u;
	vis2[u] = 1;
	for(int v:G[u]) {
		if(vis2[v]) continue;
		int c = dfs2(v);
		if(c > mx) {
			mxv = v;
			mx = c;
		}
	}
	nxt[u] = mxv;
	return mx + 1;
}

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB(v);
		G[v].PB(u);
	}
	vector<pi> v;
	for(int i=0;i<n;i++) {
		if(vis1[i]) continue;
		int u = dfs1(i).S;
		int d = dfs2(u);
		for(int j=0;j<d/2;j++)
			u = nxt[u];
		v.PB({d, u});
	}
	sort(v.begin(), v.end());
	vector<pi> ans;
	for(int i=0;i<v.size()-1;i++) {
		int u = v[i].S, w = v.back().S;
		G[u].PB(w);
		G[w].PB(u);
		ans.PB({u, w});
	}
	for(int i=0;i<n;i++) {
		vis1[i] = vis2[i] = 0;
	}
	int u = dfs1(0).S;
	int d = dfs2(u);
	cout << d << endl;
	for(pi pp:ans)
		cout << pp.F+1 << " " << pp.S+1 << endl;
}