#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0(i,n) for (i=0;i<n;i++)
#define fd0(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int dp[30005][605];
int n,m,i,j,x,cnt[30005],ans;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		cnt[x]++;
	}
	memset(dp,-22,sizeof(dp));
	dp[m][300]=cnt[m];
	for (i=m;i<=30000;i++)
	{
		fz1(j,600)
		{
			ans=max(ans,dp[i][j]);
			int t=max(300-m+1,j-1);
			if (i+t+m-300<=30000) dp[i+t+m-300][t]=max(dp[i+t+m-300][t],dp[i][j]+cnt[i+t+m-300]);
			t=max(300-m+1,j);
			if (i+t+m-300<=30000) dp[i+t+m-300][t]=max(dp[i+t+m-300][t],dp[i][j]+cnt[i+t+m-300]);
			t=max(300-m+1,j+1);
			if (i+t+m-300<=30000) dp[i+t+m-300][t]=max(dp[i+t+m-300][t],dp[i][j]+cnt[i+t+m-300]);
		}
		///dp[i].clear();
	}
	cout<<ans;
	return 0;
}