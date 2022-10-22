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
int n,l,r,ans[100001],a[100001],c[100001];
struct data
{
	int l,r,id,Key;
}mem[100001];
int cmp(data x,data y)
{
	return x.Key<y.Key;
}
int main()
{
	n=read(),l=read(),r=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
	{
		mem[i].Key=read();
		mem[i].l=l-a[i];
		mem[i].r=r-a[i];
		mem[i].id=i;
	}
	sort(mem+1,mem+n+1,cmp);
	ans[mem[1].id]=mem[1].l;
	int maxn=mem[1].l;
	for(int i=2;i<=n;++i)
	{
		if(maxn>=mem[i].r)
		{
			puts("-1");
			return 0;
		}
		ans[mem[i].id]=max(maxn+1,mem[i].l);
		maxn=ans[mem[i].id];
	}
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]+a[i]);
	putchar('\n');
	return 0;
}