#include <bits/stdc++.h>
#define MP make_pair
#define EB emplace_back
#define PB push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9 + 7;

int dp[200005][3], a[200005];

int32_t main()
{
	
	int q;
	cin >> q;
	while(q--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		for(int i=0;i<n;i++) {
			if(s[i] == 'R') a[i] = 0;
			else if(s[i] == 'G') a[i] = 1;
			else a[i] = 2;
		}
		for(int j=0;j<3;j++)
			dp[0][j] = a[0] != j;
		for(int i=1;i<k;i++) {
			for(int j=0;j<3;j++) {
				dp[i][j] = dp[i-1][(j+2)%3] + (a[i] != j);
			}
		}
		for(int i=k;i<n;i++) {
			for(int j=0;j<3;j++) {
				dp[i][j] = dp[i-1][(j+2)%3] + (a[i] != j) - (a[i-k] != ((j-k)%3+3)%3);
			}
		}
		int ans = INF;
		for(int i=k-1;i<n;i++)
			for(int j=0;j<3;j++)
				ans = min(ans, dp[i][j]);
		cout << ans << endl;

	}

	return 0;
}