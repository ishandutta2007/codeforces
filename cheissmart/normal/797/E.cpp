#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int S = sqrt(100000) + 1;
int n, a[100005], q, dp[S][100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	cin >> q;
	
	for(int k=1;k<S;k++) {
		for(int p=100000;p>=1;p--) {
			if(p + a[p] + k > n) dp[k][p] = 1;
			else dp[k][p] = 1 + dp[k][p + a[p] + k];
		}
	}
	
	while(q--) {
		int p, k;
		cin >> p >> k;
		if(k >= S) {
			int ct = 0;
			for(;p <= n;ct++) p += a[p] + k;
			cout << ct << endl;
		} else {
			cout << dp[k][p] << endl;
		}
	}
}