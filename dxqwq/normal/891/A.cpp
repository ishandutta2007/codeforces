// Problem: A. Pride
// Contest: Codeforces - Codeforces Round #446 (Div. 1)
// URL: https://codeforces.com/contest/891/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[1000003];
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=1; i<=n; i++) if(a[i]==1)
    {
    	int ans=n;
    	for(int j=1; j<=n; j++) if(a[j]==1) --ans;
    	printf("%lld\n",ans);
    	return 0;
    }
    int ans=1000000;
    for(int i=1; i<=n; i++)
    {
    	int g=a[i];
    	for(int j=i+1,k=1; j<=n; j++,++k)
    	{
    		g=__gcd(g,a[j]);
    		if(g==1)
    		{
    			ans=min(ans,k);
    		}
    	}
    }
    if(ans==1000000) puts("-1"),exit(0);
    ans+=n-1;
    printf("%lld\n",ans);
	return 0;
}