#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
using namespace std;
int n, t[1005];
int dp[1005];
const int mod = 998244353;
int sil[1005], odw[1005];
void add(int &a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}
int pot(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return res;
}
int daj(int a, int b)
{
	if(b > a)
		return 0;
	int res = sil[a];
	res = (ll) res * odw[b] % mod;
	res = (ll) res * odw[a - b] % mod;
	return res;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	dp[0] = 1;
	sil[0] = odw[0] = 1;
	for(int i = 1; n >= i; ++i)
	{
		sil[i] = (ll) sil[i - 1] * i % mod;
		odw[i] = pot(sil[i], mod - 2);
	}
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		for(int j = i - 1; j >= 1; --j)
		{
			int ile = t[j] + 1;
			ile -= 2;
			int dos = i - j - 1;
			if(ile >= 0)
			{
				add(dp[i], (ll) dp[j - 1] * daj(dos, ile) % mod);
			}
		}
		add(dp[i], dp[i - 1]);
	}
	cout << (dp[n] - 1 + mod) % mod;

			
	
	
	return 0;
}