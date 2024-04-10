// Problem: A. Dungeon
// Contest: Codeforces - Educational Codeforces Round 100 (Rated for Div. 2)
// URL: http://codeforces.com/contest/1463/problem/A
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
int a[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	for(int i=1; i<=n; ++i) a[i]=read();
    	int A=0,B=0;
    	for(int i=1; i<=n; i+=2) A+=a[i];
    	for(int i=2; i<=n; i+=2) B+=a[i];
    	if(A>=B)
    	{
    		for(int i=1; i<=n; i++) if(i&1) printf("%lld ",a[i]);
    		else printf("%lld ",1ll);
    	}
    	else
    	{
    		for(int i=1; i<=n; i++) if((i+1)&1) printf("%lld ",a[i]);
    		else printf("%lld ",1ll);
    	}
    	puts("");
    }
	return 0;
}