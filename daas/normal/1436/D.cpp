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
int n,head[200001],tot,maxn[200001],sum[200001],cnt[200001],value[200001];
struct sb
{
	int to,nextn;
}a[200001];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void fun(int u)
{
	int flag=0;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		fun(v);
		cnt[u]+=cnt[v];
		sum[u]+=sum[v];
		maxn[u]=max(maxn[u],maxn[v]);
		flag=1;
	}
	if(!flag)
		cnt[u]=1,sum[u]=maxn[u]=value[u];
	else
	{
		int Need=maxn[u]*cnt[u]-sum[u];
		sum[u]+=value[u];
		if(Need<value[u])
		{
			value[u]-=Need;
			maxn[u]+=value[u]/cnt[u];
			if(value[u]%cnt[u])
				++maxn[u];
		}
	}
}
signed main()
{
	n=read();
	for(int i=2;i<=n;++i)
	{
		int fa=read();
		ADD(fa,i);
	}
	for(int i=1;i<=n;++i)
		value[i]=read();
	fun(1);
	printf("%I64d\n",maxn[1]);
	return 0;
}