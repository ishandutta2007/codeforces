#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,head[100001],tot,size[100001],son[100001],ans[100001],maxn,sum,col[100001],cnt[100001];
struct sb
{
	int to,nextn;
}a[200001];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void format(int u,int fa)
{
	size[u]=1;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		format(v,u);
		size[u]+=size[v];
		if(size[v]>size[son[u]])
			son[u]=v;
	}
}
void calc(int u,int fa,int flag,int fbd)
{
	cnt[col[u]]+=flag;
	if(cnt[col[u]]>maxn)
		maxn=cnt[col[u]],sum=col[u];
	else
		if(cnt[col[u]]==maxn)
			sum+=col[u];
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa || v==fbd)
			continue;
		calc(v,u,flag,fbd);
	}
}
void fun(int u,int fa,int type)
{
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa || v==son[u])
			continue;
		fun(v,u,0);
	}
	if(son[u])
		fun(son[u],u,1);
	calc(u,fa,1,son[u]);
	ans[u]=sum;
	if(!type)
		calc(u,fa,-1,0),maxn=0;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		col[i]=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
	}
	format(1,0);
	fun(1,0,0);
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}