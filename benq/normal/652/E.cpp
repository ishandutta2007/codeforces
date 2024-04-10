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

int n,m, disc[300001], low[300001],cur,a,b;
int pre[300001],visit[300001];
int par[300001], sz[300001];
vi adj[300001];
vector<pair<pii,int>> edge;
set<pii> bridge, arti;

// first determine bridges
// next find path from start to end
// profit!

void input() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,m) {
		int x,y,z; cin >> x >> y >> z;
		adj[x].pb(y);
		adj[y].pb(x);
		edge.pb({{x,y},z});
		if (z) {
			arti.insert({x,y});
			arti.insert({y,x});
		}
	}
	cin >> a >> b;
}

int getpar(int a) {
	if (par[par[a]] != par[a]) par[a] = getpar(par[a]);
	return par[a];
}

void unite(int a, int b) {
	a = getpar(a), b = getpar(b);
	if (sz[a] < sz[b]) swap(a,b);
	par[b] = a;
	sz[a] = max(sz[a],sz[b]+1);
}

void dfs(int par, int node) {
	disc[node] = low[node] = cur++;
	for (int i: adj[node]) if (i != par) {
		if (!disc[i]) {
			dfs(node,i);
			low[node] = min(low[node],low[i]);
			if (disc[node] < low[i]) {
				bridge.insert({node,i});
				bridge.insert({i,node});
			}
		} else low[node] = min(low[node],low[i]);
	}
}

void dfs1(int node) {
	visit[node] = 1;
	for (int x: adj[node]) if (!visit[x]) {
		pre[x] = node;
		dfs1(x);
	}
}

int main() {
	input();
	dfs(1,1);
	dfs1(a);
	
	vi comp; comp.pb(b);
	int cur = b;
	while (b != a) {
		int b1 = pre[b];
		if (bridge.find({b,b1}) != bridge.end()) {
			if (arti.find({b,b1}) != arti.end()) {
				cout << "YES";
				return 0;
			}
			comp.pb(b1);
		}
		b = b1;
	}
	FOR(i,1,n+1) adj[i].clear(); 
	FOR(i,1,n+1) par[i] = i, sz[i] = 1;
	for (auto a: edge) if (bridge.find(a.f) == bridge.end()) unite(a.f.f,a.f.s);
	map<int,int> z;
	F0R(i,comp.size()) z[getpar(comp[i])] = 1;
	
	for (auto a: edge) if (getpar(a.f.f) == getpar(a.f.s))
		if (z[getpar(a.f.f)] == 1)
			if (arti.find(a.f) != arti.end()) {
				cout << "YES";
				return 0;
			}
	cout << "NO";
}