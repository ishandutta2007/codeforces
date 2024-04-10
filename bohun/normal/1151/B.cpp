#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 505;
int n, t[nax][nax];
int opt[nax][2];
int m;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
		for(int j = 1; m >= j; ++j)
			cin >> t[i][j];
	for(int bit = 0; bit < 10; ++bit)
	{
		int w = (1 << bit);
		int dp[2];
		dp[0] = 1;
		dp[1] = 0;
		for(int i =  1; n >= i; ++i)
		{
			int ndp[2];
			ndp[0] = ndp[1] = 0;
			for(int j = 1; m >= j; ++j)
			{
				if(w & t[i][j])
				{
					if(dp[0])
						ndp[1] = 1, opt[i][1] = j;
					if(dp[1])
						ndp[0] = 1, opt[i][0] = j;
				}
				else
				{
					if(dp[0])
						ndp[0] = 1, opt[i][0] = j;
					if(dp[1])
						ndp[1] = 1, opt[i][1] = j;
				}
			}
			dp[0] = ndp[0];
			dp[1] = ndp[1];
		}
		if(dp[1])
		{
			cout << "TAK\n";
			int ile = n;
			int mam = 1;
			vector <int> ww;
			while(ile)
			{
				ww.pb(opt[ile][mam]);
				mam ^= ((t[ile][opt[ile][mam]] & w) > 0);
				ile--;
			}
			reverse(ww.begin(), ww.end());
			for(auto it: ww)
				printf("%d ", it);
				
			
			return 0;
		}
		
	}
	cout << "NIE\n";
			
		
	
			
	return 0;
}