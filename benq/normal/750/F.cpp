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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

int T, H, ans;
set<int> adj[128];

void fin() {
    cout << "! " << ans << endl;
} // OK

void query(int x) {
    cout << "? " << x << endl;
    int k; cin >> k;
    F0R(i,k) {
        int z; cin >> z;
        adj[x].insert(z);
        adj[z].insert(x);
    }
} // OK

void sol(int chi, int cur, int lev); // OK

void findLeaf(int chi, int cur, int lev) {
    int CHI = chi, CUR = cur; vi tmp;
    
    while (1) {
        tmp.pb(CUR);
        bool f = 0;
        for (int i: adj[CUR]) if (i != CHI) {
            query(i);
            if (sz(adj[i]) == 2) { ans = i; fin(); return; }
            CHI = CUR; CUR = i; 
            f = 1; break;
        }
        if (!f) break;
    }
    
    set<int> m; m.insert(chi); for (int i: tmp) m.insert(i);
    int t = (sz(tmp)-1+lev-H)/2;
    int par = 0; 
    for (int i: adj[tmp[t]]) if (!m.count(i)) par = i;
    
    sol(tmp[t],par,lev-t-1);
}

void sol(int chi, int cur, int lev) {
    if (lev == 1) { ans = cur; fin(); return; }
    
    query(cur);
    vi z; for (int i: adj[cur]) if (i != chi) z.pb(i);
    
    if (lev == 2) { 
        query(z[0]);
        if (sz(adj[z[0]]) == 2) { ans = z[0]; fin(); }
        else { ans = z[1]; fin(); }
        return;
    } else if (lev == 3) { 
        query(z[0]);
        for (int i: adj[z[0]]) if (i != cur) {
            query(i);
            if (sz(adj[i]) == 2) { ans = i; fin(); return; }
        }
        query(z[1]);
        vi Z; for (int i: adj[z[1]]) if (i != cur) Z.pb(i);
        query(Z[0]);
        if (sz(adj[Z[0]]) == 2) ans = Z[0]; 
        else ans = Z[1]; 
        
        fin(); return;
    } else findLeaf(chi,cur,lev);
} // OK

vi get(int pre, int nex) {
    if (ans) return {};
    query(nex);
    if (sz(adj[nex]) == 2) { ans = nex; fin(); return {}; }
    for (int i: adj[nex]) if (i != pre) {
        vi tmp = get(nex,i); tmp.insert(tmp.begin(),nex);
        return tmp;
    }
    return {nex};
} // OK

void start() {
    query(1);
    if (sz(adj[1]) == 2) { ans = 1; fin(); return; }
    if (sz(adj[1]) == 1) { sol(1,*adj[1].begin(),H-1); return; }
    
    // find two roots and begin
    vi a = get(1,*adj[1].begin()), b = get(1,*next(adj[1].begin()));
    if (ans) return;
    reverse(a.begin(),a.end());
    a.pb(1); for (int i: b) a.pb(i);
    
    set<int> m; for (int i: a) m.insert(i);
    int par = 0;
    for (int i: adj[a[sz(a)/2]]) if (!m.count(i)) par = i;
    
    sol(a[sz(a)/2],par,H-1-sz(a)/2);
} // OK

void solve() {
    ans = 0; 
    F0R(i,128) adj[i].clear(); 
    cin >> H;
    start();
} // OK

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> T;
	F0R(i,T) solve();
} // OK

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!