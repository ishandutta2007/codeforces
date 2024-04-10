#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)
using namespace std;


const int nax = 100005, mod = 998244353, pot = 17;
const ll inf = 1e18 + 1;
int n, k, q	;
int cost[nax], col[nax];
ll dp[nax];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> q;
	for(int i = 1; n >= i; ++i)
		cin >> cost[i];
	for(int i = 1; n >= i; ++i)
		cin >> col[i];
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		pair<ll, int> best, best2;
		best = best2 = mp(0, -1);
		ll ans = 0;
		for(int i = 1; n >= i; ++i)
			dp[i] = -inf;
		
		for(int i = 1; n >= i; ++i)
		{
			ll X = dp[col[i]];
			if(dp[col[i]] != -inf)
				X = max(X, dp[col[i]] + (ll) cost[i] * a);
			if(best.second != col[i])
				X = max(X, best.fi + (ll) cost[i] * b);
			if(best2.second != col[i])
				X = max(X, best2.fi + (ll) cost[i] * b);
			
			dp[col[i]] = max(dp[col[i]], X);
			
			if(col[i] == best.se && dp[col[i]] > best.fi)
				best = mp(dp[col[i]], col[i]);
			else if(col[i] == best2.se && dp[col[i]] > best2.fi)
				best2 = mp(dp[col[i]], col[i]);
			else if(col[i] == best.se || col[i] == best2.se)
				;
			else if(dp[col[i]] > best2.fi)
				best2 = mp(dp[col[i]], col[i]);
			else if(dp[col[i]] > best.fi)
				best = mp(dp[col[i]], col[i]);
			//cout << best.fi << " "<< best2.fi << endl;
			if(best2.fi > best.fi)
				swap(best, best2);
			ans = max(ans, best.fi);
		}
		cout << ans << endl;
	}
		
	

    return 0;
}