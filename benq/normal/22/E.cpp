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

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (x == y) return 0;
    	if (sz[x] < sz[y]) swap(x,y);
    	sz[x] += sz[y], par[y] = x;
    	return 1;
    }
};

const int MX = 100001;

DSU<MX> D;

int T,N,M, deg1[MX], deg2[MX], visit[MX], scc[MX];
vi adj[MX], radj[MX], L;
vi n1[MX], n2[MX];

void dfs(int x) {
    visit[x] = 1;
    for (int i: adj[x]) if (!visit[i]) dfs(i);
    L.pb(x);
}

void dfs1(int x, int num) {
    if (scc[x]) return;
    scc[x] = num;
    for (int i: radj[x]) dfs1(i,num);
}

void solve() {
    cin >> N;
    FOR(i,1,N+1) {
        adj[i].clear(), radj[i].clear();
        visit[i] = deg1[i] = deg2[i] = scc[i] = 0;
    }
    L.clear();
    FOR(A,1,N+1) {
        int B; cin >> B;
        adj[A].pb(B), radj[B].pb(A);
        D.unite(A,B);
    }
    FOR(i,1,N+1) if (!visit[i]) dfs(i);
    reverse(L.begin(),L.end());
    for (int i: L) dfs1(i,i);
    FOR(i,1,N+1) for (int j: adj[i]) if (scc[i] != scc[j]) {
        deg1[scc[i]] ++;
        deg2[scc[j]] ++;
    }
    
    int ans1 = 0, ans2 = 0, num = 0;
    FOR(i,1,N+1) if (i == scc[i]) {
        if (!deg1[i]) { // none out
            ans1++;
            n1[D.get(i)].pb(i);
        }
        if (!deg2[i]) { // none in
            ans2++;
            n2[D.get(i)].pb(i);
        }
        num++;
    }
    if (num == 1) {
        cout << "0\n";
        return;
    }
    cout << max(ans1,ans2) << "\n";
    vi t; FOR(i,1,N+1) if (D.get(i) == i) t.pb(i);
    
    int ok;
    F0R(i,t.size()) {
        cout << n1[t[i]].back() << " " << n2[t[(i+1)%t.size()]].back() << "\n";
        ok = n1[t[i]].back();
        n1[t[i]].pop_back();
        n2[t[(i+1)%t.size()]].pop_back();
    }
    vi lef1, lef2;
    FOR(i,1,N+1) {
        for (int j: n1[i]) lef1.pb(j);
        for (int j: n2[i]) lef2.pb(j);
    }
    while (lef1.size() && lef2.size()) {
        cout << lef1.back() << " " << lef2.back() << "\n";
        lef1.pop_back(), lef2.pop_back();
    }
    for (int i: lef1) cout << i << " " << ok << "\n";
    for (int i: lef2) cout << ok << " " << i << "\n";
}

int main() {
    solve();
}

// read!
// ll vs. int!