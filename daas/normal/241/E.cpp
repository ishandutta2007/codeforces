#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
inline int read()
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
int n,m,head[1001],tot,dis[1001],pd[1001],dl[1002],h,t,len,num[1001],vis[1001],headn[1001],totn;
struct sb
{
	int from,to,nextn,l,pd;
}a[10001],an[5001];
inline void ADD(int from,int to,int l)
{
	a[++tot].to=to,a[tot].nextn=head[from],a[tot].from=from,a[tot].l=l;
	head[from]=tot;
}
inline void ADDn(int from,int to)
{
	an[++totn].to=to,an[totn].nextn=headn[from],an[totn].from=from,an[totn].pd=0;
	headn[from]=totn;
}
inline int SPFA()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	h=0,t=1,dl[1]=1;
	while(h!=t)
	{
		h=h%len+1;
		int u=dl[h];
		pd[u]=0;
		for(register int i=head[u];i!=0;i=a[i].nextn)
		{

			int v=a[i].to;
			if(dis[v]>dis[u]+a[i].l)
			{
				num[v]=num[u]+1;
				if(num[v]==n)
				{
					puts("No");
					exit(0);
				}
				dis[v]=dis[u]+a[i].l;
				if(!pd[v])
				{
					pd[v]=1;
					t=t%len+1;
					dl[t]=v;
				}
			}
		}
	}
	return 1;
}
/*dis[u]--->dis[v]
1<=dis[v]-dis[u]
dis[u]<=dis[v]-1
dis[v]-dis[u]<=2
dis[v]<=dis[u]+2*/
inline void fun(int u)
{
	vis[u]=1;
	for(register int i=headn[u];i!=0;i=an[i].nextn)
	{
		int v=an[i].to;
		if(!vis[v])
			fun(v);
		if(vis[v]==2)
		{
			an[i].pd=1;
			vis[u]=2;
		}
	}
}
int main()
{
	n=read(),m=read();
	len=n+1;
	for(register int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		ADDn(u,v);
	}
	vis[n]=2;
	fun(1);
	for(register int i=headn[n];i!=0;i=an[i].nextn)
		if(vis[an[i].to]==2)
		{
			puts("No");
			return 0;
		}
	for(register int i=1;i<=m;++i)
		if(an[i].pd)
		{
			ADD(an[i].from,an[i].to,2);
			ADD(an[i].to,an[i].from,-1);
		}
	SPFA();
	if(dis[n]==0x3f3f3f3f)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(register int i=1;i<=m;++i)
		if(an[i].pd)
			printf("%d\n",dis[an[i].to]-dis[an[i].from]);
		else
			puts("1");
	return 0;
}