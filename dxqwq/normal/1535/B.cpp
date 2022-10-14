// Problem: B. Array Reodering
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
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
bool cmp(int x,int y)
{
	if(!(x&1)) x+=1e9;
	if(!(y&1)) y+=1e9; 
	return x>y;
}
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	for(int i=1; i<=n; ++i) a[i]=read();
    	sort(a+1,a+n+1,cmp);
    	int ans=0;
    	for(int i=1; i<=n; ++i)
    	for(int j=i+1; j<=n; ++j) 
    	{
    		ans+=(__gcd(a[i],a[j]*2)>1);
    	}
    	printf("%d\n",ans);
    }
	return 0;
}