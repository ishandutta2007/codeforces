#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[103],b[103],tot,dp[103][10003];// 
double ans[103];
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) b[i]=read(),a[i]=read(),tot+=a[i];
	memset(dp,0xc0,sizeof(dp));
	for(int i=0; i<=n; i++) dp[i][0]=0;
	for(int i=1; i<=n; i++) for(int j=i; j>=1; j--) for(int k=100*j; k>=b[i]-a[i]; k--)
	dp[j][k]=max(dp[j][k],dp[j-1][k-b[i]+a[i]]+a[i]);
	for(int i=1; i<=n; i++) for(int j=0; j<=100*i; j++) ans[i]=max(ans[i],min((tot-dp[i][j])/2.0,(double)j)+dp[i][j]);
	for(int i=1; i<=n; i++) printf("%.10lf ",ans[i]);
	return 0;
}