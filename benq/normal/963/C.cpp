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
typedef vector<pl> vpl;

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

int n;
vector<array<ll,3>> a;
vpl allx, ally;
vi ne;

vpl normalize(vpl v) {
    ll g = 0;
    for (auto a: v) g = __gcd(g,a.s);
    for (auto& a: v) a.s /= g;
    return v;
}

void testValid(int x) {
    if (ne[1]-ne[0] != ne[x+1]-ne[x]) return;
    
    vpl v1, v2;
    FOR(i,ne[0],ne[1]) v1.pb({a[i][1],a[i][2]});
    FOR(i,ne[x],ne[x+1]) v2.pb({a[i][1],a[i][2]});
    if (normalize(v1) != normalize(v2)) {
        cout << 0;
        exit(0);
    }
}
 
namespace NT {
    vpl fac(ll x) {
        vpl pri;
        
        for (ll i = 2; i*i <= x; ++i) if (x % i == 0) {
            ll t = 0;
            while (x % i == 0) x /= i, t ++;
            pri.pb({i,t});
        }
        
        if (x > 1) pri.pb({x,1});
        return pri;
    }

    ll numFac(ll x) {
        ll ans = 1;
        for (auto a: fac(x)) ans *= (a.s+1);
        return ans;
    }
    
    ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
        a %= b;
        if (a <= 1) return a;
        ll i = inv(b%a,a);
        ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
        if (tmp < 0) tmp += b;
        return tmp;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; a.resize(n);
    F0R(i,n) F0R(j,3) cin >> a[i][j];
    sort(all(a));
    
    F0R(i,n) if (i == 0 || a[i][0] != a[i-1][0]) ne.pb(i);
    for (int i: ne) allx.pb({a[i][0],a[i][2]});
    ne.pb(n);
    FOR(i,ne[0],ne[1]) ally.pb({a[i][1],a[i][2]});
    
    FOR(i,1,sz(ne)-1) testValid(i);
    allx = normalize(allx);
    ally = normalize(ally);
    
    if (a[0][2] % allx[0].s != 0 || a[0][2]/allx[0].s % ally[0].s != 0) {
        cout << 0;
        exit(0);
    }
    ll mult = a[0][2]/allx[0].s/ally[0].s;
    cout << NT::numFac(mult);
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)