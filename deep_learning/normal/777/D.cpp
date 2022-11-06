#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std; 
int len[500005], diff[500005], ans[500005]; 
vector<int> dp[500005], pre[500005], mx[500005], pos[500005]; 
string str[500005];
int main()
{
	// freopen("777D.in", "r", stdin); 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> str[i]; 
		len[i] = str[i].size(); 
		dp[i].resize(len[i]); 
		pre[i].resize(len[i]); 
		mx[i].resize(len[i]); 
		pos[i].resize(len[i]); 
	}
	for (int i = 1; i < n; i++)
	{
		bool f = false; 
		for (int j = 0; j < min(str[i - 1].size(), str[i].size()); j++)
		{
			if (str[i][j] != str[i - 1][j])
			{
				diff[i] = j; 
				f = true; 
				break; 
			}
		}
		if (!f)
			diff[i] = min(str[i - 1].size(), str[i].size()); 
	}
	for (int j = 0; j < len[0]; j++)
	{
		dp[0][j] = j; 
		mx[0][j] = j; 
		pos[0][j] = j; 
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < len[i]; j++)
		{
			if (diff[i] > j)
			{
				dp[i][j] = mx[i - 1][j] + j;
				pre[i][j] = pos[i - 1][j]; 
			}
			else if (str[i - 1][diff[i]] < str[i][diff[i]])
			{
				dp[i][j] = mx[i - 1][len[i - 1] - 1] + j; 
				pre[i][j] = pos[i - 1][len[i - 1] - 1]; 
			}
			else
			{
				dp[i][j] = mx[i - 1][diff[i] - 1] + j; 
				pre[i][j] = pos[i - 1][diff[i] - 1]; 
			}
			mx[i][j] = j ? mx[i][j - 1] : 0; 
			if (dp[i][j] > mx[i][j])
			{
				mx[i][j] = dp[i][j];
				pos[i][j] = j; 
			}
		}
	}
	int res = -1e9, idx; 
	for (int i = 0; i < len[n - 1]; i++)
	{
		if (dp[n - 1][i] > res)
		{
			res = dp[n - 1][i]; 
			idx = i; 
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		ans[i] = idx; 
		idx = pre[i][idx]; 
	}
	for (int i = 0; i < n; i++)
		cout << str[i].substr(0, ans[i] + 1) << endl; 
	return 0; 
}