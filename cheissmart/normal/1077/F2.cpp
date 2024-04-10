#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int dp[5005][5005], a[5005];
const int INF = 1e15+87;

signed main()
{
	IO_OP;

	int n, k, x;
	cin >> n >> k >> x;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=x;i++)
		dp[i][0] = -INF;
	for(int j=0;j<=x;j++) {
		vi v(n+1);
		for (int i = 1; i <= n; i++)
			v[i] = dp[j-1][i-1]+a[i];
		deque<int> dk;
		for(int i=1;i<=n;i++) {
			while(dk.size() && v[dk.back()] <= v[i])
				dk.pop_back();
			dk.push_back(i);
			while(dk.front() < i-k+1)
				dk.pop_front();
			if(i/k > j || j > i) {
				dp[j][i] = -INF;
				continue;
			}
			if(j == 0) {
				dp[j][i] = 0;
				continue;
			}
			//dp[j][i] = rmq(v,max(1LL, i-k+1),i);
			dp[j][i] = v[dk.front()];
			//for(int l=i;l>=max(1LL, i-k+1);l--)
				//dp[j][i] = max(dp[j][i], v[l]);
			//cout << j << " " << i <<" "<< dp[j][i] << endl;
		}
	}
	if(dp[x][n] < 0) cout << -1 << endl;
	else cout << dp[x][n] << endl;
}