#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e18 + 7;

int a[300005], dp[300005][4];

int32_t main()
{
	IO_OP;
	
	int n, x;
	cin >> n >> x;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++) {
		dp[i][0] = a[i] + max(dp[i-1][0], 0LL);
		dp[i][1] = x * a[i] + max(0LL, max(dp[i-1][0], dp[i-1][1]));
	}
	reverse(a+1, a+n+1);
	for(int i=1;i<=n;i++) {
		dp[i][2] = a[i] + max(dp[i-1][2], 0LL);
		dp[i][3] = x * a[i] + max(0LL, max(dp[i-1][2], dp[i-1][3]));
	}
	int ans = -INF;
	for(int i=1;i<=n;i++) {
		ans = max(ans, max(max(dp[i][0], dp[i][1]), 0LL)+max(0LL, max(dp[n-i][2], dp[n-i][3])));
	}
	cout << ans << endl;
}