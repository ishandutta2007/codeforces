// Problem: B. Mislove Has Lost an Array
// Contest: Codeforces - Codeforces Round #581 (Div. 2)
// URL: https://codeforces.com/contest/1204/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
signed main()
{
	int n=read(),l=read(),r=read();
	int c=1,mn=0,mx=0;
	for(int i=1; i<=l; ++i,c<<=1)
	{
		mn+=c;
	}
	mn+=(n-l);
	c=1;
	for(int i=1; i<=r; ++i,c<<=1)
	{
		mx+=c;
	}
	c>>=1;
	mx+=(n-r)*c;
	printf("%lld %lld\n",mn,mx);
	return 0;
}