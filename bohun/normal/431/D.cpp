#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

ll dp[100][100];
ll m, k;	


ll solve(ll x) {
	ll res = __builtin_popcountll(x) == k;
	ll Count = 0;
	for(int i = 60; 0 <= i; --i) {
		if(!((x >> i) & 1))
			continue;
		if(k - Count >= 0) {
			res += dp[i][k - Count];
		}
		Count += 1;
	}
	return res;
}
	

bool ok(ll x) {
	return solve(2 * x) - solve(x) >= m;
}
 
int main() {
	for(int i = 0; i <= 61; ++i) {
		dp[i][0] = dp[i][i] = 1;
		for(int j = 1; j < i; ++j)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}
	scanf("%lld %lld", &m, &k);
	ll left = 1;
	ll right = 1e18;
	while(left < right) {
		ll mid = (left + right) / 2;
		if(ok(mid))
			right = mid;
		else
			left = mid + 1;
	}
	printf("%lld", left);
	
	
	return 0;
}