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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

ll no (ll x) {
    return (x+MOD)%MOD;
}

ll mul(ll a, ll b) {
    return no(a*b%MOD);
}

ll ad(ll a, ll b) {
    return no((a+b)%MOD);
}

template<int SZ> struct Combo {
    ll fac[SZ+1], ifac[SZ+1];
    
    Combo() {
        fac[0] = ifac[0] = 1;
    	FOR(i,1,SZ+1) {
    	    fac[i] = i*fac[i-1] % MOD;
    	    ifac[i] = inv(fac[i]);
    	}
    }
    
    ll po (ll b, ll p) {
        return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
    }
    
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll comb(ll a, ll b) {
        if (a < b) return 0;
        ll tmp = fac[a]*ifac[b] % MOD;
        tmp = tmp*ifac[a-b] % MOD;
        return tmp;
    }
};

Combo<200005> C;
int n,k;
ll sum = 0;

ll part(ll a, ll b) {
    if (a == 0 && b == 0) return 1;
    if (a < b || a < 1 || b < 1) return 0;
    if (b == 1) return 1;
    return part(a-1,b-1)+b*part(a-1,b);
}

ll po(ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

ll get(int n, int k, int ind) {
    ll t = C.comb(k-1,ind);
    if (ind&1) t *= -1;
    ll x = mul(n,po(k-ind,n-1));
    x -= mul(n-1,mul(k-1-ind,po(k-ind,n-2)));
    return mul(t,x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    F0R(i,n) {
        int x; cin >> x;
        sum = ad(sum,x);
    }
    
    ll ans = 0;
    F0R(i,k) ans = ad(ans,get(n,k,i));
    ans = mul(ans,C.ifac[k-1]);
    // ll z = 0;
    // FOR(i,1,n+1) z = ad(z,mul(i,mul(C.comb(n-1,i-1),part(n-i,k-1))));
    ans = mul(ans,sum);
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)