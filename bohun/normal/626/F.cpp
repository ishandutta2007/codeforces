#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 205, mod = 1e9 + 7;
const ll inf = 1e18, z = 0;
int dp[nax][nax][1005];
int n, k;
int t[nax];

void add(int &a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; n > i; ++i)
		cin >> t[i];
	sort(t, t + n);
	reverse(t, t + n);
	dp[0][0][0] = 1;
	for(int i = 0; n > i; ++i)
		for(int j = 0; n >= j; ++j)
			for(int s = 0; k >= s; ++s)
			{
				int go = j * (t[i] - t[i + 1]) + s;
				// open
				if(go + (t[i] - t[i + 1]) <= k)
					add(dp[i + 1][j + 1][go + (t[i] - t[i + 1])], dp[i][j][s]);
				// close
				if(j > 0 && go - (t[i] - t[i + 1]) <= k)
					add(dp[i + 1][j - 1][go - (t[i] - t[i + 1])], (ll)dp[i][j][s] * j % mod);
				// open && close
				if(go <= k)
					add(dp[i + 1][j][go], dp[i][j][s]);
				// con
				if(go <= k)
					add(dp[i + 1][j][go], (ll) j * dp[i][j][s] % mod);
			}
	int ans = 0;
	for(int i = 0; k >= i; ++i)
		add(ans, dp[n][0][i]);
	cout << ans;
				
	
	
	
	return 0;
}