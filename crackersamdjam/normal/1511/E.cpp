#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 3e5+5;
const ll mod = 998244353;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int n, m;
ll ans, cnt, two, three, psa[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin>>s[i];
		for(int j = 0; j < m; j++){
			cnt += s[i][j] == 'o';
		}
	}

	psa[0] = 0;
	psa[1] = 0;
	for(int i = 2; i <= cnt; i++){
		int f = i%2 ? -1 : 1;
		psa[i] = (psa[i-1] + f*fpow(2LL, cnt-i, mod))%mod;
	}

	vector<vector<int>> r(n, vector<int>(m));
	vector<vector<int>> c(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i) c[i][j] = c[i-1][j];
			if(j) r[i][j] = r[i][j-1];

			if(s[i][j] == 'o'){
				r[i][j]++;
				c[i][j]++;
			}
			else{
				r[i][j] = c[i][j] = 0;
			}

			ans += psa[r[i][j]];
			ans += psa[c[i][j]];
			ans %= mod;
		}
	}

	ans = (ans%mod+mod)%mod;
	cout<<ans<<'\n';
}