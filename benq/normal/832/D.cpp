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
const int MAXK = 20;

int n,q, parK[100001][MAXK], depth[100001];
vi adj[100001];

int lca(int u, int v){
  int k = MAXK-1;
  while(k>=0){
    int d = 1<<k;
    if(depth[u]>=depth[v]+d) u=parK[u][k];
    if(depth[v]>=depth[u]+d) v=parK[v][k];
    k--;
  }
  k = MAXK-1;
  while(k>=0){
    if(parK[u][k] != parK[v][k]){
      u = parK[u][k];
      v = parK[v][k];
    }
    k--;
  }
  if(u != v){
    u = parK[u][0];
    v = parK[v][0];
  }
  return u;
}

int query(int a, int b, int c) {
    if (lca(a,b) == a) {
        if (lca(a,c) != a) return 1;
        else {
            return depth[lca(b,c)]-depth[a]+1;
        }
    } else {
        if (lca(a,c) != a) {
            int l1 = lca(a,c), l2 = lca(a,b);
            if (l1 == l2) return depth[a]-depth[l1]+1+depth[lca(b,c)]-depth[l1];
            else {
                if (depth[l1] < depth[l2]) swap(l1,l2);
                return depth[a]-depth[l1]+1;
            }
        } else return 1;
    }
    // both b and c above a -->
    // both b and c below a --> compute LCA 
    // b above a, c above a
}

void dfs(int u, int prev){
  depth[u] = depth[prev]+1;
  parK[u][0] = prev;
  for (int v: adj[u]) if (v != prev) dfs(v, u);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	FOR(i,2,n+1) {
	    int y; cin >> y;
	    adj[i].pb(y);
	    adj[y].pb(i);
	}
	dfs(1,0);
	
	FOR(i,1,20) FOR(j,1,n+1) parK[j][i] = parK[parK[j][i-1]][i-1];
	
	F0R(i,q) {
	    int a,b,c; cin >> a >> b >> c;
	    //cout << query(a,b,c) << " " << query(b,a,c) << " " << query(c,a,b) << "\n";
	    cout << max(max(query(a,b,c),query(b,a,c)),query(c,a,b)) << "\n";
	}
}