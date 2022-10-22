#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
int dp[6];
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	for (int i = 0; i < n; i++) {
		if (a[i] == 4) dp[0]++;
		else if (a[i] == 8) dp[1] = min(dp[0],dp[1]+1);
		else if (a[i] == 15) dp[2] = min(dp[1],dp[2]+1);
		else if (a[i] == 16) dp[3] = min(dp[2],dp[3]+1);
		else if (a[i] == 23) dp[4] = min(dp[3],dp[4]+1);
		else dp[5] = min(dp[4],dp[5]+1);
	}
	printf ("%d\n",n-dp[5]*6);
    return 0;
}