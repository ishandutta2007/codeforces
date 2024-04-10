#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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
const ll INF = 1e18;
const int MX = 50001;

template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }

    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

vector<vi> graph;

template <int V> struct HeavyLight { // sum queries, sum updates
    int parent[V], heavy[V], depth[V];
    int root[V], treePos[V];
    LazySegTree<ll,V> tree;

    void init() {
        int n = graph.size();
        FOR(i,1,n+1) heavy[i] = -1;
        parent[1] = -1, depth[1] = 1;
        dfs(1);
        for (int i = 1, currentPos = 0; i <= n; ++i)
    		if (parent[i] == -1 || heavy[parent[i]] != i)
    			for (int j = i; j != -1; j = heavy[j]) {
    				root[j] = i;
    				treePos[j] = currentPos++;
    			}
    }
    
    int dfs(int v) {
        int size = 1, maxSubtree = 0;
        for (auto u : graph[v]) if (u != parent[v]) {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            int subtree = dfs(u);
            if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
            size += subtree;
        }
        return size;
    }

    template <class BinaryOperation>
    void processPath(int u, int v, BinaryOperation op) {
        for (; root[u] != root[v]; v = parent[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            op(treePos[root[v]], treePos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(treePos[u], treePos[v]); // assumes values are stored in edges, not vertices
    }

    void modifyPath(int u, int v, int value) {
        processPath(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
    }

    ll queryPath(int u, int v) {
        ll res = 0;
        processPath(u, v, [this, &res](int l, int r) { res += tree.qsum(l, r); });
        return res;
    }
};

HeavyLight<1<<16> H;
	
int n,m,q,C,f[MX],F[MX],c[MX];
set<int> oc[MX];
ll sumSquare, sumVal;
vpi modi[MX];
ld ans[MX];

void gen() {
    H.init();
    cout << fixed << setprecision(8);
    F0R(i,q) {
        ans[i] = -1;
        int t; cin >> t;
        if (t == 1) {
            int x,w; cin >> x >> w;
            modi[F[x]].pb({x,-1});
            F[x] = w;
            modi[F[x]].pb({x,1});
        } else {
            int k; cin >> k;
            modi[k].pb({i,0});
        }
    }
}

void ad(int x) {
    
}

void rem(int x) {
    
}

void upd(int x, int w) {
    rem(x);
    f[x] = w;
    ad(x);
}

ld get(int k) {
    return pow((ld)c[k],2)*sumSquare/n-(ld)2*c[k]*sumVal*C/n+(ld)C*C;
}

void input() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q >> C;
    graph.resize(n+1);
    FOR(i,1,n+1) {
        cin >> f[i];
        oc[f[i]].insert(i);
        F[i] = f[i];
    }
    FOR(i,2,n+1) {
        int p; cin >> p;
        graph[i].pb(p), graph[p].pb(i);
    }
    FOR(i,1,m+1) cin >> c[i];
}

void solve(int col) {
    // for every pair add 2*depth[lca]
    // for every one add depth[]
    sumSquare = sumVal = 0;
    for (int i: oc[col]) {
        sumSquare += 2*H.queryPath(1,i)+H.depth[i];
        sumVal += H.depth[i];
        H.modifyPath(1,i,1);
    }
    for (auto a: modi[col]) {
        if (a.s == -1) {
            oc[col].erase(a.f);
            H.modifyPath(1,a.f,-1);
            sumSquare -= 2*H.queryPath(1,a.f)+H.depth[a.f];
            sumVal -= H.depth[a.f];
        } else if (a.s == 1) {
            oc[col].insert(a.f);
            sumSquare += 2*H.queryPath(1,a.f)+H.depth[a.f];
            sumVal += H.depth[a.f];
            H.modifyPath(1,a.f,1);
        } else {
            ans[a.f] = get(col);
        }
    }
    for (int i: oc[col]) H.modifyPath(1,i,-1);
}

int main() {
    input();
    gen();
    FOR(i,1,m+1) solve(i);
    F0R(i,q) if (ans[i] != -1) cout << ans[i] << "\n";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)