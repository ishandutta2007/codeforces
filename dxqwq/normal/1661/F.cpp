// Problem: F. Teleporters
// Contest: Codeforces - Educational Codeforces Round 126 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1661/problem/F
// Memory Limit: 512 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node
{
	int x,d,g;
	bool operator<(const node&t)const{return g<t.g;}
};
priority_queue<node> q;
inline int F(int x,int y)
{
	int v0=x/y,v1=v0+1,k1=x-v0*y,k0=y-k1;
	return v1*v1*k1+v0*v0*k0;
}
int a[1000003];
signed main()
{
	int n=read(),ans=0,sum=0;
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=n; i>=1; --i) a[i]-=a[i-1],sum+=a[i]*a[i];
	for(int i=1; i<=n; ++i) if(a[i]>1)
		q.push((node){a[i],1,F(a[i],1)-F(a[i],2)});
	sum-=read();
	while(sum>0)
	{
		node t=q.top();q.pop();
		if(t.x/t.d!=t.x/(t.d+1))
		{
			sum-=t.g,++ans,++t.d,
			t.g=F(t.x,t.d)-F(t.x,t.d+1);
			if(t.g) q.push(t);
			continue;
		}
		int tmp=t.x/(t.x/t.d);
		if(t.g*(tmp-t.d)>=sum)
		{
			ans+=(sum-1)/t.g+1;
			break;
		}
		else sum-=t.g*(tmp-t.d),ans+=tmp-t.d,
		t.d=tmp,t.g=F(t.x,t.d)-F(t.x,t.d+1);
		if(t.g) q.push(t);
	}
	printf("%lld\n",ans);
	return 0;
}