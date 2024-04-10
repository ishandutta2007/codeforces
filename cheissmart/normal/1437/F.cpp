#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 5005, M = 998244353;

int a[N], dp[N][N], sum_dp[N][N], before[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	memset(before, -1, sizeof before);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			if(a[j] * 2 <= a[i])
				before[i] = j;
	for(int i = 0; i < n; i++) {
		dp[i][1] = 1;
		if(i) sum_dp[i][1] = (dp[i][1] + sum_dp[i - 1][1]) % M;
		else sum_dp[i][1] = dp[i][1];
		for(int j = 2; j <= i + 1; j++) {
			if(before[i] + 1 >= j - 1) {
				dp[i][j] = 1LL * dp[i][j - 1] * (before[i] + 1 - (j - 2)) % M;
				dp[i][j] = (dp[i][j] + sum_dp[before[i]][j - 1]) % M;
			}
			if(i) sum_dp[i][j] = (dp[i][j] + sum_dp[i - 1][j]) % M;
			else sum_dp[i][j] = dp[i][j];
		}
	}
	cout << dp[n - 1][n] << endl;
}