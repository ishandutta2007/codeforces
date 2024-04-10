#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int dp[105][3],a[105];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		dp[i][0] = dp[i][1] = dp[i][2] = INF;
	}
	if(a[0] == 0) {
		dp[0][0] = 1;
	} else if(a[0] == 1) {
		dp[0][2] = 0;
	} else if(a[0] == 2) {
		dp[0][1] = 0;
	} else {
		dp[0][1] = 0;
		dp[0][2] = 0;
	}
	for(int i=1;i<n;i++) {
		if(a[i] == 0) {
			for(int j=0;j<3;j++) 
				dp[i][0] = min(dp[i][0], dp[i-1][j]);
			dp[i][0]++;
		} else if(a[i] == 1) {
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
			dp[i][0] = min(dp[i-1][2], min(dp[i-1][0], dp[i-1][1])) + 1;
		} else if(a[i] == 2) {
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
			dp[i][0] = min(dp[i-1][2], min(dp[i-1][0], dp[i-1][1])) + 1;
		} else {
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
		}
	}
	cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])) << endl;
}