#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 1e5+5;
const ll mod = 1e9+7;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int t, n, k;
ll f[MM], inv[MM];

ll C(int nn, int kk){
	assert(nn >= kk and kk >= 0);
	return f[nn]*inv[kk]%mod*inv[nn-kk]%mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	f[0] = 1;
	for(ll i = 1; i < MM; i++)
		f[i] = f[i-1]*i%mod;
	inv[MM-1] = divmod(1LL, f[MM-1], mod);
	for(int i = MM-1; i; i--)
		inv[i-1] = inv[i]*i%mod;

	cin>>t;
	while(t--){
		cin>>n>>k;
		ll ans = 1;

		for(int i = 1; i <= n; i++){
			//i have been taken
			int rem = n-(i-1)*(k-1);
			if(rem < i) break;
			ll add = C(rem, i);
			ll tot = C(n, i);
			ans = (ans + divmod(add, tot, mod))%mod;
			// pr(i, rem, tot);
		}
		cout<<ans<<'\n';
	}
}