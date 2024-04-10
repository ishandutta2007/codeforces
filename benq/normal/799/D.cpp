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

ll a,b,h,w,n;
ll dp[MX]; 
vl v;

bool done() {
    F0R(i,MX) if (i*h >= a && dp[i]*w >= b) return 1;
    return 0;
}

void ad(ll x) {
    F0Rd(i,MX) if (dp[i] != -MOD) {
        dp[min((ll)MX-1,i*x)] = max(dp[min((ll)MX-1,i*x)],dp[i]);
        dp[i] = min(dp[i]*x,(ll)MX-1);
        // i*x, dp[i]
        // i, dp[i]*x
    }
}

int get() {
    F0R(i,MX) dp[i] = -MOD;
    dp[1] = 1;
    if (done()) return 0;
    F0R(i,min(sz(v),34)) {
        ad(v[i]);
        if (done()) return i+1;
    }
    return MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> h >> w >> n;
    v.resize(n);
    F0R(i,n) cin >> v[i];
    sort(all(v)); reverse(all(v));
    int x = get();
    swap(a,b);
    x = min(x,get());
    if (x == MOD) cout << -1;
    else cout << x;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)