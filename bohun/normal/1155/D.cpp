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
const int nax = 300005, inf = 1000000000, mod = 1e9 + 7;
ll dp[nax][2][2];
ll n, t[nax], m;
ll ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
	}
	for(int i = 1; n >= i; ++i)
	{
		ll a = max(t[i], t[i] + dp[i - 1][0][0]);
		ll b = max(t[i] * m, max(dp[i - 1][0][0], dp[i - 1][1][0]) + t[i] * m);
		ll c = max(t[i], max(dp[i - 1][1][0], dp[i - 1][1][1]) + t[i]);
		dp[i][0][0] = max((ll)0, a);
		dp[i][1][0] = max((ll)0, b);
		dp[i][1][1] = max((ll)0, c);
		ans = max({ans, dp[i][1][1], dp[i][0][0], dp[i][1][0]});
	}
	cout << ans;
	return 0;
}