// Problem: C. Subordinates
// Contest: Codeforces - Codeforces Round #380 (Div. 1, Rated, Based on Technocup 2017 - Elimination Round 2)
// URL: https://codeforces.com/contest/737/problem/C
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
int n=read(),s=read();
int a[1000003];
int pre[1000003];
signed main()
{
	int F=0;
	for(int i=1; i<=n; ++i) 
	if(i!=s)
	{
		int x=read();
		if(x==0) x=n+1;
		++a[x];
	}
	else
	{
		int x=read();
		if(x!=0) F=1;
	}
	pre[0]=a[0]=1;
	for(int i=1; i<=n; ++i) pre[i]=pre[i-1]+a[i];
	int ans=9999999;
	for(int i=0,s=0; i<=n; ++i)
	{
		s+=(a[i]==0);
		ans=min(ans,max(s,n-pre[i]));
	}
	printf("%lld\n",ans+F);
	return 0;
}