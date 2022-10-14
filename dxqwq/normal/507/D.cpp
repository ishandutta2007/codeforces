#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int dp[1003][13][103];
int qwq[13];
signed main()
{
	int n=read(),p=read(),m=read();
	for(int i=1; i<10; i++) dp[1][i][i%p]=1,qwq[i]=i%p;
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<10; j++) qwq[j]*=10,qwq[j]%=p,++dp[i+1][j][qwq[j]]; 
		int x=0;
		for(int j=0; j<10; j++) x+=dp[i][j][0];
		x%=m;
		for(int j=0; j<10; j++) dp[i+1][j][0]+=x;
		for(int j=1; j<p; j++)
		{
			x=0;
			for(int k=0; k<10; k++) x+=dp[i][k][j];
			x%=m;
			for(int k=0; k<10; k++) dp[i+1][k][(qwq[k]+j)%p]+=x,dp[i+1][k][(qwq[k]+j)%p]%=m;
		}
	} 
	long long ans=0;
	for(int i=1; i<=9; i++) ans=(ans+dp[n][i][0])%m;
	printf("%lld\n",ans);
	return 0; 
}