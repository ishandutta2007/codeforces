/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<ll> adj[100001], dist[100001], sum[100001];
int par[100001], dia[100001], sz[100001];
multiset<int> child[100001];
map<pii,double> done;

void dfs(int pre, int cur) { // compute diameter as well as max dist
	par[cur] = par[pre];
	sz[par[cur]] ++;
	
	child[cur].insert(0);
	for (int a: adj[cur]) if (a != pre) {
		dfs(cur,a);
		child[cur].insert(*prev(child[a].end())+1);
		dia[par[cur]] = max(dia[par[cur]], *prev(prev(child[cur].end()))+*prev(child[cur].end()));
	}
}

void dfs2(int pre, int cur) {
	if (pre != cur) {
		int temp = (*prev(child[cur].end()))+1;
		child[pre].erase(child[pre].find(temp));
		child[cur].insert((*prev(child[pre].end()))+1);
		child[pre].insert(temp);
	}
	dist[par[cur]].pb(*prev(child[cur].end()));
	for (int a: adj[cur]) if (a != pre) dfs2(cur,a);
}

double query(int u, int v) {
	ll maxdia = max(dia[u],dia[v]);
	double ans = 0;
	
	for (int a: dist[u]) {
		ll lo = -1, hi = (int)dist[v].size()-1;
		while (lo < hi) {
			int mid = (lo+hi+1)/2;
			if (a+dist[v][mid]+1 > maxdia) lo = mid;
			else hi = mid-1;
		}
		ans += (a+1)*(lo+1);
		ans += sum[v][lo+1]; // something wrong w/ this
		ans += ((int)dist[v].size()-lo-1)*maxdia;
	}
	ans /= sz[u];
	ans /= sz[v];
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,q; cin >> n >> m >> q;
	F0R(i,m) {
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	FOR(i,1,n+1) if (par[i] == 0) {
		par[i] = i;
		dfs(i,i);
		dfs2(i,i);
		
		sort(dist[i].begin(),dist[i].end());
		reverse(dist[i].begin(),dist[i].end());
		
		sum[i].pb(0);
		F0R(j,dist[i].size()) sum[i].pb(sum[i][j]+dist[i][j]);
	}
	
	F0R(i,q) {
		int u,v; cin >> u >> v;
		u = par[u], v = par[v];
		if (sz[u] > sz[v] || (sz[u] == sz[v] && u > v)) swap(u,v);
		if (u == v) {
			cout << -1 << "\n";
			continue;
		} 
		if (done.find({u,v}) == done.end()) done[{u,v}] = query(u,v);
		cout << fixed << setprecision(9) << done[{u,v}] << "\n";
	}
}