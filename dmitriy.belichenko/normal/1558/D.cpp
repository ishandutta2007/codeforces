// #include <bits/stdc++.h>
// Lili rope submission 
#include <bits/extc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int const MM = 4e5+5;
ll const mod = 998244353;

using namespace __gnu_cxx;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int t, n, m;
vector<int> in[MM];
ll f[MM], inv[MM];

ll C(int nn, int kk){
	// assert(nn > 0 and kk > 0);
	if(nn < kk) return 0;
	assert(nn < MM and kk < MM);
	return f[nn]*inv[kk]%mod*inv[nn-kk]%mod;
}

ll go(int ball, int box){
	return C(ball+box-1, box-1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	f[0] = inv[0] = 1;
	for(ll i = 1; i < MM ; i++){
		f[i] = f[i-1]*i%mod;
		inv[i] = divmod(1LL, f[i], mod);
	}

	rope<bool> rr, r;
	for(int i = 0; i < MM; i++){
		rr.push_back(false);
	}

	cin>>t;
	for(int tc = 1; tc <= t; tc++){
		cin>>n>>m;
		int must = m;
		r = rr;
		for(int i = 0; i < m; i++){
			int x, y; cin>>x>>y;
			if(r[y-1]){
				must--;
				r.replace(y-1, 1, false);
			}
			r.insert(y, true);
		}

		ll ans = go(n-1-must, n+1);

		assert(ans > 0);
		cout<<ans<<'\n';
	}
}