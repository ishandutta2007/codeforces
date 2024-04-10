#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
ll const mod = 1e9+7;
int const MM = 2e5+5;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

ll f[MM], inv[MM];

ll C(int n, int k){
	return f[n]*inv[k]%mod*inv[n-k]%mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin>>t;

	f[0] = inv[0] = 1;
	for(ll i = 1; i < MM; i++){
		f[i] = f[i-1]*i%mod;
		inv[i] = divmod(1LL, f[i], mod);
	}

	while(t--){
		ll n, k;
		cin>>n>>k;
		ll ans = 0;

		ll each = fpow(2LL, n, mod);

		ll good = 0, bad = n%2 == 0;
		for(int i = 1; i < n; i += 2){
			good += C(n, i);
			good %= mod;
		}
		// pr(good, each);

		ll rem = 1;
		for(int i = 1; i <= k; i++){
			// pr("i", i, good, rem, "o", fpow(kk, k-1, mod));
			ans += (rem*good % mod) *fpow(each, k-i, mod);
			// should multiply by n choose k

			ans %= mod;
			// the rest don't matter if this passes

			rem *= (each-good-bad);
			rem %= mod;
		}
		// pr(ans);
		ll tot = fpow(each, k, mod);
		// pr("tot", tot);
		ans = tot-ans;
		ans %= mod;
		if(ans < 0) ans += mod;
		cout<<ans<<'\n';
	}
}