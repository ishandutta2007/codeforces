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
const int nax = 105;
const ll inf = 1e18;
int n, m;
vector <pair<int, char>> v[nax];
char c;
bool dp[nax][nax][30];
bool jest[nax][nax][30];

bool go(int a, int b, int ile)
{
	if(jest[a][b][ile])
		return dp[a][b][ile];
	if(!ss(v[a]))
	{
		jest[a][b][ile] = 1;
		return dp[a][b][ile] = 0;
	}
	for(auto it: v[a])
	{
		int c = it.se - 'a' + 1;
		if(c >= ile)
		{
			dp[a][b][ile] |= !go(b, it.fi, c);
		}
	}
	jest[a][b][ile] = 1;
	return dp[a][b][ile];
}
	

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; m >= i; ++i)
	{
		int a, b;
		cin >> a >> b >> c;
		v[a].pb({b, c});
	}
	
	for(int i = 1; n >= i; ++i)
	{
		for(int j = 1; n >= j; ++j)
			cout << (go(i, j, 0)== 1 ? 'A' : 'B');
		cout << endl;
	}
					
					
						
							
						
		
		
    return 0;
}