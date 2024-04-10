// Problem: E. Phoenix and Computers
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int p;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int C[1003][1003];
int dp[403][403];
int Q[1003];
// i  j 
signed main()
{
    int n=read();p=read();
    for(int i=1; i<=1000; ++i) 
    Q[i]=qp(2,i-1);
    C[0][0]=1;
    for(int i=1; i<=1000; ++i)
    {
    C[i][0]=1;
    for(int j=1; j<=i; ++j) 
    C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
    }
    dp[1][1]=1;
    for(int i=1; i<=n; ++i)
    {
    	dp[i][i]=qp(2,i-1);
    	for(int j=i; j>=3; --j)
    	for(int l=i-j+1,k=1; k<=j-2; ++k)
    	(dp[i][k+l]+=dp[j-2][k]*Q[l]%p*C[k+l][k]%p)%=p;
    }
    int ans=0;
    for(int i=1; i<=n; ++i) (ans+=dp[n][i])%=p;
	printf("%lld\n",ans);
	return 0;
}