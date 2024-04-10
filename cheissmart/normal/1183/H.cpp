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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e15 + 7;

int dp[102][102];
int pre[102][26];

signed main()
{
	IO_OP;
	
	int n, k;
	string s;
	cin >> n >> k >> s;	
	s = ' ' + s;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 26; j++)
			pre[i][j] = pre[i-1][j];
		pre[i][s[i]-'a'] = i;
	} 
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			for(int k = 0; k < 26; k++) {
				if(pre[i][k])
					dp[i][j] = min(INF, dp[i][j] + dp[pre[i][k]-1][j-1]);
			}
		}
	}
	int cur = 0, cost = 0;
	for(int i = 0; i <= n && cur < k; i++) {
		int cnt = dp[n][n - i];
		if(cur + cnt >= k) {
			cnt = k - cur;
			cur += cnt;
			cost += i * cnt;
		} else {
			cur += cnt;
			cost += i * cnt;
		}
	}
	if(cur == k) cout << cost << endl;
	else cout << -1 << endl;
}