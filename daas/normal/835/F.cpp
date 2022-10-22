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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,head[200001],tot=1,deg[200001],dl[200001],h,t,maxn[200001],deep[200001],z[200010],top,sum[200010],ans,pre[200001],suf[200001],value[200001];
struct node
{
	int to,nextn,l;
}a[400010];
void ADD(int from,int to,int l)
{
	a[++tot].to=to,a[tot].nextn=head[from],a[tot].l=l;
	head[from]=tot;
}
void pick(int u,int from)
{
	ans=max(ans,maxn[u]);
	z[++top]=u;
	deg[a[from].to]=1;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(deg[v]==1 || i==(from^1)) continue;
		sum[top+1]=sum[top]+a[i].l;
		pick(v,i);
		break;
	}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int u=read(),v=read(),l=read();
		ADD(u,v,l);
		ADD(v,u,l);
		++deg[u];
		++deg[v];
	}
	for(int i=1;i<=n;++i) if(deg[i]==1) dl[++t]=i;
	while(h!=t)
	{
		int u=dl[++h];
		for(int i=head[u];i!=0;i=a[i].nextn)
		{
			int v=a[i].to;
			if(deg[v]==1) continue;
			maxn[v]=max(maxn[v],max(maxn[u],deep[v]+deep[u]+a[i].l));
			deep[v]=max(deep[v],deep[u]+a[i].l);
			--deg[v];
			if(deg[v]==1) dl[++t]=v;
		}
	}
	for(int i=1;i<=n;++i) if(deg[i]!=1) {pick(i,0);break;}
	int maxn=-0x3f3f3f3f3f3f3f3f,mem=-0x3f3f3f3f3f3f3f3f;
	memset(value,-0x3f,sizeof(value));
	memset(pre,-0x3f,sizeof(pre));
	memset(suf,-0x3f,sizeof(suf));
	for(int i=1;i<top;++i)
	{
		mem=max(mem,maxn+deep[z[i]]+sum[i]);
		value[i]=mem;
		maxn=max(maxn,deep[z[i]]-sum[i]);
		pre[i]=max(pre[i-1],deep[z[i]]+sum[i]);
	}
	maxn=mem=-0x3f3f3f3f3f3f3f3f;
	for(int i=top-2;i>=1;--i)
	{
		mem=max(mem,maxn+deep[z[i+1]]-sum[i+1]);
		value[i]=max(value[i],mem);
		maxn=max(maxn,deep[z[i+1]]+sum[i+1]);
		suf[i]=max(suf[i+1],deep[z[i+1]]-sum[i+1]);
	}
	int cans=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<top;++i) value[i]=max(value[i],pre[i]+suf[i]+sum[top]),cans=min(cans,value[i]);
	printf("%lld\n",max(ans,cans));
	return 0;
}