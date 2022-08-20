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
const int MX = 100001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
        setIn(s+".in");
        setOut(s+".out");
    }
}

int N,K;
map<int,Tree<pi>> m;

int get(int i, int l, int r) {
    if (!m.count(i)) return 0;
    return m[i].order_of_key({r+1,-MOD})-m[i].order_of_key({l,-MOD});
}

int main() {
    io();
    cin >> N >> K;
    vector<array<int,3>> v;
    F0R(i,N) {
        int x,r,q; cin >> x >> r >> q;
        v.pb({r,x,q});
    }
    sort(v.rbegin(),v.rend());
    ll ans = 0;
    int co = 0;
    for (auto a: v) {
        FOR(i,a[2]-K,a[2]+K+1) ans += get(i,a[1]-a[0],a[1]+a[0]);
        m[a[2]].insert({a[1],co++});
    }
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/