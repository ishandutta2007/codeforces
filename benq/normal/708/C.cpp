#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;

set<pii> best[400001];
map<int,pii> adj[400001];
int done[400001],temp[400001],sz[400001],n;

pii dfs(int node, int par) {
	pii ans;
	int s = 0;
	if (done[node] == adj[node].size()) {
		pii x = adj[node][par]; // size of subtree, best
		ans = mp(n-x.f,0);
		if (2*ans.f<=n) ans.s = ans.f;
		else {
			auto x = best[node].begin();
			auto x1 = next(x);
			if ((*x1).s != par) ans.s = (*x1).f;
			else ans.s = (*x).f;
		}
		s = 1;
	} else if (done[node] == 0) {
		ans = mp(1,0);
		temp[node] = par;
		for (auto i: adj[node]) if (i.f != par) {
			pii x = dfs(i.f,node);
			adj[node][i.f] = x;
			best[node].insert(mp(x.s,i.f));
			if (best[node].size()>2) best[node].erase(best[node].begin());
			ans.f += x.f;
			ans.s = max(ans.s,x.s);
		}
		if (2*ans.f<=n) ans.s = ans.f;
		sz[node] = ans.f;
		done[node] = adj[node].size()-1;
		s = 2;
	} else {
		if (par == temp[node]) {
			s = 3;
			ans = mp(sz[node],(*prev(best[node].end())).f);
			if (sz[node]*2<=n)ans.s = sz[node];
		} else {
			int p = temp[node];
			pii x = dfs(p,node);
			adj[node][p] = x;
			if (best[node].size()<2) best[node].insert(mp(x.s,p));
			else if (*best[node].begin()<mp(x.s,p)) {
				best[node].erase(best[node].begin());
				best[node].insert(mp(x.s,p));
			}
			x = adj[node][par];
			ans = mp(n-x.f,0);
			if (2*ans.f <= n) ans.s = ans.f;
			else {
				auto x = best[node].begin();
				auto x1 = next(x);
				if ((*x1).s != par) ans.s = (*x1).f;
				else ans.s = (*x).f;
			}
			done[node] = adj[node].size();
			s = 4;
		}
	}
	// cout << s << " " << node << " " << par << " " << ans.f << " " << ans.s << "\n";
	return ans;
}

bool query(int node) {
	for (auto i: adj[node]) {
		pii x = dfs(i.f,node);
		if (2*(x.f-x.s)>n) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n-1) {
		int u,v; cin >> u >> v;
		adj[u][v] = mp(0,0);
		adj[v][u] = mp(0,0);
	}
	FOR(i,1,n+1) cout << query(i) << " ";
}