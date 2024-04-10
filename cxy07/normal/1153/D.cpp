//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;

int n,cnt;
int dp[MAXN],a[MAXN],f[MAXN],isleaf[MAXN];

int main () {
	cin >> n;
	for(int i = 1;i <= n; ++i) {
		cin >> a[i];
		dp[i] = (a[i] ? n + 1 : 0);
		isleaf[i] = -1;
	}
	for(int i = 2,tmp;i <= n; ++i) {
		cin >> tmp;
		f[i] = tmp; isleaf[tmp] = i;
	}
	for(int i = n;i > 1; --i) {
		if(isleaf[i] == -1) dp[i] = 1,cnt++;
		int fa = f[i];
		dp[fa] = a[fa] ? min(dp[fa],dp[i]) : dp[fa] + dp[i];
	}
	cout << cnt + 1 - dp[1] << endl;
	return 0;
}