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
int n,m,i,j,num[500005],dp[5005];
string st;
vector<int> bi[500005];
int main()
{
	scanf("%d",&n);
	dp[1]=1;dp[2]=1;num[1]=1;
	for (i=3;i<=5000;i++) 
	{
		dp[i]=dp[i-1]+dp[i-2];
		if (dp[i]>10000) break;
		num[dp[i]]=1;
	}
	for (i=1;i<=n;i++) printf("%c",num[i]?'O':'o');
	return 0;
}