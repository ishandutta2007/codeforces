#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (ll i=a; i<(b); i++)
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

const int MOD = 998244353;

int a,b,c;
ll fac[10001], ifac[10001];

ll inv (ll b) { // MOD is prime
    ll ans = 1, p = MOD-2;
    while (p) {
        if (p&1) ans = ans*b % MOD;
        p >>= 1;
        b = b*b % MOD;
    }
    return ans;
}

ll combo(ll x, ll y) {
    ll tmp = fac[x]*ifac[y] % MOD;
    tmp = tmp*ifac[x-y] % MOD;
    return tmp;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	fac[0] = ifac[0] = 1;
	FOR(i,1,10001) {
	    fac[i] = i*fac[i-1] % MOD;
	    ifac[i] = inv(fac[i]);
	}
	cin >> a >> b >> c;
	ll x = 0, y = 0, z = 0;
	F0R(k,min(a,b)+1) {
	    ll tmp = combo(a,k)*combo(b,k) % MOD;
	    tmp = tmp*fac[k] % MOD;
	    x = (x+tmp) % MOD;
	}
	F0R(k,min(b,c)+1) {
	    ll tmp = combo(b,k)*combo(c,k) % MOD;
	    tmp = tmp*fac[k] % MOD;
	    y = (y+tmp) % MOD;
	}
	F0R(k,min(a,c)+1) {
	    ll tmp = combo(a,k)*combo(c,k) % MOD;
	    tmp = tmp*fac[k] % MOD;
	    z = (z+tmp) % MOD;
	}
	ll ans = 1;
	ans = (ans*x) % MOD;
	ans = (ans*y) % MOD;
	ans = (ans*z) % MOD;
	cout << ans;
}

// read!
// ll vs. int!