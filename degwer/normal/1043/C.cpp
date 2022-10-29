#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string dp[2020][2];
int frm[2020][2];
int ans[2020];
int main()
{
	string s;
	cin >> s;
	dp[0][0] = dp[0][1] = "";
	for (int i = 0; i < s.size(); i++)
	{
		string z11, z12, z21, z22;
		z11 = z12 = dp[i][0], z21 = z22 = dp[i][1];
		z11.push_back(s[i]);
		z12.push_back(s[i]);
		z21.push_back(s[i]);
		z22.push_back(s[i]);
		reverse(z21.begin(), z21.end());
		reverse(z22.begin(), z22.end());
		if (z11 < z22)dp[i + 1][0] = z11, frm[i + 1][0] = 0;
		else dp[i + 1][0] = z22, frm[i + 1][0] = 1;
		if (z21 < z12)dp[i + 1][1] = z21, frm[i + 1][1] = 0;
		else dp[i + 1][1] = z12, frm[i + 1][1] = 1;
		reverse(dp[i + 1][1].begin(), dp[i + 1][1].end());
	}
	int now = 0;
	for (int i = s.size(); i >= 1; i--)
	{
		ans[i] = frm[i][now];
		now ^= frm[i][now];
	}
	for (int i = 1; i <= s.size(); i++)printf("%d ", ans[i]); printf("\n");
}