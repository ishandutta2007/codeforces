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

int Q;
ll shift[60];

ll lev(ll X) {
    return __builtin_clzll(1)-__builtin_clzll(X);
}

ll getPos(ll X) {
    ll t = lev(X);
    return (1LL<<t)+((X+shift[t]+(1LL<<t)) % (1LL<<t));
}

void prin(ll X) {
    ll t = lev(X);
    cout <<  (1LL<<t)+((X-shift[t]+(1LL<<t)) % (1LL<<t)) << " ";
    if (X > 1) prin(X/2);
}

void ad (ll L, ll K) {
    shift[L] = (shift[L]+K)%(1LL<<L);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Q;
    F0R(i,Q) {
        int T; cin >> T;
        if (T == 1) {
            ll X,K; cin >> X >> K;
            ad(lev(X),K);
        } else if (T == 2) {
            ll X,K; cin >> X >> K;
            FOR(i,lev(X),60) {
                ad(i,K);
                K = 2*K % (1LL<<59);
            }
        } else {
            ll X; cin >> X;
            prin(getPos(X));
            cout << "\n";
        }
    }
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)