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

int n, p[101];
double ans[101];
vector<pii> adj[101];
vector<pii> edge;
map<pii,int> m;

void dfs(int par, int node) {
    p[node] = par;
    double dif = 2.0/adj[node].size();
    double tim = ans[m[{par,node}]]+1;
    
    if (tim >= 2) tim -= 2;
    for (auto a: adj[node]) if (a.f != par) {
        tim += dif;
        if (tim >= 2) tim -= 2;
        ans[a.s] = tim;
        dfs(node,a.f);
    }
}

int main() {
    cin >> n;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        edge.pb({a,b});
        adj[a].pb({b,i});
        adj[b].pb({a,i});
        m[{a,b}] = m[{b,a}] = i;
    }
    
    dfs(0,1);
    cout << fixed << setprecision(9);
    cout << n-1 << "\n";
    F0R(i,n-1) {
        cout << 1 << " " << (i+1) << " ";
        if (p[edge[i].f] == edge[i].s) swap(edge[i].f,edge[i].s);
        if (ans[i] <= 1) cout << edge[i].s << " " << edge[i].f << " " << 1-ans[i];
        else cout << edge[i].f << " " << edge[i].s << " " << 2-ans[i];
        cout << "\n";
       //  cout << "HI " << ans[i] << "\n";
    }
}