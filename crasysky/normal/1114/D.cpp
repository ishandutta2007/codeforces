#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
#define maxn 5003
using namespace std;
int c[maxn], dp[maxn][maxn][2];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
		cin >> c[i];
	for (int i = n; i; -- i)
		for (int j = i + 1; j <= n; ++ j){
			if (c[i] == c[i + 1]){
				dp[i][j][0] = dp[i + 1][j][0];
				dp[i][j][1] = dp[i + 1][j][1];
				continue;
			}
			if (c[j] == c[j - 1]){
				dp[i][j][0] = dp[i][j - 1][0];
				dp[i][j][1] = dp[i][j - 1][1];
				continue;
			}
			if (c[i] == c[j]){
				dp[i][j][0] = dp[i][j][1] = min(dp[i + 1][j - 1][0], dp[i + 1][j - 1][1]) + 1;
				continue;
			}
			dp[i][j][0] = min(dp[i][j - 1][0], min(dp[i + 1][j][0], dp[i + 1][j][1])) + 1;
			dp[i][j][1] = min(dp[i + 1][j][1], min(dp[i][j - 1][0], dp[i][j - 1][1])) + 1;
		}
	cout << min(dp[1][n][0], dp[1][n][1]) << endl;
}