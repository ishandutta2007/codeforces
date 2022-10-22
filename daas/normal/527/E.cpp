#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
const int MAXM=3e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,deg[MAXN],z[MAXN],top;
struct node
{
	int st[MAXN],head[MAXN],tot;
	int to[MAXM*2],nextn[MAXM*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed;
int ans[MAXM][2],cnt,pd[MAXM*2];
void fun(int u)
{
	for(int i=Ed.st[u];i!=0;i=Ed.st[u])
	{
		Ed.st[u]=Ed.nextn[i];
		int v=Ed.to[i];
		if(pd[i]) continue;
		pd[i]=pd[i^1]=1;
		fun(v);
		ans[++cnt][0]=u;
		ans[cnt][1]=v;
	}
}
int main()
{
	n=read(),m=read();
	Ed.tot=1;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		Ed.ADD(u,v);
		Ed.ADD(v,u);
		++deg[u];
		++deg[v];
	}
	for(int i=1;i<=n;++i) if(deg[i]&1) z[++top]=i;
	for(int i=1;i<=top;i+=2) Ed.ADD(z[i],z[i+1]),Ed.ADD(z[i+1],z[i]);
	for(int i=1;i<=n;++i) Ed.st[i]=Ed.head[i];
	fun(1);
	printf("%d\n",cnt+cnt%2);
	for(int i=cnt;i>=1;--i)
		if((cnt-i)%2) printf("%d %d\n",ans[i][1],ans[i][0]);
		else printf("%d %d\n",ans[i][0],ans[i][1]);
	if(cnt&1) puts("1 1");
	return 0;
}
//ore no turn,draw!