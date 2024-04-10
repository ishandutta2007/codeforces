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
int const MM = 2e5+5;
ll const mod = 998244353;

int n, k;
ll dp[MM] = {1}, ans[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>k;
	int m = sqrtl(2*n)*2+5+k;
	m = min(m, n);
	for(int i = k; i <= m; i++){
		for(int j = i; j <= n; j++){
			dp[j] += dp[j-i];
			if(dp[j] > mod) dp[j] -= mod;
		}
		for(int j = n; j >= i; j--){
			dp[j] = dp[j-i];
			ans[j] += dp[j];
			if(ans[j] > mod) ans[j] -= mod;
		}
		for(int j = i-1; j >= 0; j--){
			dp[j] = 0;
		}
	}
	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<' ';
	}
}