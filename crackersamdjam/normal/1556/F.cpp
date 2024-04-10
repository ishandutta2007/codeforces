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
using vi = vector<char>;
ll const mod = 1e9+7;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int n;
ll a[14];
ll p[14][14];
ll dp[1<<14];
ll ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j)
				p[i][j] = 1;
			else
				p[i][j] = divmod(a[i], a[i]+a[j], mod);
		}
	}

	for(int i = 1; i < (1<<n); i++){
		dp[i] = 1;
		vector<int> good, bad;
		for(int j = 0; j < n; j++){
			if(i&(1<<j)){
				good.emplace_back(j);
			}
			else{
				bad.emplace_back(j);
			}
		}

		dp[i] = 1;
		for(int b: good){
			for(int c: bad){
				dp[i] = dp[i]*p[b][c]%mod;
			}
		}

		int sz = __builtin_popcount(i);
		for(int j = (i-1)&i; j; j = (j-1)&i){
			ll r = 1;
			int k = i^j;
			for(int b = 0; b < n; b++){
				if(k&(1<<b)){
					for(int c: bad){
						r = r*p[b][c]%mod;
					}
				}
			}

			dp[i] -= dp[j]*r;
			dp[i] %= mod;
		}

		ans += dp[i]*sz;
		ans %= mod;
	}

	if(ans < 0) ans += mod;
	cout<<ans<<'\n';
}