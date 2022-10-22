#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 100 + 20;

int n, d;
int x[max_n], y[max_n];
int dis[max_n][max_n];
int dp[max_n][max_n], save[max_n];

int cal(int a, int b){
	int dif = abs(x[a] - x[b]) + abs(y[a] - y[b]);
	return dif * d;	
}

void solve(){
	for (int i = 0; i < n; i++)
		dp[i][n - 1] = min(0, save[i] - dis[i][n - 1]);

	for (int j = n - 2; j >= 0; j--)
		for (int i = 0; i < n; i++){
			dp[i][j] = dp[i][j + 1];

			for (int w = 0; w < n; w++){
				if (w == i)	continue;
				int a = save[i] - dis[i][w];
				dp[i][j] = max(dp[i][j], dp[w][j + 1] + a);
			}
			if (dp[i][j] > 0)	dp[i][j] = 0;
		}	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 1; i < n - 1; i++)
		cin >> save[i];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dis[i][j] = cal(i, j);

	solve();
	int ans = dp[0][0];
	if (ans > 0)	ans = 0;
	else	ans = -ans;
	cout << ans << endl;
	return 0;
}