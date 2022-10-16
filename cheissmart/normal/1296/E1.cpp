#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 202; // Note: this is O(N) dp

int dp[N], pre[N], pre1[N], ans[N], a[N];

signed main()
{
	IO_OP;
	
	int n;
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++)
		a[i] = s[i] - 'a';
	dp[0] = -INF;
	pre[0] = pre1[0] = -1;
	for(int i=1;i<n;i++) {
		dp[i] = INF;
		if(a[i-1] <= a[i] && dp[i-1] < dp[i]) {
			dp[i] = dp[i-1];
			pre1[i] = pre1[i-1];
			pre[i] = i - 1;
		}
		if(dp[i-1] <= a[i] && a[i-1] < dp[i]) {
			dp[i] = a[i-1];
			pre[i] = pre1[i-1];
			pre1[i] = i - 1;
		}
	}
	if(dp[n-1] == INF) {
		cout << "NO" << endl;
		return 0;
	}
	int i = n - 1;
	while(i >= 0) {
		ans[i] = 1;
		i = pre[i];
	}
	cout << "YES" << endl;
	for(int i=0;i<n;i++)
		cout << ans[i];
	
}