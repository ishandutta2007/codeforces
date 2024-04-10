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

mt19937_64 g(69420);

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

template<class T> bool miller_rabin(T N, int iterations = 7){
	if(N < 2 or N%6%4 != 1)
		return (N|1) == 3;
	vector<T> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	while(int(A.size()) < iterations)
		A.emplace_back(uniform_int_distribution<long long>(1795265023, numeric_limits<long long>::max())(g));
	int s = 0;
	while(!(((N-1)>>s)&1))
		s++;
	T d = N>>s;
	for(T a: A){
		T p = fpow(a%N, d, N);
		int i = s;
		while(p != 1 and p != N-1 and a%N and i--)
			p = p*p%N;
		if(p != N-1 and i != s)
			return 0;
	}
	return 1;
}

int t, n, a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>t;
	while(t--){
		cin>>n;

		ll r = 1e9+1;
		vector<array<ll, 4>> v;

		for(int i = 1; i <= n; i++){
			cin>>a[i];
		}
		for(int i = 2; i <= n; i++){
			while(!miller_rabin(r))
				r++;
			a[1] = min(a[1], a[i]);
			v.push_back({1, i, a[1], r});
			r++;
		}

		cout<<size(v)<<'\n';
		for(auto i: v){
			for(auto j: i)
				cout<<j<<' ';
			cout<<'\n';
		}
	}
}