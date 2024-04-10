#include<bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int main()
{
 	int n;
 	cin >> n;
 	vector<int> a(n);
 	for(int i = 0; i < n; i++)
 		cin >> a[i];
 	vector<vector<int> > dp(n + 1, vector<int>(3, INF));
 	dp[0][0] = 0;
 	for(int i = 0; i < n; i++)
 		for(int j = 0; j < 3; j++)
 		{
 		 	if(dp[i][j] == INF)
 		 		continue;
 		 	dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + 1);
 		 	if((a[i] == 1 || a[i] == 3) && j != 1)
 		 		dp[i + 1][1] = min(dp[i + 1][1], dp[i][j]);
 			if((a[i] == 2 || a[i] == 3) && j != 2)
 		 		dp[i + 1][2] = min(dp[i + 1][2], dp[i][j]);
 		}
	cout << *min_element(dp[n].begin(), dp[n].end());
}