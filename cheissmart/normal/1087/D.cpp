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

vector<pair<int, double>> G[100001];
vector<pi> ve;

bool dfs(int u, int p) {
	for(int i=0;i<G[u].size();i++) {
		int v = G[u][i].F;
		if(v == p) continue;
		if(dfs(v, u)) {
			ve.PB({u, i});
		}
	}
	if(G[u].size() == 1) {
		ve.PB({u, 0});
		return true;
	}
	return false;
}
pair<int, double> dfs1(int u, int p) {
	double d = 0;
	int mxv = u;
	for(int i=0;i<G[u].size();i++) {
		int v = G[u][i].F;
		if(v == p) continue;
		auto aaa = dfs1(v, u);
		double tmp = aaa.S;
		int nv = aaa.F;
		if(tmp+G[u][i].S > d) {
			d = tmp+G[u][i].S;
			mxv = nv;
		}
	}
	return {mxv, d};
	
}

double dfs2(int u, int p) {
	double d = 0;
	for(int i=0;i<G[u].size();i++) {
		int v = G[u][i].F;
		if(v == p) continue;
		d = max(d, dfs2(v, u)+G[u][i].S);
	}
	return d;
}

int main()
{
	IO_OP;
	
	int n, s;
	cin >> n >> s;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB({v, 0});
		G[v].PB({u, 0});
	}
	if(n <= 3) {
		cout << fixed << setprecision(20) << 1.0*s << endl;
		return 0;
	}
	int rt;
	for(int i=0;i<n;i++) {
		if(G[i].size() >= 2) {
			rt = i;
			break;
		}
	}
	dfs(rt, -1);

	for(pi p:ve)
		G[p.F][p.S].S = 1.0*2*s/ve.size();
		
	int nrt = dfs1(rt, -1).F;

	cout << fixed << setprecision(20) << dfs2(nrt, -1) << endl;
}