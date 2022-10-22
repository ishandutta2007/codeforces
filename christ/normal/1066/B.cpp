#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int dp[MN];
int main() {
	int n,r;
	scanf ("%d %d",&n,&r);
	vector<int> a(n+1); vector<int> heat;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		if (a[i]) heat.push_back(i);
	}
	memset(dp,0x3f,sizeof dp); dp[0] = 0;
	for (int pos : heat) {
		int ed = min(pos+r-1,n);
		dp[ed] = min(dp[ed],dp[max(0,pos-r)]+1);
		for (int i = ed; i >= 0; i--) dp[i] = min(dp[i],dp[i+1]);
	}
	printf ("%d\n",dp[n]>1e9?-1:dp[n]);
    return 0;
}
//psa[j] - psa[i-1] <= k
//psa[j] <= k + psa[i-1]