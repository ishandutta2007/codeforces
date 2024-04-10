#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
  
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
 
int m, par[300002][19], depth[300002], mx = 0;
set<int> s1, s2;
 
int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x,y);
    F0Rd(i,19) if (depth[x]-(1<<i) >= depth[y]) x = par[x][i];
    F0Rd(i,19) if (par[x][i] != par[y][i]) x = par[x][i], y = par[y][i];
    if (x != y) x = par[x][0];
    return x;
}
 
int dist(int x, int y) {
    return depth[x]+depth[y]-2*depth[lca(x,y)];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> m;
    depth[1] = 0; s1.insert(1);
    
    FOR(i,2,m+2) {
        int y; cin >> y;
        par[i][0] = y, depth[i] = depth[y]+1;
        FOR(j,1,19) par[i][j] = par[par[i][j-1]][j-1];
        
        int d1 = s1.size() ? dist(i,*s1.begin()) : 0;
        int d2 = s2.size() ? dist(i,*s2.begin()) : 0;
        
        if (max(d1,d2) > mx) {
            mx = max(d1,d2);
            if (d1 == mx) {
                for (int j: s2) if (dist(j,i) == mx) s1.insert(j);
                s2.clear();
                s2.insert(i);
            } else {
                for (int j: s1) if (dist(j,i) == mx) s2.insert(j);
                s1.clear();
                s1.insert(i);
            }
        } else if (max(d1,d2) == mx) {
            if (d1 == mx) s2.insert(i);
            else s1.insert(i);
        }
        /*for (int i: s1) cout << i << " ";
        cout << "\n";
        for (int i: s2) cout << i << " ";
        cout << "\n";*/
        cout << s1.size()+s2.size() << "\n";
        // cout << "--------\n";
    }
}
 
// read!
// ll vs. int!