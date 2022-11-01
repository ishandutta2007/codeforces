#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int n,m;
int a[56];
double dp[56][56][56];
double C[56][56];

int main()
{
	cin>>n>>m;
	C[0][0] = 1.0;
	for(int i=1;i<=55;i++)
	{
		C[i][0] = 1.0;
		for(int j=1;j<=i;j++)
		{
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=0;i<=n;i++) dp[0][0][i] = i;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				for(int c=0;c<=j;c++)
				{
					int Max = max(k,(c+a[i]-1)/a[i]);
					dp[i][j][k] += dp[i-1][j-c][Max] * pow(i-1,j-c) / pow(i,j) * C[j][c];
				}
			}
		}
	}
	printf("%.10f\n",dp[m][n][0]);
	return 0;
}