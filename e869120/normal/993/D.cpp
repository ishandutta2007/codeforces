#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long n, a[59], b[59], dp[53][29][5109][2]; vector<pair<long long, long long>>vec;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) vec.push_back(make_pair(-a[i], b[i]));
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= n; i++) { a[i] = vec[i - 1].first*-1; b[i] = vec[i - 1].second; }
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n / 2; j++) { for (int k = 0; k <= n * 100; k++) { dp[i][j][k][0] = (1LL << 40); dp[i][j][k][1] = (1LL << 40); } }
	}
	dp[0][0][0][0] = 0; dp[0][0][0][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n / 2; j++) {
			for (int k = 0; k <= n * 100; k++) {
				if (dp[i][j][k] == 0) continue;

				// i : , j : 2 , k : , 0 :  1 , 1 :  2 
				dp[i + 1][j][k + b[i + 1]][0] = min(dp[i + 1][j][k + b[i + 1]][0], dp[i][j][k][0] + a[i + 1]);
				if (a[i + 1] != a[i + 2]) dp[i + 1][j][k + b[i + 1]][1] = min(dp[i + 1][j][k + b[i + 1]][1], dp[i][j][k][0] + a[i + 1]);
				
				if ((i + 1) - (j + 1) >= j + 1) dp[i + 1][j + 1][k][0] = min(dp[i + 1][j + 1][k][0], dp[i][j][k][1]);
				if ((i + 1) - (j + 1) >= j + 1) dp[i + 1][j + 1][k][1] = min(dp[i + 1][j + 1][k][1], dp[i][j][k][1]);
			}
		}
	}
	long long minx = (1LL << 60);
	for (int i = 0; i <= n / 2; i++) {
		for (int j = 1; j <= n * 100; j++) {
			minx = min(minx, (1000LL * dp[n][i][j][0] + j - 1) / j);
			minx = min(minx, (1000LL * dp[n][i][j][1] + j - 1) / j);
		}
	}
	cout << minx << endl;
	return 0;
}