#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
    #define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int c[100005], f[587], h[11], dp[505][5005], cc[100005];

int main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	for(int i=0;i<n*k;i++) {
		int t;
		cin >> t;
		c[t]++;
	}
	for(int i=0;i<n;i++) {
		cin >> f[i];
		cc[f[i]]++;
	}
	for(int i=1;i<=k;i++)
		cin >> h[i];

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n*k;j++) {
			for(int l=0;l<=min(j, k);l++)
				dp[i][j] = max(dp[i][j], dp[i-1][j-l] + h[l]);
		}
	}
	int ans = 0;
	for(int i=0;i<100005;i++)
		ans += dp[cc[i]][c[i]];
	cout << ans << endl;
}