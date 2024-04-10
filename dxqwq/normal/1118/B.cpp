// Problem: B. Tanya and Candies
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/contest/1118/problem/B
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
int a[1000003],b0[1000003],b1[1000003];
int c0,c1;
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i)
	{
		b0[i]=b0[i-1];
		b1[i]=b1[i-1];
		if(i&1) b1[i]+=a[i];
		else b0[i]+=a[i];
	}
	int cnt=(b0[n-1]==b1[n-1]);
	for(int i=n; i>=2; --i)
	{
		if((i-1)&1) c1+=a[i];
		else c0+=a[i];
		if(c0+b0[i-2]==c1+b1[i-2]) ++cnt;
	}
	printf("%lld\n",cnt);
	return 0;
}