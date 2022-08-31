#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define b begin()
#define e end()
 
const int MOD = 1000000007;

int n,k, dp[201][201][1001];
vi nums;
ll ans;

// dp based on current student, number open, difference

void dp1(int cur, int g, int k1) {
	int k2 = k1+g*(nums[cur+1]-nums[cur]);
	if (cur < n-1 && k2 <= k) {
		if (g>0) {
			ll a1 = ((ll)dp[cur+1][g-1][k2]+(ll)g*dp[cur][g][k1]) % MOD;
			dp[cur+1][g-1][k2] = int(a1);
		}
		ll a2 = ((ll)dp[cur+1][g][k2]+(ll)(g+1)*dp[cur][g][k1]) % MOD;
		dp[cur+1][g][k2] = int(a2);
		dp[cur+1][g+1][k2] = (dp[cur+1][g+1][k2]+dp[cur][g][k1]) % MOD;
	}
}

int main() {
	scanf("%d%d",&n,&k), nums.resize(n);
	F0R(i,n) scanf("%d",&nums[i]);
	sort(nums.b,nums.e);
	dp[0][1][0] = 1, dp[0][0][0] = 1;
	F0R(i,n) F0R(j,i+2) F0R(k1,k+1) if (dp[i][j][k1] != 0) dp1(i,j,k1);
	F0R(i,k+1) ans = (ans+dp[n-1][0][i]) % MOD; 
	printf("%d",ans);
}