#include<bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int> > dp(n + 1, vector<int>(4, INF));
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 3; j++)
		{
		 	if (i < n)
		 	{
		 		int add = 0;
		 		if((s[i] == 'a' && j == 1) || (s[i] == 'b' && j != 1))
		 			add = 1;
		 		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + add);
		 	}
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
		}
	cout << n - dp[n][3] << endl;
}