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

// 1 query: {1,1}, {2,3}, {4,6}, ...
// 2 queries: {1,3}, {2,}

ll M = 10004205361450474LL;
ll des = M;

map<ll,ll> good[6];

ll get(ll L, ll Q) {
    L = min(L,10000LL);
    if (good[Q].count(L)) return good[Q][L];
    if (Q == 1) return good[Q][L] = L;
    
    ll cans = 0;
    F0R(i,L+1) {
        cans += get(L+cans,Q-1);
        if (i != L) cans ++;
    }
    
    return good[Q][L] = cans;
}

int co = 0;

int query(vl v) {
    cout << sz(v) << endl;
    for (auto a: v) cout << a << " ";
    cout << endl;
    
    /*int x = sz(v);
    F0R(i,sz(v)) {
        if (v[i] == des) {
            x = -1;
            break;
        }
        if (v[i] > des) {
            x = i;
            break;
        }
    }*/
    int x; cin >> x;
    
    co ++;
    if (x == -1) {
        // cout << co;
        exit(0);
    }
    return x;
}

void solve(ll L, ll Q) {
    vl v;
    
    ll cans = 0;
    F0R(i,min(L,10000LL)+1) {
        if (Q>1) cans += get(L+cans,Q-1);
        if (i != min(L,10000LL)) {
            v.pb(L+cans); cans ++;
        }
    }
    int x = query(v);
    if (x == 0) solve(L,Q-1);
    else solve(v[x-1]+1,Q-1);
}

int main() {
    solve(1,5);
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/