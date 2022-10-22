#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
vector <int> primes;
int sito[105], rep[105];
int dp[105][(1 << 18)];
const int inf = 1e9;
int wynik = inf;
int opt[105][(1 << 18)];
int main()
{
	int n, t[105];	
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> t[i];
	for(int i = 2; 60 >= i; ++i)
	{
		if(sito[i] == 0)
		{
			primes.pb(i);
			for(int j = 2 * i; 60 >= j; j += i)
				sito[j] = 1;
		}
	}
	for(int i = 1; 60 >= i; ++i)
	{
		int sum = 0;
		for(int j = 0; ss(primes) > j; ++j)
			if(i % primes[j] == 0)
				sum += (1 << j);
		rep[i] = sum;
	}
	for(int i = 0; n >= i; ++i)
		for(int maska = 0; (1 << 18) > maska; maska++)
			dp[i][maska] = inf;
	dp[0][0] = 0;
	for(int i = 1; n >= i; ++i)
	{
		
		for(int g = 1; 60 >= g; ++g)
		for(int j = 0; (1 << 18) > j; ++j)
		{
			if((rep[g] & j) == rep[g])
			{
				if(dp[i][j] > dp[i - 1][(j ^ rep[g])] + abs(t[i] - g))
					opt[i][j] = g;
				dp[i][j] = min(dp[i][j], dp[i - 1][(j ^ rep[g])] + abs(t[i] - g));
			}
		}	
	}
	int poz = -1;
	for(int i = 0; (1 << 18) > i; ++i)
		if(wynik > dp[n][i])
			{
				wynik = min(wynik, dp[n][i]);
				poz = i;
			}
	vector <int> res (n + 1);
	for(int i = n; i >= 1; --i)
	{
		res[i] = opt[i][poz];
		poz ^= rep[res[i]];
	}
	for(int i = 1; n >= i; ++i)
		cout << res[i] << " ";
	
			
		
	return 0;
}