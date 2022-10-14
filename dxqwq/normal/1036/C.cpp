// Problem: C. Classy Numbers
// Contest: Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1036/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int dp[103][13],num[103];
int dfs(int d,int cnt,int flag)
{
	if(cnt>3) return 0;
	if(d<0) return 1;
	if(flag)
	{
		int ans=0;
		for(int i=0; i<=num[d]; i++) 
		{
			ans+=dfs(d-1,cnt+(i>0),(i==num[d]));
		}
		return ans;
	}
	else
	{
		if(dp[d][cnt]) return dp[d][cnt];
		if(cnt==3) return 1;int ans=0;
		for(int i=0; i<=9; ++i)
		{
			ans+=dfs(d-1,cnt+(i>0),0);
		}
		return dp[d][cnt]=ans;
	}
}
int solve(int x)
{
	int d=0;
	while(x)
	{
		num[d++]=x%10;
		x/=10;
	}
	return dfs(d-1,0,1);
}
signed main()
{
    for(int T=read(); T--;)
    {
    	int l=read(),r=read();
    	printf("%lld\n",solve(r)-solve(l-1));
    }
	return 0;
}