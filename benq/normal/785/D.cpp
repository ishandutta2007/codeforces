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

string s;
int tot0, tot1;
ll fac[200001], ifac[200001];

ll combo(ll a, ll b) {
    if (a-b < 0 || b < 0) return 0LL;
    ll tmp = (fac[a]*ifac[b]) % MOD;
    tmp = (tmp*ifac[a-b]) % MOD;
    return tmp;
}

ll inv (ll x) {
    ll p = MOD-2, ans = 1;
    while (p) {
        if (p&1) ans = (ans*x) % MOD;
        x = (x*x) % MOD;
        p >>= 1;
    }
    return ans;
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	F0R(i,s.length()) {
	    if (s[i] == '(') tot0 ++;
	    else tot1++;
	}
	fac[0] = ifac[0] = 1;
	FOR(i,1,200001) {
	    fac[i] = (i*fac[i-1]) % MOD;
	    ifac[i] = inv(fac[i]);
	}
}

int main() {
    init();
    
    ll ans = 0;
	int co0 = 0, co1 = 0;
	F0R(i,s.length()) {
	    if (s[i] == '(') {
	        ans = (ans+combo(co0+tot1-co1,tot1-co1-1)) % MOD;
	        co0 ++;
	    } else co1++;
	}
	cout << ans;
}

// read!
// ll vs. int!