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

vi adj[1000001];
int root, stor[1000001], n,q, gmin = MOD, lst = 0;

void dfs(int par, int node) {
	stor[node] = min(stor[par],node);
	for (int i: adj[node]) if (i != par) dfs(node,i);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	F0R(i,n-1) {
		int x,y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	F0R(i,q) {
		int t; cin >> t;
		int z; cin >> z;
		int x = (z+lst) % n + 1;
		if (i == 0) {
			root = x;
			stor[root] = MOD;
			dfs(root,root);
			gmin = min(gmin,root);
		} else if (t == 1) {
			gmin = min(gmin,stor[x]);
		} else if (t == 2) {
			cout << min(gmin,stor[x]) << "\n";
			lst = min(gmin,stor[x]);
		}
	}
}