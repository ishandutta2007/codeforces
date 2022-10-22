#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,l[101],r[101],dp[101][100001],dl[100001],h,t;
int main()
{
	n=read(),K=read();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=K;++i)
	{
		l[i]=read(),r[i]=read();
		int len=r[i]-l[i],L=l[i]-r[i-1];
		for(int j=0;j<=n;++j) if(j-(r[i]-r[i-1])>=0) dp[i][j]=dp[i-1][j-(r[i]-r[i-1])];
		h=t=0;
		for(int j=0;j<=n;++j)
		{
			if(j-L>=0)
			{
				while(h<t && dp[i-1][dl[t]]>=dp[i-1][j-L]) --t;
				dl[++t]=j-L;
			}
			while(h<t && j-L-dl[h+1]>len) ++h;
			if(r[i]-j>=0 && r[i]-j<=n && h!=t) dp[i][r[i]-j]=min(dp[i][r[i]-j],dp[i-1][dl[h+1]]+1);
			/*if(j-L>=0)
			{
				while(h<t && dp[i-1][dl[t]]>=dp[i-1][j-L]) --t;
				dl[++t]=j-L;
			}*/
		}
		L=r[i]-r[i-1];
		h=t=0;
		for(int j=0;j<=n;++j)
		{
			if(j+len-L>=0)
			{
				while(h<t && dp[i-1][dl[t]]>=dp[i-1][j+len-L]) --t;
				dl[++t]=j+len-L;
			}
			while(h<t && dl[h+1]+L-j<1) ++h;
			if(h!=t) dp[i][j]=min(dp[i][j],dp[i-1][dl[h+1]]+2);
			/*if(j+len-L>=0)
			{
				while(h<t && dp[i-1][dl[t]]>=dp[i-1][j+len-L]) --t;
				dl[++t]=j+len-L;
			}*/
		}
		//for(int j=0;j<=n;++j) cout<<dp[i][j]<<" ";
		//cout<<endl;
	}
	if(n-(2*n-r[K])>=0 && dp[K][n-(2*n-r[K])]!=0x3f3f3f3f)
	{
		puts("Full");
		printf("%d\n",dp[K][n-(2*n-r[K])]);
	}
	else puts("Hungry");
	return 0;
}