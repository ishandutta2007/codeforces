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
int const MM = 4e6+5;

ll mod;

void add(ll &a, ll b){
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
}

int n;
ll dp[MM], psa[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>mod;
	dp[n] = 1;
	ll s = 0;
	for(int i = n; i >= 1; i--){
		add(dp[i], s);

		for(ll j = 2; j*i <= n; j++){
			ll hi = min((ll)n+1, j*(i+1));
			add(dp[i], psa[i*j]-psa[hi]);
			add(dp[i], 0);
		}

		psa[i] = psa[i+1];
		add(psa[i], dp[i]);
		add(s, dp[i]);
	}
	dp[1] %= mod;
	if(dp[1] < 0) dp[1] += mod;
	cout<<dp[1]<<'\n';
}