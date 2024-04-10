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

const int nax = 505, mod = 998244353;
const int inf = 1e9;

int n, k;	
int dp[nax][nax];
void add(int &a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}
int ile[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; n >= i; ++i)
		dp[0][i] = 1;
	for(int j = 1; n >= j; ++j)
	{
		for(int i = 1; n >= i; ++i)
		{
			for(int g = 1; g <= j; ++g)
			{
				if(i - g >= 0)
					add(dp[i][j], dp[i - g][j]);
			}
		}
	}
	for(int i = 1; n >= i; ++i)
		for(int j = i; n >= j; ++j)
		{
			add(ile[j - i + 1], (ll) dp[i - 1][j - i + 1] * dp[n - j][j - i] % mod);
		}
	int ans = 0;
	for(int len = 1; n >= len; ++len)
	{
		for(int bok = 1; min(n, (k - 1) / len) >= bok; ++bok)
		{
			int mam = (ll) ile[bok] * ile[len] % mod;
			mam = mam * 2 % mod;
			add(ans, mam);
		}
	}
	cout << ans;
		
	
	
	return 0;
}