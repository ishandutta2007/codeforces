#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 55, mod = 998244353;
int n, m, h;
int dp[nax][nax][nax];
int t[nax][4];
int mam[nax][nax];
void go(int lewo, int prawo)
{
	mam[lewo][prawo] = 1;
	vector <int> v(51);
	for(int g = 0; h >= g; ++g)
		dp[lewo][prawo][g] = -1000000000;
	for(int mid = lewo; prawo >= mid; ++mid)
	{
		for(int j = 0; h >= j; ++j)
			v[j] = 0;
		for(int j = 1; m >= j; ++j)
		{
			if(t[j][0] >= lewo && t[j][0] <= mid  && t[j][1] <= prawo && t[j][1] >= mid)
				v[t[j][2] + 1] += t[j][3];
		}
		for(int j = 0; h >= j; ++j)
			v[j] += (j > 0 ? v[j - 1] : 0);
		for(int val = 0; h >= val; ++val)
		{
			int ile = val * val - v[val];
			if(mid > lewo)
			{
				if(!mam[lewo][mid - 1])
					go(lewo, mid - 1);
				ile += dp[lewo][mid - 1][val];
			}
			if(mid < prawo)
			{
				if(!mam[mid + 1][prawo])
					go(mid + 1, prawo);
				ile += dp[mid + 1][prawo][val];
			}
			dp[lewo][prawo][val] = max(dp[lewo][prawo][val], ile);
		}
		for(int val = 1; h >= val; ++val)
			dp[lewo][prawo][val] = max(dp[lewo][prawo][val], dp[lewo][prawo][val - 1]);
	}
}
	
	
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> h >> m;
	for(int i = 1; m >= i; ++i)
		cin >> t[i][0] >> t[i][1] >> t[i][2] >> t[i][3];
	go(1, n);
	cout << dp[1][n][h];
		
				
			
	return 0;
}