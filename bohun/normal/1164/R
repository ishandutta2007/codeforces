#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 0; n > i; ++i)
using namespace std;
const int nax = 2005, mod = 1e9 + 7;
int n, h;
int t[nax], dp[nax][nax];

void add(int &a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}
int max_h = 2000 + 1;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> h;
	bool ok = 1;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		if(t[i] > h)
			ok = 0;
		t[i] = h - t[i];	
	}
	if(!ok)
	{
		cout << 0;
		return 0;
	}
	dp[0][0] = 1;
	up(i, n)
		up(j, max_h)
		{
			int ile;
			ile = j + 1;
			if(ile == t[i + 1])
				add(dp[i + 1][j], dp[i][j]);
			ile = j + 1;
			if(ile == t[i + 1])
				add(dp[i + 1][j + 1], dp[i][j]);
			ile = j;
			if(j && ile == t[i + 1])
				add(dp[i + 1][j - 1], (ll) j * dp[i][j] % mod);
			if(j == t[i + 1])
				add(dp[i + 1][j], dp[i][j]);
			ile = j + 1;
			if(j && ile == t[i + 1])
				add(dp[i + 1][j], (ll) j * dp[i][j] % mod);
		}
	cout << dp[n][0];

    return 0;
}