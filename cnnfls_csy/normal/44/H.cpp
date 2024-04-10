#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,dp[2][15],sum;
string st;
bool bo=1;
int main()
{
	cin>>st;
	for (i=0;i<=9;i++) dp[0][i]=1;
	for (i=0;i<st.length()-1;i++)
	{
		memset(dp[(i+1)&1],0,sizeof(dp[(i+1)&1]));
		for (j=0;j<=9;j++)
		{
			dp[(i+1)&1][(j+st[i+1]-'0')/2]+=dp[i&1][j];
			if ((j+st[i+1]-'0')&1) dp[(i+1)&1][(j+st[i+1]-'0')/2+1]+=dp[i&1][j];
		}
	}
	for (i=0;i<=9;i++) sum+=dp[(st.length()-1)&1][i];
	for (i=1;i<st.length();i++)
	{
		if (abs(st[i-1]-st[i])>1) bo=0;
	}
	cout<<sum-bo;
	return 0;
}