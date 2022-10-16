#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 2005;

int t, n, k;
int dp[MM][MM];
// dp[i][# removed] = # matched

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>k;

		for(int i = 0; i <= n; i++){
			memset(dp[i], -0x3f, sizeof dp[i]);
		}
		dp[0][0] = 0;
		int ans = 1e9;

		for(int i = 1; i <= n; i++){
			int a;
			cin>>a;
			a = i-a;
			for(int j = 0; j <= i; j++){
				dp[i][j] = dp[i-1][j] + (a == j);
				if(j){
					dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
				}
				if(dp[i][j] >= k){
					ans = min(ans, j);
				}
			}
		}
		if(ans == 1e9)
			ans = -1;
		cout<<ans<<'\n';
	}
}