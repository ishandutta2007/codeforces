#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 5005;
const ll inf = 1e18;
ll a[nax], b[nax], c[nax], d[nax], n, x[nax];
int pocz, kon;
ll dp[2][nax][2][2];

void mini(ll &a, ll b)
{
	a = min(a, b);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> pocz >> kon;
	up(i, n)
		cin >> x[i];
	up(i, n)
		cin >> a[i];
	up(i, n)
		cin >> b[i];
	up(i, n)
		cin >> c[i];
	up(i, n)
		cin >> d[i];
	
	for(int j = 0; n + 1 >= j; ++j)
		dp[0][j][0][0] = dp[0][j][0][1] = dp[0][j][1][0] = dp[0][j][1][1] = inf;
	ll ans = inf;
	dp[0][0][0][0] = 0;
	for(int i = 1; n >= i; ++i)
	{
		int ja = (i & 1);
		int on = !ja;
		for(int j = 0; n + 1 >= j; ++j)
			dp[ja][j][0][0] = dp[ja][j][0][1] = dp[ja][j][1][0] = dp[ja][j][1][1] = inf;
		for(int j = 0; n >= j; ++j)
		{
			for(int s = 0; 2 > s; ++s)
			{
				for(int k = 0; 2 > k; ++k)
				{
					ll cena = 0;
					if(i != pocz && i != kon)
					{
						// merge
						if(s + k > 0 || j > 0)
						{
							cena = 2 * x[i] + c[i] + a[i];
							mini(dp[ja][j][s][k], dp[on][j + 1][s][k] + cena);
						}
						
						// new vertex
						cena = -2 * x[i] + b[i] + d[i];
						if(j > 0)
						mini(dp[ja][j][s][k], dp[on][j - 1][s][k] + cena);
						
						// new end
						cena = a[i] + d[i];
						if(j > 0 || s > 0)
						mini(dp[ja][j][s][k], dp[on][j][s][k] + cena);
						
						// new start
						cena = b[i] + c[i];
						if(j > 0 || k > 0)
						mini(dp[ja][j][s][k], dp[on][j][s][k] + cena);
						
						// answer
						cena = 2 * x[i] + a[i] + c[i];
						if(i == n && s && k)
							mini(ans, dp[on][0][s][k] + cena);
					}
					else if(i == pocz && s == 0)
					{
						// merge
						cena = x[i] + c[i];
						mini(dp[ja][j][1][k], dp[on][j + 1][s][k] + cena);
						
						// new node
						cena = -x[i] + d[i];
						mini(dp[ja][j][1][k], dp[on][j][s][k] + cena);
						
						cena = x[i] + c[i];
						if(i == n && k)
						{
							mini(ans, dp[on][0][s][k] + cena);
						}
					}
					else if(i == kon && k == 0)
					{
						//merge
						cena = x[i] + a[i];
						mini(dp[ja][j][s][1], dp[on][j + 1][s][k] + cena);
						
						// new node
						cena = -x[i] + b[i];
						mini(dp[ja][j][s][1], dp[on][j][s][k] + cena);
						
						cena = x[i] + a[i];
						if(i == n && s)
							mini(ans, dp[on][0][s][k] + cena);
					}
				}
			}
		}
	}
	cout << ans;
						
							
					
					
						
							
						
		
		
    return 0;
}