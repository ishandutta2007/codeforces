#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	string s;
	cin >> s;
	int n = s.size();
	int dp[n], sum = 0;
	dp[0] = 0;
	for (int i = 1; i < n; i++){
		dp[i] = dp[i - 1] + (s[i - 1] == s[i] && s[i] == 'v');
	}
	sum = dp[n - 1];
	ll ans = 0;
	for (int i = 0 ; i < n; i++){
		if (s[i] == 'o'){
			ans += dp[i] * (sum - dp[i]);
		}
	}
	cout << ans;
}