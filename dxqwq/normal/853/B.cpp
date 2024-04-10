// Problem: B. Jury Meeting
// Contest: Codeforces - Codeforces Round #433 (Div. 1, based on Olympiad of Metropolises)
// URL: https://codeforces.com/contest/853/problem/B
// Memory Limit: 512 MB
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
struct node
{
	int u,v,w;
}a[1000003];
vector<node> v[1000003];
int f[1000003],g[1000003];
int c[1000003];
signed main()
{
	int n=read(),m=read(),k=read()+1;
	for(int i=1; i<=m; ++i)
	{
		int X=read();
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
		v[X].push_back(a[i]);
	}
	int ans=1e18;
	memset(f,-1,sizeof(f)),memset(g,-1,sizeof(g));
	memset(c,-1,sizeof(c));
	int S=0,C=0;
	for(int i=1; i<=1000000; ++i)
	{
		for(node j:v[i]) if(j.v==0)
		{
			if(c[j.u]==-1)
			{
				S+=j.w,++C,c[j.u]=j.w;
			}
			else if(c[j.u]>j.w)
			{
				S-=c[j.u]-j.w,c[j.u]=j.w;
			}
		}
		if(C==n) f[i]=S;
	}
	S=0,C=0;
	memset(c,-1,sizeof(c));
	for(int i=1000000; i>=1; --i)
	{
		for(node j:v[i]) if(j.u==0)
		{
			if(c[j.v]==-1)
			{
				S+=j.w,++C,c[j.v]=j.w;
			}
			else if(c[j.v]>j.w)
			{
				S-=c[j.v]-j.w,c[j.v]=j.w;
			}
		}
		if(C==n) g[i]=S;
	}
	for(int i=1; i+k<=1000000; ++i) if(f[i]>-1&&g[i+k]>-1)
	{
		ans=min(ans,f[i]+g[i+k]);
	}
	if(ans>1e17) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}