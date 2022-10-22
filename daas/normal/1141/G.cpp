#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		x=-1,c=getchar();
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,k,head[200001],tot,root,maxn,ans[200001],degree[200001];
struct sb
{
	int to,nextn;
}a[400001];
inline void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
inline void fun(int u,int fa,int col)
{
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		++col;
		if(col>maxn)
			col=1;
		ans[(i+1)/2]=col;
		fun(v,u,col);
	}
}
int main()
{
	n=read(),k=read();
	for(register int i=1;i<n;++i)
	{
		int u=read(),v=read();
		++degree[u];
		++degree[v];
		ADD(u,v);
		ADD(v,u);
	}
	sort(degree+1,degree+n+1);
	maxn=degree[n-k];
	printf("%d\n",maxn);
	fun(1,0,0);
	for(register int i=1;i<n;++i)
		printf("%d ",ans[i]);
	return 0;
}