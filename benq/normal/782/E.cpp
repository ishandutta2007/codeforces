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

vi adj[200001], path;
int n,m,k, par[200001]; 

int getpar(int node) {
	if (par[par[node]] != par[node]) par[node] = getpar(par[node]);
	return par[node];
}

void unite(int x, int y) {
	x = getpar(x), y = getpar(y);
	par[y] = x;
}

void dfs(int par, int node) {
	path.pb(node);
	for (int i: adj[node]) if (i != par) {
		dfs(node,i);
		path.pb(node);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	FOR(i,1,n+1) par[i] = i;
	F0R(i,m) {
		int x,y; cin >> x >> y;
		if (getpar(x) != getpar(y)) {
			adj[y].pb(x);
			adj[x].pb(y);
			unite(x,y);
		}
	}
	dfs(0,1);
	int len = (2*n+k-1)/k;
	F0R(i,k) {
		vi z;
		for (int j = min(i*len,(int)path.size()-1); j < min(i*len+len,(int)path.size()); ++j) z.pb(path[j]);
		cout << z.size() << " ";
		for (int j: z) cout << j << " ";
		cout << "\n";
	}
}