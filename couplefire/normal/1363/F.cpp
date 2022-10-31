#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2005;
 
int n;
string s, t;
int suf[26][N], suf2[26][N];
int cache[N][N];
 
int dp(int i, int j)
{
	if(j == 0)
		return 0;
	int &ans = cache[i][j];
	if(ans != -1)
		return ans;
	ans = 2e9;
	if(i > 0)
	{
		ans = 1 + dp(i - 1, j);
		if(s[i - 1] == t[j - 1])
			ans = min(ans, dp(i - 1, j - 1));
	}
	int ch = t[j - 1] - 'a';
	if(suf[ch][i + 1] - suf2[ch][j + 1] > 0)
		ans = min(ans, dp(i, j - 1));
	return ans;
}
 
int32_t main()
{
	IOS;
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> n >> s >> t;
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				cache[i][j] = -1;
		for(int i = 0; i <= 25; i++)
			for(int j = 0; j <= n + 1; j++)
				suf[i][j] = suf2[i][j] = 0;
		for(int i = n; i >= 1; i--)
		{
			for(int j = 0; j < 26; j++)
			{
				suf[j][i] = suf[j][i + 1];
				suf2[j][i] = suf2[j][i + 1];
			}
			suf[s[i - 1] - 'a'][i]++;
			suf2[t[i - 1] - 'a'][i]++;
		}
		int ans = dp(n, n);
		if(ans > 1e9)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}