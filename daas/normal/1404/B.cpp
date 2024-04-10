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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,A,B,da,db,head[100001],tot,deep[100001],maxn[100001];
struct node
{
	int to,nextn;
}a[200001];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void fun(int u,int fa)
{
	deep[u]=deep[fa]+1;
	maxn[u]=u;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa) continue;
		fun(v,u);
		if(deep[maxn[v]]+1>deep[maxn[u]]) maxn[u]=maxn[v];
	}
}
int main()
{
	T=read();
	deep[0]=-1;
	while(T--)
	{
		n=read(),A=read(),B=read(),da=read(),db=read();
		for(int i=1;i<=n;++i) head[i]=0;
		tot=0;
		for(int i=1;i<n;++i)
		{
			int u=read(),v=read();
			ADD(u,v);
			ADD(v,u);
		}
		if(db<=2*da)
		{
			puts("Alice");
			continue;
		}
		fun(A,0);
		if(deep[B]<=da)
		{
			puts("Alice");
			continue;
		}
		int id=maxn[A];
		fun(id,0);
		if(deep[maxn[id]]>2*da) puts("Bob");
		else puts("Alice");
	}
	return 0;
}