// Problem: A. Phoenix and Gold
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[100003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read(),s=read(),x=0;
    	for(int i=1; i<=n; ++i) a[i]=read(),x+=a[i];
    	if(x==s)
    	{
    		puts("NO");
    		continue;
    	}
    	sort(a+1,a+n+1);
    	int S=0;
    	puts("YES");
    	for(int i=1; i<=n; ++i)
    	{
    		S+=a[i];
    		if(S==s)
    		{
    			printf("%lld ",a[n]);
    			for(int j=i; j<n; ++j) printf("%lld ",a[j]);
    			break;
    		}
    		else printf("%lld ",a[i]);
    	}
    	puts("");
    }
	return 0;
}