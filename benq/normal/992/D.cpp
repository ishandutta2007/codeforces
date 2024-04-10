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

int n,k;
vpi x;
ll ans = 0;

void ad(ll z0, ll z1, ll need) {
    // 0 <= i <= z0 
    ll lo = max(0LL,need-z1), hi = min(need,z0);
    if (lo > hi) return;
    ans += hi-lo+1;
    // i <= 
    // i >= 
    // 0 <= need-i <= z1
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    x.pb({1,0});
    F0R(i,n) {
        int t; cin >> t;
        if (t != 1) {
            x.pb({t,1});
            x.pb({1,0});
        } else {
            x.back().s ++;
        }
    }
    
    if (k == 1) for (int cur = 0; cur < sz(x); cur += 2) ans += x[cur].s;
    
    for (int cur = 1; cur < sz(x); cur += 2) {
        ll a = 1, b = 0;
        for (int CUR = cur; CUR < sz(x); CUR += 2) {
            assert(x[CUR].f > 1);
            if ((ld)a*x[CUR].f > 1e18) break;
            
            a *= x[CUR].f; b += x[CUR].f;
            if (a % k == 0) ad(x[cur-1].s,x[CUR+1].s,a/k-b);
            b += x[CUR+1].s;
        }
    }
    
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS