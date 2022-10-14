// Problem: F. Souvenirs
// Contest: Codeforces - Codeforces Round #397 by Kaspersky Lab and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/problemset/problem/765/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node
{
	int id,val;
	bool operator<(const node&t){return val<t.val;}
}c[110003];
int a[110003];
#ifdef local
const int B=2;
#else
const int B=320;
#endif
int g[330];
int t[660],ta[330],tb[330];
int dis[330][110003];
//ij
signed main()
{
	int n=read(),S=n/B;
	for(int i=1; i<=n; ++i) a[i]=c[i].val=read();
	for(int i=0; i<(S+1)*B; ++i) c[i].id=i;
	for(int i=0; i<=S; ++i) sort(c+i*B,c+(i+1)*B);
	memset(g,0x3f,sizeof(g)),memset(dis,0x3f,sizeof(dis));
	for(int i=1; i<S; ++i)
	{
		int nl=i*B,nr=(i+1)*B;
		for(int j=i-1; j>=0; --j)
		{
			int tl=j*B,tr=(j+1)*B;
			for(int k=tl,pos=nl; k<tr; ++k)
			{
				while(pos<nr&&c[k].val>c[pos].val) ++pos;
				(pos!=nr&&dis[i][c[k].id]>c[pos].val-c[k].val)&&(dis[i][c[k].id]=c[pos].val-c[k].val),
				(pos!=nl&&dis[i][c[k].id]>c[k].val-c[pos-1].val)&&(dis[i][c[k].id]=c[k].val-c[pos-1].val);
			}
			for(int k=tr-1; k>=tl; --k)
				(dis[i][k]>dis[i][k+1])&&(dis[i][k]=dis[i][k+1]);
		}
		for(int j=i+1; j<=S; ++j)
		{
			int tl=j*B,tr=(j+1)*B;
			for(int k=tl,pos=nl; k<tr; ++k)
			{
				while(pos<nr&&c[k].val>c[pos].val) ++pos;
				(pos!=nr&&dis[i][c[k].id]>c[pos].val-c[k].val)&&(dis[i][c[k].id]=c[pos].val-c[k].val),
				(pos!=nl&&dis[i][c[k].id]>c[k].val-c[pos-1].val)&&(dis[i][c[k].id]=c[k].val-c[pos-1].val);
			}
			for(int k=tl; k<tr; ++k)
				(dis[i][k]>dis[i][k-1])&&(dis[i][k]=dis[i][k-1]);
		}
	}
	for(int i=1; i<S; ++i)
		for(int j=i*B+1,tmp=(i+1)*B; j<tmp; ++j)
			(g[i]>c[j].val-c[j-1].val)&&(g[i]=c[j].val-c[j-1].val);
	for(int T=read(); T--;)
	{
		int l=read(),r=read();
		if(l/B==r/B)
		{
			int lst=-1000000000,ans=1000000000;
			for(int i=(l/B)*B,tmp=(l/B+1)*B; i<tmp; ++i)
				(l<=c[i].id&&c[i].id<=r)&&((ans>c[i].val-lst)&&(ans=c[i].val-lst),lst=c[i].val);
			printf("%d\n",ans);
		}
		else
		{
			int ans=1000000000;
			for(int i=l/B+1; i<r/B; ++i) 
				(ans>g[i])&&(ans=g[i]);
			for(int i=l/B+1; i<r/B; ++i) 
				(ans>dis[i][l])&&(ans=dis[i][l]),
				(ans>dis[i][r])&&(ans=dis[i][r]);
			int ca=1,cb=1,len=0,tas=0,tbs=0;
			for(int i=(l/B)*B,tmp=(l/B+1)*B; i<tmp; ++i)
				(c[i].id>=l)&&(ta[++tas]=c[i].val);
			for(int i=(r/B)*B,tmp=(r/B+1)*B; i<tmp; ++i)
				(c[i].id<=r)&&(tb[++tbs]=c[i].val);
			while(ca<=tas&&cb<=tbs)
				(ta[ca]<tb[cb])?(t[++len]=ta[ca],++ca):(t[++len]=tb[cb],++cb);
			while(ca<=tas) t[++len]=ta[ca],++ca;
			while(cb<=tbs) t[++len]=tb[cb],++cb;
			for(int i=2; i<=len; ++i) (ans>t[i]-t[i-1])&&(ans=t[i]-t[i-1]);
			printf("%d\n",ans);
		}
	}
	return 0;
}