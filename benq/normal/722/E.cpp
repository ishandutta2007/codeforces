#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;

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
        if (a < 0 || b < 0) return 0;
        ll tmp = fac[a+b]*ifac[b] % MOD;
        tmp = tmp*ifac[a] % MOD;
        return tmp;
    }
};

Combo<200000> C;

int n,m,k,s;
ll dp[2001][21];
vector<pii> bad;

void norm(ll& x) {
    x = (x%MOD+MOD)%MOD;
}

int get(int x) {
    if (x == 1) return 0;
    return 32-__builtin_clz(x-1);
}

void solve(int lev, int ind) {
    dp[ind][lev] = C.comb(n-bad[ind].f,m-bad[ind].s);
    FOR(i,ind+1,bad.size()) {
        dp[ind][lev] -= C.comb(bad[i].f-bad[ind].f,bad[i].s-bad[ind].s)*dp[i][lev];
        norm(dp[ind][lev]);
    }
    F0Rd(i,lev) dp[ind][lev] -= dp[ind][i];
    norm(dp[ind][lev]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k >> s; 
	bad.pb({1,1}); 
	F0R(i,k) {
	    int r,c; cin >> r >> c;
	    bad.pb({r,c});
	}
	sort(bad.begin(),bad.end());
	F0R(j,20) F0Rd(i,bad.size()) solve(j,i);
	dp[0][20] = C.comb(n-1,m-1);
	F0R(i,20) {
	    dp[0][20] -= dp[0][i];
	    norm(dp[0][20]);
	}
	ll ans = 0;
	F0R(i,21) {
	    ans += dp[0][i]*s; 
	    norm(ans);
	    s = (s+1)/2;
	}
	ans = ans*C.inv(C.comb(n-1,m-1)); norm(ans);
	cout << ans;
}

// read!
// ll vs. int!