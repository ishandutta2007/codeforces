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
int n,head[31],tot,deg[31],root,size[31],son[31],zone[31][2],change[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct sb
{
	int to,nextn;
}a[61];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void find(int u,int fa)
{
	size[u]=1;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		find(v,u);
		size[u]+=size[v];
		son[u]=max(son[u],size[v]);
	}
	son[u]=max(son[u],n-size[u]);
	if(son[u]<son[root])
		root=u;
}
void calc(int u,int v,int K,int way)
{
	zone[v][0]=zone[u][0]+change[way][0]*(1ll<<K);
	zone[v][1]=zone[u][1]+change[way][1]*(1ll<<K);
}
void fun(int u,int fa,int fbd,int K)
{
	int bj=0;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		if(bj==fbd)
			++bj;
		bj%=4;
		calc(u,v,K,bj);
		fun(v,u,(bj+2)%4,K-1);
		++bj;
		if(bj==fbd)
			++bj;
		bj%=4;
	}
}
signed main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
		++deg[u];
		++deg[v];
	}
	for(int i=1;i<=n;++i)
		if(deg[i]>4)
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	son[0]=n;
	find(1,0);
	fun(root,0,4,16);
	for(int i=1;i<=n;++i)
		printf("%I64d %I64d\n",zone[i][0],zone[i][1]);
	return 0;
}