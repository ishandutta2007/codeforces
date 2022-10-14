// Problem: C. Strange Function
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int LCM(int n,int m)
{
	return n/__gcd(n,m)*m;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),ans=n+n,s=1;
		for(int i=2; s<=n; ++i) 
		{
			s=LCM(s,i);
			ans+=(n/s);
			ans%=p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}