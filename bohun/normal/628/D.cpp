#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int m, d;
string a, b;
const int mod = 1e9+7;
int dp[2005][2005][2];
void add(int& a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}
int solve(string x)
{
	int n = (int)x.size();
	for(int i = 0; n >= i; i++)
		for(int j = 0; m > j; j++)
			for(int k = 0; 2 > k; ++k)
				dp[i][j][k] = 0;
	dp[0][0][1] = 1;
	for(int i = 0; n > i; ++i)
		for(int j = 0; m > j; ++j)
			for(int k = 0; 2 > k; ++k)
				for(int c = 0; (k ? x[i] - '0' : 9) >= c; ++c)
					{
						if((i & 1) && c != d)
							continue;
						if(!(i & 1) && c ==d)
							continue;
						if(!i && !c)
							continue;
						int nj = (10 * j + c) % m;
						int ni = i + 1;
						int nk = (k == 1 && c == x[i] - '0');
						add(dp[ni][nj][nk], dp[i][j][k]);
					}
	return (dp[n][0][0] + dp[n][0][1]) % mod;
}					
bool god(string x)
{
	int sum = 0;
	for(int i = 0; (int)x.size() > i; i++)
	{
		int p = x[i] - '0';
		if((i & 1) &&  p != d)
			return false;
		if(!(i & 1) && p == d)
			return false;
		sum = (10 * sum + p) % m;
	}
	return sum == 0;
}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	cin >> m >> d >> a >> b;
	cout << (solve(b) - solve(a) + god(a) + mod) % mod;
	return 0;	
}