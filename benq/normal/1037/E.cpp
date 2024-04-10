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

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int n,m,k,deg[MX],ans[MX];
bool active[MX];
vpi adj[MX], ed;
set<pi> s;

void del(int x) {
    s.erase({deg[x],x});
    deg[x] --;
    s.insert({deg[x],x});
}

void rem(int x, int i) {
    s.erase({deg[x],x});
    active[x] = 0;
    for (auto a: adj[x]) if (a.s <= i && active[a.f]) del(a.f);
}

int main() {
    io();
    cin >> n >> m >> k;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        ed.pb({a,b});
        adj[a].pb({b,i}), adj[b].pb({a,i});
        deg[a] ++, deg[b] ++;
    }
    FOR(i,1,n+1) {
        s.insert({deg[i],i});
        active[i] = 1;
    }
    F0Rd(i,m) {
        while (sz(s) && s.begin()->f < k) rem(s.begin()->s,i);
        ans[i] = sz(s);
        /*for (auto a: s) cout << a.f << " " << a.s << " | ";
        cout << "\n";*/
        if (active[ed[i].f] && active[ed[i].s]) del(ed[i].f), del(ed[i].s);
    }
    F0R(i,m) cout << ans[i] << "\n";
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/