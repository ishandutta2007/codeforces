#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
ll dp[MN][10];
int main() {
	int n;
	scanf ("%d",&n);
	memset(dp,-0x3f,sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		scanf ("%d",&k);
		vector<int> ones,twos,threes;
		while (k--) {
			int c,d;
			scanf ("%d %d",&c,&d);
			if (c == 1) ones.push_back(d);
			else if (c == 2) twos.push_back(d);
			else threes.push_back(d);
		}
		sort(all(ones),greater<int>()); sort(all(twos),greater<int>()); sort(all(threes),greater<int>());
		for (int j = 0; j < 10; j++) dp[i][j] = dp[i-1][j];
		if (ones.size() >= 3) for (int j = 0; j < 10; j++) dp[i][j] = max(dp[i][j],dp[i-1][(j+7)%10] + ones[0] + ones[1] + ones[2] + (j < 3 ? ones[0] : 0));
		if (ones.size() >= 2) for (int j = 0; j < 10; j++) dp[i][j] = max(dp[i][j],dp[i-1][(j+8)%10] + ones[0] + ones[1] +  (j < 2 ? ones[0] : 0));
		if (ones.size() >= 1) for (int j = 0; j < 10; j++) dp[i][j] = max(dp[i][j],dp[i-1][(j+9)%10]+ones[0]+(j==0?ones[0]:0));
		if (twos.size() >= 1 && ones.size() >= 1) for (int j = 0; j < 10; j++) dp[i][j] = max(dp[i][j],dp[i-1][(j+8)%10] + twos[0] + ones[0] + (j < 2 ? max(twos[0],ones[0]) : 0));
		if (twos.size() >= 1) for (int j = 0; j < 10; j++) dp[i][j] = max(dp[i][j],dp[i-1][(j+9)%10]+twos[0]+(j==0?twos[0]:0));
		if (threes.size() >= 1) for (int j = 0; j < 10; j++) dp[i][j] = max(dp[i][j],dp[i-1][(j+9)%10]+threes[0]+(j==0?threes[0]:0));
	}
	ll ret = 0;
	for (int i = 0; i < 10; i++) ret = max(ret,dp[n][i]);
	printf ("%lld\n",ret);
    return 0;
}