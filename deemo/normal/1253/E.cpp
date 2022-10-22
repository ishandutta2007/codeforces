#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int C = 80 + 3;

int n, m;
pii p[MAXN];
int dp[MAXN][C];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;
	sort(p, p+n);
	memset(dp, 63, sizeof(dp));
	for (int i = 0; i <= n; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++){
			dp[i][j] = dp[i][j-1];
			if (p[j-1].F <= i) {
				int req = i - (p[j-1].F + p[j-1].S);
				req = max(0, req);
				int temp = p[j-1].F - (p[j-1].S + req) - 1;
				if (temp >= 1 && p[0].F > temp)
					req += temp;
				dp[i][j] = min(dp[i][j], dp[max(0, p[j-1].F - p[j-1].S - req - 1)][j-1] + req);
			}
			else
				dp[i][j] = min(dp[i][j], dp[min(i, max(0, p[j-1].F - p[j-1].S - 1))][j-1]);

		}
	cout << dp[m][n] << "\n";
	return 0;
}