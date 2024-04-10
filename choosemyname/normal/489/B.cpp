#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int dp[110][110];
int a[110],b[110];
int main()
{
	int n,m,n1,n2;
	cin>>n;
	for(n1=1;n1<=n;n1++)
		cin>>a[n1];
	cin>>m;
	for(n2=1;n2<=m;n2++)
		cin>>b[n2];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(n1=1;n1<=n;n1++)
		for(n2=1;n2<=m;n2++)
		{
			dp[n1][n2]=max(dp[n1][n2-1],dp[n1-1][n2]);
			if(abs(a[n1]-b[n2])<=1)
				dp[n1][n2]=max(dp[n1][n2],dp[n1-1][n2-1]+1);
		}
	cout<<dp[n][m];
}