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

int depth[100001], numvisit;
vi a1[100001], a2[100001], a3[100001];
bool visit1[100001], visit2[100001];
set<pii> edge;

void dfs(int par, int node) {
	depth[node] = depth[par]+1;
	for (int i: a1[node]) if (depth[i] == 0) {
		a2[node].pb(i);
		a3[i].pb(node);
		edge.insert(mp(min(node,i),max(node,i)));
		dfs(node,i);
	}
}

void dfs1(int node) {
	numvisit++;
	visit1[node] = 1;
	for (int i: a2[node]) if (!visit1[i]) dfs1(i);
}

void dfs2(int node) {
	numvisit++;
	visit2[node] = 1;
	for (int i: a3[node]) if (!visit2[i]) dfs2(i);
}

int main() {
	int n,m; cin >> n >> m;
	F0R(i,m) {
		int v1, v2; cin >> v1 >> v2;
		a1[v1].pb(v2);
		a1[v2].pb(v1);
	}
	dfs(0,1);
	FOR(i,1,n+1) for (int j: a1[i]) if (i<j) if (edge.find(mp(i,j)) == edge.end()) {
		if (depth[i] < depth[j]) a2[j].pb(i), a3[i].pb(j);
		else a2[i].pb(j), a3[j].pb(i);
	}
	dfs1(1);
	if (numvisit != n) {
		cout << 0;
		return 0;
	}
	numvisit = 0;
	dfs2(1);
	if (numvisit != n) {
		cout << 0;
		return 0;
	}
	FOR(i,1,n+1) for (int j: a2[i]) cout << i << " " << j << "\n";
}