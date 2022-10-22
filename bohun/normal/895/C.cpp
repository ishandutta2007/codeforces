#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
int n, ile[100], a;
vector <int> p;
int sito[100];
int sil[100005], odw[100005];
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
int licz(int c, int d)
{
	if(d > c)
		return 0;
	int res = sil[c];
	res = (ll) res * odw[d] % mod;
	res = (ll) res * odw[c - d] % mod;
	return res;
}
void add(int &a, int b)
{
	a = (a + b) % mod;
}
int dp[2][(1 << 20) + 5];
int main()
{
	scanf("%d", &n);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &a), ile[a]++;
	for(int i = 2; 70 >= i; ++i)
	{
		if(!sito[i])
		{
			p.pb(i);
			for(int j = 2 * i; 70 >= j; j += i)
				sito[j] = 1;
		}
	}
	sil[0] = 1;
	for(int i = 1; n >= i; ++i)
		sil[i] = (ll) sil[i - 1] * i % mod;
	odw[0] = 1;
	for(int i = 1; n >= i; ++i)
		odw[i] = pot(sil[i], mod - 2);
	dp[0][0] = 1;
	for(int i = 1; 70 >= i; ++i)
	{
		int parz = 0, nieparz = 0;
		for(int j = 1; ile[i] >= j; j += 2)
			add(nieparz, licz(ile[i],j));
		for(int j = 2; ile[i] >= j; j += 2)
			add(parz, licz(ile[i], j));
		int maska = 0;
		for(int j = 0; 19 > j; ++j)
		{
			int ile = 0;
			int X = i;
			while(X % p[j] == 0)
			{
				ile++;
				X /= p[j];
			}
			maska |= (1 << j) * (ile & 1);
		}
		for(int j = 0; (1 << 19) > j; ++j)
			{
				add(dp[(i & 1)][j], dp[((i + 1) & 1)][j]);
				int nowa = (j ^ maska);
				add(dp[(i & 1)][nowa], (ll) dp[((i + 1) & 1)][j] * nieparz % mod);
				add(dp[(i & 1)][j], (ll) dp[((i + 1) & 1)][j] * parz % mod);
			}
		for(int j = 0; (1 << 19) > j; ++j)
			dp[((i + 1) & 1)][j] = 0;
	}
	printf("%d", (dp[0][0] - 1 + mod) % mod);
	return 0;
}