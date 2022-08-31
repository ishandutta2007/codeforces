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
const int MX = 200005;

int T,n;
ll a[MX], ans[MX], g, in;
map<int,vi> m;

ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
    a %= b;
    if (a <= 1) return a;
    ll i = inv(b%a,a);
    ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
    if (tmp < 0) tmp += b;
    return tmp;
}

ll norm(ll x, ll m) {
    return (x%m+m)%m;
}

void solve(vi v) {
    // cout << sz(v) << "\n";
    /*for (int i: v) cout << i << " ";
    cout << "\n";*/
    vpi pos;
    F0R(i,sz(v)) pos.pb({norm((a[v[i]]-a[v[0]])/g,T/g)*in%(T/g),v[i]}); // if two are congruent mod T/g, throw away the later one 
    sort(all(pos));
    vpi POS;
    for (auto a: pos) {
        if (sz(POS) && POS.back().f == a.f) continue;
        POS.pb(a);
    }
    POS.pb({T/g,-1});
    /*for (auto a: POS) cout << a.f << " " << a.s << " | ";
    cout << "\n";*/
    F0R(i,sz(POS)-1) ans[POS[i].s] = POS[i+1].f-POS[i].f;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T >> n;
    F0R(i,n) cin >> a[i];
    swap(a[n],a[0]);
    FOR(i,1,n+1) a[i] += a[i-1];
    g = __gcd((ll)T,a[n]); in = inv((a[n]/g)%(T/g),T/g);
    
    /*F0R(i,n+1) cout << a[i] << " ";
    cout << "\n";
    cout << "AH " << a[6] << " " << a[7] << " " << a[n] << "\n";
    cout << "AH " << norm(a[7]-a[6],T/g) << " " << (a[n]/g)%(T/g) << " " << in << " " << norm(a[7]-a[6],T/g)*in%(T/g) << "\n";*/
    
    F0R(i,n) m[a[i]%g].pb(i);
    for (auto a: m) solve(a.s);
    F0R(i,n) cout << ans[i] << " ";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/