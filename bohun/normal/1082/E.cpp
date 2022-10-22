#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;

const int nax = 500005, mod = 998244353;
const ll  inf = 1e18;
int dp[nax];
int suf[nax];	
int n, c;
int t[nax], ile;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for(int i = 1; n >= i; ++i)
		cin >> t[i];
	for(int i = n; i >= 1; --i)
	{
		suf[i] = suf[i + 1] + (t[i] == c);
	}
	for(int i = 1; n >= i; ++i)
	{
		dp[t[i]] = max(dp[t[i]] + 1, ile + 1);
		if(t[i] == c)
			ile++;
		ans = max(ans, dp[t[i]] + suf[i + 1]);
	}
	cout << ans;
		
	
	
	return 0;
}