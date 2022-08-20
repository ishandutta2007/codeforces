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

int n, sub[200001], par[200001], cen = 1;
vi adj[200001];
vector<pair<int,pii>> ans;

void dfs(int node) {
    sub[node] = 1;
    for (int i: adj[node]) if (i != par[node]) {
        par[i] = node;
        dfs(i);
        sub[node] += sub[i];
    }
}

vi todo;

void dfs1(int node, int dist) {
    if (dist > 1) todo.pb(node);
    for (int i: adj[node]) if (i != par[node]) {
        par[i] = node;
        dfs1(i,dist+1);
    }
}

void solve(int p, int node) {
    par[node] = p;
    dfs1(node,0);
    int pre = node;
    for (int i: todo) {
        ans.pb({p,{pre,i}});
        ans.pb({i,{par[i],node}});
        pre = i;
    }
    todo.clear();
    ans.pb({p,{pre,node}});
}

int main() {
    cin >> n; 
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    
    dfs(1);
    while (1) {
        bool f = 0;
        for (int i: adj[cen]) if (i != par[cen] && 2*sub[i] > n) {
            cen = i;
            f = 1;
            break;
        }
        if (!f) break;
    } 
    par[cen] = 0; dfs(cen);
    
    for (int i: adj[cen]) if (2*sub[i] < n) solve(cen,i); // OK
    for (int i: adj[cen]) if (2*sub[i] == n) {
        int cen1 = i;
        for (int j: adj[cen1]) if (j != cen) solve(cen1,j);
        break;
    }
    cout << ans.size() << "\n";
    for (auto a: ans) cout << a.f << " " << a.s.f << " " << a.s.s << "\n";
}

// read!
// ll vs. int!