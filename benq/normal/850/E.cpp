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

vi sos (vi dp) {
    int SZ = 31-__builtin_clz(sz(dp));
    F0R(i,SZ) {
        vi res = dp;
        F0R(j,1<<SZ) if (j&(1<<i)) res[j^(1<<i)] += dp[j];
        swap(res,dp);
    }
    return dp;
}

namespace FWHT {
    int get(int s) {
        return s > 1 ? 32 - __builtin_clz(s - 1) : 0;
    }

    vd fwht(vd P) {
        for (int len = 1; 2 * len <= sz(P); len <<= 1) {
            for (int i = 0; i < sz(P); i += 2 * len) {
                for (int j = 0; j < len; j++) {
                    double u = P[i + j];
                    double v = P[i + len + j];
                    P[i + j] = u+v;
                    P[i + len + j] = u-v;
                }
            }
        }
    
        return P;
    }
    
    vd fwht_rev(vd& a) {
        vd res = fwht(a);
        F0R(i,sz(res)) res[i] /= sz(a);
        return res;
    }
    
    vd sq(vd a) {
        int s = sz(a), L = get(s), n = 1<<L;
        if (s <= 0) return {};
        
        a.resize(n); a = fwht(a);
        
        F0R(i,n) a[i] = a[i]*a[i];
        a = fwht_rev(a);
        return a;
    }
    
    vi sq(vi a) {
        vd A; for (auto x: a) A.pb(x);
        vd c = sq(A);
        vi C; for (double x: c) C.pb(round(x));
        return C;
    }
}

int n;

void prin(vi v) {
    F0R(i,sz(v)) cout << v[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    string s; cin >> s;
    vi v; F0R(i,1<<n) v.pb(s[i]-'0');
    vi V = FWHT::sq(v);
    // prin(V);
    ll ans = 0;
    F0R(i,sz(V)) ans = (ans+((ll)V[i]<<(n-__builtin_popcount(i))))%MOD;
    cout << 3*ans%MOD;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/