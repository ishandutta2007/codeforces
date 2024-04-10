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
const int MX = 1000001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int n,k;

struct con {
    int num = 0;
    vi p;
    
    void ins() {
        num ++;
        p.pb(0);
    }
    
    void addOne() {
        for (int& i: p) i ++;
        while (sz(p) > 1 && 2*p[sz(p)-2] > k) p.pop_back();
    }
};

void comb(con& a, con& b) {
    a.num += b.num;
    for (int i: b.p) a.p.pb(i);
    sort(all(a.p));
    while (sz(a.p) > 1 && 2*a.p[sz(a.p)-2] > k) a.p.pop_back();
    while (sz(a.p) > 1 && a.p[0]+a.p[1] <= k) {
        a.p.erase(a.p.begin());
        a.num --;
    }
}

vi adj[MX];
con c[MX];

void dfs(int x, int y = 0) {
    if (sz(adj[x]) == 1) c[x].ins();
    for (int i: adj[x]) if (i != y) {
        dfs(i,x);
        c[i].addOne();
        comb(c[x],c[i]);
    }
}

int main() {
    io();
    cin >> n >> k;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1);
    cout << c[1].num;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/