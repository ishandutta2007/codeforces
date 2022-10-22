#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define For(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 1005, pod = (1 << 17), inf = 1e9 + 5;
char s[3][nax];
int dp[nax][55][55];
int Pref[nax][3][55];
int All[nax][3];
int P[nax];
char slowo[nax];
int id[3];
int n;
void Wio(int n)
{
	P[1] = 0;
	for(int i = 2; n >= i; ++i)
	{
		int k = P[i - 1];
		while(k && slowo[i] != slowo[k + 1])
			k = P[k];
		if(slowo[i] == slowo[k + 1])
			++k;
		P[i] = k;
	}
}
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	scanf("%s %s %s", s[0] + 1, s[1] + 1, s[2] + 1);
	n = strlen(s[0] + 1);
	id[1] = strlen(s[1] + 1);
	id[2] = strlen(s[2] + 1);
	for(int i = 1; 2 >= i; ++i)
	{
		slowo[1] = s[i][1];
		for(int j = 2; id[i] >= j; ++j)
		{
			for(int g = 0; 26 > g; ++g)
			{
				slowo[j] = (char)('a' + g);
				Wio(j);
				Pref[j][i][g] = P[j];
			}
			slowo[j] = s[i][j];
			Wio(j);
			All[j][i] = P[j];
		}
	}
	for(int g = 0; 1000 >= g; ++g)
	for(int i = 0; id[1] >= i; ++i)
		for(int j = 0; id[2] >= j; ++j)
			dp[g][i][j] = -inf;
	dp[0][0][0] = 0;
	for(int i = 0; n > i; ++i)
	{
		for(int j = 0; id[1] > j; ++j)
		{
			for(int k = 0; id[2] > k; ++k)
			{
				if(s[0][i + 1] == '*')
				{
					//cout << "FF";
					for(int a = 0; 26 > a; ++a)
					{
						char lit = (char)('a' + a);
						int nj, nk;
						if(lit == s[1][j + 1])
							nj = j + 1;
						else
							nj = Pref[j + 1][1][a];
						if(lit == s[2][k + 1])
							nk = k + 1;
						else
							nk = Pref[k + 1][2][a];
						int Add = 0;
						if(nj == id[1])
						{
							Add++;
							nj = All[id[1]][1];
						}
						if(nk == id[2])
						{
							Add--;
							nk = All[id[2]][2];
						}	
						dp[i + 1][nj][nk] = max(dp[i + 1][nj][nk], dp[i][j][k] + Add);
						
					}
				}
				else
				{
					char lit = s[0][i + 1];
					int a = lit - 'a';
					int nj, nk;
					if(lit == s[1][j + 1])
						nj = j + 1;
					else
						nj = Pref[j + 1][1][a];
					if(lit == s[2][k + 1])
						nk = k + 1;
					else
						nk = Pref[k + 1][2][a];
					int Add = 0;
					if(nj == id[1])
					{
						Add++;
						nj = All[id[1]][1];
					}
					if(nk == id[2])
					{
						Add--;
						nk = All[id[2]][2];
					}
					dp[i + 1][nj][nk] = max(dp[i + 1][nj][nk], dp[i][j][k] + Add);
				}
			}
		}
	}
	int ans = -inf;
	for(int i = 0; id[1] > i; ++i)
		for(int j = 0; id[2] > j; ++j)
			ans = max(ans, dp[n][i][j]);
	cout << ans;
	
	
	
	
	
	
		
		
	
				
    return 0;
}