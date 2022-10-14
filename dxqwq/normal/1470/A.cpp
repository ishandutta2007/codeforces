// Problem: A. Strange Birthday Party
// Contest: Codeforces - Codeforces Round #694 (Div. 1)
// URL: https://codeforces.com/contest/1470/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1000003],b[1000003];
signed main()
{
    for(int T=read(); T--;)
    {
    	int n=read(),m=read();
    	for(int i=1; i<=n; i++) a[i]=read();
    	for(int i=1; i<=m; i++) b[i]=read();
    	sort(a+1,a+n+1);
    	int ans=0;
    	for(int i=n,t=1; i>=1; i--)
    	{
    		if(a[i]>t)
    		{
    			ans+=b[t++];
    		}
    		else ans+=b[a[i]];
    	}
    	printf("%lld\n",ans);
    }
	return 0;
}