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

int n,m, ans=0, col[300001];
vi cream[300001], adj[300001];

void dfs(int par, int node) {
	vi todo, cur;
	
	for (int a: cream[node]) 
		if (col[a] > 0) cur.pb(col[a]);
		else todo.pb(a);
	sort(cur.begin(),cur.end());
	
	int lst = 0;
	F0R(i,cur.size()) {
		if (todo.size() == 0) break;
		FOR(j,lst+1,cur[i]) {
			if (todo.size() == 0) break;
			col[todo[todo.size()-1]] = j;
			todo.erase(todo.begin()+todo.size()-1);
		}
		lst = cur[i];
	}
	int sta = 1;
	if (cur.size()) sta = cur[cur.size()-1]+1;
	
	FOR(j,sta,MOD) {
		if (todo.size() == 0) break;
		col[todo[todo.size()-1]] = j;
		todo.erase(todo.begin()+todo.size()-1);
	}
	
	for (int a: adj[node]) if (a != par) dfs(node,a);
}

int main() {
	cin >> n >> m;
	FOR(i,1,n+1) {
		int s; cin >> s; cream[i].resize(s);
		F0R(j,s) cin >> cream[i][j];
		ans = max(ans,s);
	}
	F0R(i,n-1) {
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(0,1);
	ans = max(ans,1);
	cout << ans << "\n";
	FOR(i,1,m+1) {
		if (col[i] == 0) col[i] = 1;
		cout << col[i] << " ";
	}
}