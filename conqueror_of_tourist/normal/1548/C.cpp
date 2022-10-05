#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD = 1000000007;

vll fact;
vll invfact;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % MOD, e /= 2)
		if (e & 1) ans = ans * b % MOD;
	return ans;
}

ll comb(ll a,ll b){
    if (b < 0 || b > a){
        return 0;
    }
    ll den = (invfact[b] * invfact[a-b]) % MOD;
    return (fact[a] * den) % MOD;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int MAX = 3000005;
	
	fact.pb(1);
	for(int i = 1; i < MAX; i++){
	    fact.pb((i * fact[i-1]) % MOD);
	}
	
	invfact.pb(modpow(fact[MAX-1], MOD-2));
	ll i3 = modpow(3, MOD-2);
	for (int i = MAX - 1; i > 0; i--){
	    invfact.pb((i * invfact.back()) % MOD);
	}
	
	reverse(invfact.begin(), invfact.end());
	
	int n,q;
	cin >> n >> q;
	
	ll a,b,c;
	a = n+1;
	b = n;
	c = n;
	
	vll out;
	out.pb(a);
	
	for(int i = 1; i <= 3 * n; i += 1){
	    ll tot = comb(3 * n + 1, i + 1);
	    ll e1 = b % MOD;
	    ll e2 = c % MOD;
	    ll b3 = (tot - b - b - c) % MOD;
	    ll base = (i3 * b3) % MOD;
	    a = base + e1 + e2;
	    b = base;
	    c = base + e1;
	    a %= MOD;
	    if (a < 0) a += MOD;
	    out.pb(a);
	}
	
	for (int t = 0; t < q; t++){
	    int v;
	    cin >> v;
	    cout << out[v] << '\n';
	}
}