#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

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
const int MX = 200001;

int n,s;

struct Euler {
    vi circuit;
    set<pi> adj[MX];
    
    void addEdge(int a, pi b) {
        adj[a].insert(b);
    }
    
    void find_circuit(int x) { // directed graph, possible that resulting circuit is not valid
        while (sz(adj[x])) {
            pi j = *adj[x].begin(); adj[x].erase(adj[x].begin());
            find_circuit(j.f);
            circuit.pb(j.s);
        }
    }
    
    vector<vi> genCyc() {
        vector<vi> ans;
        F0R(i,n) if (sz(adj[i])) {
            circuit.clear();
            find_circuit(i);
            ans.pb(circuit);
        }
        return ans;
    }
};

Euler E;

vi a, A;
map<int,int> m;

void compress() {
    for (int i: a) m[i] = 0;
    int co = 0;
    for (auto& x: m) x.s = co++;
    for (int& i: a) i = m[i];
}

void input() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s; a.resize(n);
    F0R(i,n) cin >> a[i];
    compress();
    // for (int i: a) cout << i << " ";
    A = a; sort(all(A));
}

vector<vi> x;

void tri(int extra) {
    extra = min(extra,sz(x));
    if (extra <= 2) return;
    vi X, st;
    F0R(i,extra) {
        X.insert(X.end(),all(x.back()));
        st.pb(x.back().front());
        x.pop_back();
    }
    reverse(all(st));
    x.pb(X); x.pb(st);
}

void rot(vi v) {
    for (int& i: v) i --;
    int val = a[v.back()];
    FORd(i,1,sz(v)) a[v[i]] = a[v[i-1]];
    a[v[0]] = val;
}

int main() {
    input();
    F0R(i,sz(a)) if (a[i] != A[i]) E.addEdge(a[i],{A[i],i+1});
    x = E.genCyc();
    int sum = 0; for (auto y: x) sum += sz(y);
    tri(s-sum);
    sum = 0; for (auto y: x) sum += sz(y);
    
    if (sum <= s) {
        cout << sz(x) << "\n";
        for (auto a: x) {
            rot(a);
            cout << sz(a) << "\n";
            for (int i: a) cout << i << " ";
            cout << "\n";
        }
    } else {
        cout << -1;
    }
    // for (int i: a) cout << i << " ";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/