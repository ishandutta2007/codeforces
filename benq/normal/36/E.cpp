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

DSU<10001> D;

set<vi> adj[10001];
vi ans, comp;
int m;
bitset<10001> in;

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> m; 
	F0R(i,m) {
	    int a,b; cin >> a >> b;
	    adj[a].insert({b,i+1}), adj[b].insert({a,i+1});
	    D.unite(a, b);
	    in[a] = in[b] = 1;
	}
	FOR(i,1,10001) if (adj[i].size()&1) ans.pb(i);
	FOR(i,1,10001) if (in[i] && D.get(i) == i) comp.pb(i);
}

vi tmp[10001];
vector<vi> fin;
vi cur;

void dfs(int x) {
    while (adj[x].size()) {
        vi y = *adj[x].begin(); 
        adj[x].erase(adj[x].begin()), adj[y[0]].erase({x,y[1]});
        
        dfs(y[0]);
        cur.pb(y[1]);
    }
}

void gen(int x) {
    if (tmp[x].size()) dfs(tmp[x].back());
    else dfs(x);
    fin.pb(cur);
    cur.clear();
}

void solve1() {
    if (tmp[comp[0]].size() > 4) {
        cout << -1;
        exit(0);
    }
    if (tmp[comp[0]].size() == 4) {
        int a = tmp[comp[0]][0], b = tmp[comp[0]][1];
        adj[a].insert({b,MOD}), adj[b].insert({a,MOD});
        gen(comp[0]);
        
        F0R(i,fin[0].size()) if (fin[0][i] == MOD) {
            fin.pb({});
            FOR(j,i+1,fin[0].size()) fin[1].pb(fin[0][j]);
            fin[0].resize(i);
            return;
        }
    } else {
        gen(comp[0]);
        fin.pb({fin[0].back()});
        fin[0].pop_back();
    }
}

void solve2() {
    for (int i: comp) if (tmp[i].size() > 2) {
        cout << -1;
        exit(0);
    }
    gen(comp[0]), gen(comp[1]);
}

void finish() {
	if (fin.size() < 2 || fin[0].size() == 0 || fin[1].size() == 0) {
	    cout << -1;
	    exit(0);
	}
	cout << fin[0].size() << "\n";
	for (int i: fin[0]) cout << i << "\n";
	cout << fin[1].size() << "\n";
	for (int i: fin[1]) cout << i << "\n";
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
	init();
	for (int i: ans) tmp[D.get(i)].pb(i);
	if (comp.size() > 2) { // too many components
	    cout << -1;
	    return 0;
	} else if (comp.size() == 1) {
	    solve1();
	} else {
	    solve2();
	}
	finish();
}

// read!
// ll vs. int!