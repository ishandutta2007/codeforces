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

int n;
map<ll,ll> m;

// i*x+b --> (i+1)*x+b 
// for every a >= m 
// go to (a-m,b+i*m)

void mx(ll& a, ll b) { a = max(a,b); }

void process(int ind, ll x) {
    for (auto it = m.lb(x); it != m.end(); it = next(it), m.erase(prev(it))) {
        ll di = it->f/x;
        mx(m[it->f%x],it->s+ind*di*x);
        mx(m[x-1],it->s+ind*(di-1)*x);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    m[(ll)pow(10,13)-1] = 0;
    F0R(i,n) {
        ll a; cin >> a;
        process(i,a);
    }
    ll ans = 0;
    for (auto a: m) ans = max(ans,a.f*n+a.s);
    cout << ans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/