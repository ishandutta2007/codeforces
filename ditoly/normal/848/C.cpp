#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define MN 100000
#define N 131072
set<int> s[MN+5];
int a[MN+5],ls[MN+5],wn,qn,pn;
long long ans[MN+5],t[N*2+5];
struct work{int t,a,b,c;}w[MN*7+5];
struct P{int t,a,b,c,d;}p[MN*14+5];
bool cmp(const P&a,const P&b){return a.a==b.a?a.t<b.t:a.a<b.a;}
void add(int k,int x){for(k+=N;k;k>>=1)t[k]+=x;}
long long query(int l,int r)
{
	long long res=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res+=t[l+1];
		if( r&1)res+=t[r-1];
	}
	return res;
}
void solve(int l,int r)
{
	int mid=l+r>>1,i;
	if(l<r)solve(l,mid),solve(mid+1,r);
	for(pn=0,i=l;i<=mid;++i)if(w[i].t<2)p[++pn]=(P){0,w[i].a,w[i].b,w[i].c,0};
	for(;i<=r;++i)if(w[i].t>1)p[++pn]=(P){1,w[i].a-1,w[i].a,w[i].b,w[i].c},
							  p[++pn]=(P){2,w[i].b,w[i].a,w[i].b,w[i].c};
	sort(p+1,p+pn+1,cmp);
	for(i=1;i<=pn;++i)
	{
		if(p[i].t==0)add(p[i].b,p[i].c);
		if(p[i].t==1)ans[p[i].d]-=query(p[i].b,p[i].c);
		if(p[i].t==2)ans[p[i].d]+=query(p[i].b,p[i].c);
	}
	for(i=1;i<=pn;++i)if(p[i].t==0)add(p[i].b,-p[i].c);
}
int main()
{
	int n,m,i,t,x,y;
	n=read();m=read();
	for(i=1;i<=n;s[a[i]].insert(ls[a[i]]=i),++i)
		if(ls[a[i]=read()])w[++wn]=(work){1,i,ls[a[i]],i-ls[a[i]]};
	for(i=1;i<=m;++i)
	{
		t=read();x=read();y=read();
		if(t==1)
		{
			set<int>::iterator i=s[a[x]].find(x),j=i,k=i;++k;
			if(i!=s[a[x]].begin())
			{
				--j;w[++wn]=(work){1,x,*j,*j-x};
				if(k!=s[a[x]].end())w[++wn]=(work){1,*k,*j,*k-*j};
			}
			if(k!=s[a[x]].end())w[++wn]=(work){1,*k,x,x-*k};
			s[a[x]].erase(i);
			s[a[x]=y].insert(x);
			i=j=k=s[y].find(x);++k;
			if(i!=s[y].begin())
			{
				--j;w[++wn]=(work){1,x,*j,x-*j};
				if(k!=s[y].end())w[++wn]=(work){1,*k,*j,*j-*k};
			}
			if(k!=s[y].end())w[++wn]=(work){1,*k,x,*k-x};
		}
		else w[++wn]=(work){2,x,y,++qn};
	}
	solve(1,wn);
	for(i=1;i<=qn;++i)printf("%I64d\n",ans[i]);
}