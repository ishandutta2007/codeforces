#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int n,root,head[1000001],tot,value[1000001],size[1000001],Need,ans1,ans2,deep[1000001];
struct sb
{
	int to,nextn;
}a[1000001];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void format(int u)
{
	size[u]=value[u];
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		deep[v]=deep[u]+1;
		format(v);
		size[u]+=size[v];
	}
}
void fun(int u)
{
	if(ans2)
		return;
	size[u]=value[u];
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==ans1)
			continue;
		fun(v);
		if(ans2)
			return;
		size[u]+=size[v];
	}
	if(u!=root && size[u]==Need)
		ans2=u;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int fa=read();
		if(!fa)
			root=i;
		else
			ADD(fa,i);
		value[i]=read();
	}
	format(root);
	if(size[root]%3)
	{
		puts("-1");
		return 0;
	}
	Need=size[root]/3;
	for(int i=1;i<=n;++i)
		if(i!=root && size[i]==Need)
		{
			if(!ans1)
				ans1=i;
			else
				if(deep[i]>deep[ans1])
					ans1=i;
		}
	if(!ans1)
	{
		puts("-1");
		return 0;
	}
	fun(root);
	if(ans2)
		printf("%d %d\n",ans1,ans2);
	else
		puts("-1");
	return 0;
}