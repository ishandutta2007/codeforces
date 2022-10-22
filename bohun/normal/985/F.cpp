#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m;
char s[200005];
int last[30];
int t[200005][30];
int sum[200005][30];
const int p = 31;
int mod = 1e9 + 7;
int bylo[30];
int pot[200005];
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	pot[0] = 1;
	for(int i = 1; 200000 >= i; ++i)
		pot[i] = (ll) pot[i - 1] * p % mod;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 0; 30 > i; ++i)
		last[i] = n + 1;
	for(int i = n; i >= 1; i--)
	{
		int l = s[i] - 'a';
		last[l] = i;
		for(int j = 0; 30 > j; ++j)
			t[i][j] = last[j];
	}
	for(int i = 1; n >= i; ++i)
	{
		for(int j = 0; 30 > j; ++j)
			sum[i][j] = (ll) p * sum[i - 1][j] % mod;
		int l = s[i] - 'a';
		sum[i][l]++;
		if(sum[i][l] >= mod)
			sum[i][l] -= mod;
	}
	for(int i = 1; m >= i; ++i)
	{
		int x, y, len;
		scanf("%d%d%d", &x, &y, &len);
		bool ok = 1;
		int xx = x + len - 1;
		int yy = y + len - 1;
		int ile = 0;
		for(int j = 0; 30 > j; ++j)
		{
			if(t[x][j] <= xx)
			{
				ile++;
				int roz = t[x][j] - x;
				int lit = s[y + roz] - 'a';
				if(bylo[lit] == i)
					ok = 0;
				int h1 = (sum[xx][j] - ((ll)sum[x - 1][j] * pot[len]) % mod + mod) % mod;
				int h2 = (sum[yy][lit] - ((ll)sum[y - 1][lit] * pot[len] % mod) + mod) % mod;
				bylo[lit] = i;
				if(h1 != h2)
					ok = 0;
			}
		}
		for(int j = 0; 30 > j; ++j)
		{
			if(t[y][j] <= yy)
				ile--;
		}
		if(!ile and ok)
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}		
	
	
	
	return 0;
}