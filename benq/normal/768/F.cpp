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

ll f,w,h;
ll ok = 0, ot = 0;
ll fac[100000], ifac[100000];

ll inv (ll b) { // MOD is prime
    ll ans = 1, p = MOD-2;
    while (p) {
        if (p&1) ans = ans*b % MOD;
        p >>= 1;
        b = b*b % MOD;
    }
    return ans;
}

ll combo(ll a, ll b) {
    if (b > a || a < 0) return 0;
    ll tmp = fac[a]*ifac[b] % MOD;
    tmp = tmp*ifac[a-b] % MOD;
    return tmp;
}

void test(int a, int b) { // a food, b wine
    ll tok = 0, tot = 0;
    tot = combo(f-1,a-1)*combo(w-1,b-1) % MOD;
    tok = combo(f-1,a-1)*combo(w-1-b*h,b-1) % MOD;
    if (a == b) tok *= 2, tot *= 2;
    ok = (ok+tok) % MOD, ot = (ot+tot) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	fac[0] = ifac[0] = 1;
	FOR(i,1,100000) {
	    fac[i] = i*fac[i-1] % MOD;
	    ifac[i] = inv(fac[i]);
	}
	cin >> f >> w >> h;
	if (f == 0) {
	    if (w > h) cout << 1;
	    else cout << 0;
	    return 0;
	} 
	if (w == 0) {
	    cout << 1;
	    return 0;
	}
	FOR(i,1,100001) {
	    test(i,i);
	    test(i+1,i);
	    test(i,i+1);
	}
	cout << (ok*inv(ot)) % MOD;
}

// read!
// ll vs. int!