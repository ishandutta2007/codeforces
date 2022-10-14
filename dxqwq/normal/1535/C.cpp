// Problem: C. Unstable String
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[1000003];
int dp[1000003][2];
signed main()
{
    for(int T=read();T--;)
    {
    	scanf("%s",s+1);
    	int n=strlen(s+1);
    	int ans=0;
    	for(int i=0; i<=n; ++i) dp[i][0]=dp[i][1]=0;
    	for(int i=1; i<=n; ++i) 
    	{
    		if(s[i]=='0') dp[i][0]=dp[i-1][1]+1;
    		if(s[i]=='1') dp[i][1]=dp[i-1][0]+1;
    		if(s[i]=='?') 
    		dp[i][1]=dp[i-1][0]+1,
    		dp[i][0]=dp[i-1][1]+1;
    		ans+=dp[i][1],ans+=dp[i][0];
    	}
    	int c=0;
    	for(int i=1; i<=n; ++i)
    	{
    		if(s[i]=='?')
    		{
    			++c;
    		}
    		else
    		{
    			ans-=c*(c+1)/2;
    			c=0;
    		}
    	}
    	ans-=c*(c+1)/2;
    	printf("%lld\n",ans);
    }
	return 0;
}