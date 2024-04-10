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
const int MX = 2000010;

int n,k;
ll dp[MX];
ll fac[MX], ifac[MX];

ll po (ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

ll inv (ll b) { return po(b,MOD-2); }

ll perm(int lo, int hi) {
    if (lo > hi+1) return 0;
    ll tmp = (fac[hi]*ifac[lo-1]) % MOD;
    assert (0 <= tmp && tmp < MOD);
    return tmp;
}

int hi;
ll csum = 0;

void solve(int ind) {
    csum = csum*ind % MOD;
    while (hi > ind+k) {
        csum -= perm(ind,hi-2)*dp[hi];
        csum = (csum%MOD+MOD)%MOD;
        hi --;
    }
    
    csum += dp[ind+1];
    csum %= MOD;
    
    dp[ind] += csum;
    dp[ind] %= MOD;
    
    ll tmp = perm(ind,ind+k-1)*perm(ind+k+1,n-1) % MOD;
    tmp *= (n-(ind+k));
    tmp %= MOD;
    
    dp[ind] += tmp;
    dp[ind] %= MOD;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	fac[0] = ifac[0] = 1;
	FOR(i,1,MX) {
	    fac[i] = (i*fac[i-1]) % MOD;
	    ifac[i] = inv(fac[i]) % MOD;
	}
	cin >> n >> k; hi = n;
	FORd(i,1,n) solve(i);
	cout << dp[1];
}

// read!
// ll vs. int!