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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001;

// i rows, j cols 
// multiplier: (-1)^(i+j+1)
// if j == 0: 3^i*3^((n-i)*n)
// 3*

template<int SZ> struct Combo {
    ll fac[SZ+1], ifac[SZ+1];
    
    Combo() {
        fac[0] = ifac[0] = 1;
    	FOR(i,1,SZ+1) {
    	    fac[i] = i*fac[i-1] % MOD;
    	    ifac[i] = inv(fac[i]);
    	}
    }
    
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll comb(ll a, ll b) {
        if (a < b || b < 0 || a < 0) return 0;
        ll tmp = fac[a]*ifac[b] % MOD;
        tmp = tmp*ifac[a-b] % MOD;
        return tmp;
    }
};

Combo<1000005> C;

ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }

ll ad(ll a, ll b) { return (a+b)%MOD; }
ll sub(ll a, ll b) { return (a-b+MOD)%MOD; }
ll mul(ll a, ll b) { return a*b%MOD; }
ll divi(ll a, ll b) { return mul(a,inv(b)); }

ll n, ans = 0;

ll getsgn(int i, int j) {
	if ((i+j)&1) return 1;
	return MOD-1;
}

ll po3[1000005];

void solve1() {
    FOR(i,1,n+1) {
    	ll ret = getsgn(i,0);
        ret = mul(ret,mul(po3[i],po(po3[n],n-i)));
        ret = mul(ret,C.comb(n,i));
    	ans = ad(ans,mul(ret,2));
    }
}

void solve2() {
    F0R(i,n) {
    	ll ret = mul(getsgn(i,0),C.comb(n,i));
    	ret = mul(ret,3);
    	ll z = po(sub(1,po3[i]),n);
    	z = sub(z,po(sub(0,po3[i]),n));
    	ans = ad(ans,mul(z,ret));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    po3[0] = 1;
    FOR(i,1,n+1) po3[i] = mul(3,po3[i-1]);
    solve1();
    solve2();
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS