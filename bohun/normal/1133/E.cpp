#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
const int nax = 5005;
int dp[nax][nax][2];
int a[5005];
int pref[5005];
map < int ,int > m;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, k;
	int t[5005];
	cin >> n >> k;
	for(int i = 1; n >= i; ++i)
		cin >> t[i], m[t[i]]++;
	sort(t + 1,t + n +1);
	t[0] = -2;
	int ile = 1;
	for(int i = 1; n >= i; ++i)
	{
		while(t[i - 1] == t[i])
			i++;
		if(i <= n)
		{
			a[ile] = t[i];
			ile++;
		}
	}
	ile--;
	for(int i = 1; ile >= i; ++i)
		pref[i] = pref[i - 1] + m[a[i]];
	dp[1][1][1] = m[a[1]];
	for(int i = 1; ile >= i; ++i)
	{
		for(int mas = 0; k >= mas; mas++)
		{
			for(int j = i - 1; i - 6 < j; --j)
			{
				if(j <= 0)
					continue;
				if(a[i] - a[j] <= 5 and mas >= 1)
					dp[i][mas][0] = max(dp[i][mas][0], dp[j][mas][1] + pref[i] - pref[j]);
				dp[i][mas][0] = max(dp[i][mas][0], max(dp[j][mas][0], dp[j][mas][1]) );
				if(mas >= 1)
					dp[i][mas][1] = max(dp[i][mas][1], max(dp[j][mas - 1][0], dp[j][mas - 1][1]) + m[a[i]]);
				//cout << i << " " << mas << " " << dp[i][mas][0] << " " << dp[i][mas][1] << " " << pref[i] << endl;
			}
		}
	}
	int ans = 0;
	for(int i = 1; k >=i ;++i)
		ans = max(ans , max(dp[ile][i][0], dp[ile][i][1]));
	cout << ans;
	
	return 0;
}