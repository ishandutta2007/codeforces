#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n, m;
int a, b;
vector < int > v[5005];
ll dp[5005];
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; m >= i; ++i)	
	{
		cin >> a >> b;
		v[a].push_back(b);
	}
	for(int i = 1; n >= i; ++i)
	{
		int mini = 1000000000;
		for(auto w: v[i])
		{
			int c = ((w > i) ? w - i : n - (i - w));
			mini = min(mini, c);
		}
		dp[i] = (ll)n * ((int)v[i].size() - 1) + mini;
		if(v[i].size() == 0)
			dp[i] = 0;
		//cout << i << " " << dp[i] <<endl;
	}
	for(int i = 1; n >= i; ++i)
	{
		ll ans = dp[i];
		int ile = 0;
		int node = i;
		while(ile < n-1)
		{
			node = (node)%n + 1;
			ile++;
			if(dp[node] > 0)
			ans = max(ans, dp[node] + ile);
		}
		cout << ans << " ";
	}
			
	return 0;	
}