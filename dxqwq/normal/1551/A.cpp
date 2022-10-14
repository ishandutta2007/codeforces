// Problem: A. Polycarp and Coins
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/contest/1551/problem/A
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		if(n%3==0)
		printf("%lld %lld\n",n/3,n/3);
		else if(n%3==1)
		printf("%lld %lld\n",n/3+1,n/3);
		else printf("%lld %lld\n",n/3,n/3+1);
	}
	return 0;
}