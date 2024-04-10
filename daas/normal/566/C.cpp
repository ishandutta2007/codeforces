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
int n,num[200001],head[200001],tot,pd[200001],size[200001],son[200001],root,all,ans1;
double ans2=-1,D[200001],sum;
struct sb
{
	int to,nextn,l;
}a[400001];
inline void ADD(int from,int to,int l)
{
	a[++tot].to=to,a[tot].nextn=head[from],a[tot].l=l;
	head[from]=tot;
}
inline void find(int u,int fa)
{
	size[u]=1,son[u]=0;
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa || pd[v])
			continue;
		find(v,u);
		size[u]+=size[v];
		son[u]=max(son[u],size[v]);
	}
	son[u]=max(son[u],all-size[u]);
	if(son[u]<son[root])
		root=u; 
}
inline void dfs(int u,int fa,int dis)
{
	D[u]=(double)num[u]*sqrt(dis);
	sum+=(double)num[u]*sqrt(dis)*dis;
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		dfs(v,u,dis+a[i].l);
		D[u]+=D[v];
	}
}
inline void fun(int u)
{
	pd[u]=1;
	sum=0;
	dfs(u,0,0);
	if(sum<ans2 || ans2==-1)
		ans1=u,ans2=sum;
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(pd[v] || D[u]-2*D[v]>=0)
			continue;
		all=size[v];
		root=0;
		find(v,u);
		fun(root);
		break;
	}
}
signed main()
{
	n=read();
	for(register int i=1;i<=n;++i)
		num[i]=read(); //363465134
	for(register int i=1;i<n;++i)
	{
		int u=read(),v=read(),l=read();
		ADD(u,v,l);
		ADD(v,u,l);
	}
	son[0]=0x3f3f3f3f3f3f3f3f;
	all=n;
	find(1,0);
	fun(root);
	printf("%lld %.18lf\n",ans1,ans2);
	return 0;
}