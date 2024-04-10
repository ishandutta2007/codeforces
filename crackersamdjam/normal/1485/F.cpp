#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
template<typename T> int size(const T &a){return a.size();}

using namespace std;
using ll = long long;
const int MM = 2e5+5;
const ll mod = 1e9+7;

int t, n, b[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		map<ll, ll> dp;
		dp[0] = 1;
		ll sum = 0, ans = 1;

		for(int i = 0; i < n; i++){
			cin>>b[i];
			ll add = (ans-dp[sum]+mod)%mod;
			dp[sum] = (dp[sum] + add)%mod;
			ans = (ans+add)%mod;
			sum += b[i];
		}
		cout<<ans<<'\n';
	}
}
/*
dp[i][j] = # of ways to end at index i with sum j
if a[i] = b[i],
	dp[i][j] --> dp[i][j+b[i]]
if a[i] = b[i]-sum(0, i-1),
	a[i] = b[i]-j
	dp[i][j] -> dp[i][j+b[i]-j]
	dp[i][j] -> dp[i][b[i]]

*/