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
int n,m,K,father[1000001],size[1000001],z[1000001][2],top,col[500001],pd[500001],ans,cnt,vis[500001];
struct data
{
	int u,v;
}mem[500001];
int cmp(data x,data y)
{
	return col[x.u]<col[y.u] || (col[x.u]==col[y.u] && col[x.v]<col[y.v]);
}
int find(int k)
{
	if(father[k]!=k)
		return find(father[k]);
	return k;
}
void merge(int x,int y,int type)
{
	int ax=find(x),ay=find(y);
	if(ax!=ay)
	{
		if(size[ax]>size[ay])
			swap(ax,ay);
		father[ax]=ay;
		size[ay]+=ax;
		if(type)
		{
			z[++top][0]=ax;
			z[top][1]=ay;
		}
	}
}
void Delete()
{
	while(top)
	{
		int x=z[top][0],y=z[top][1];
		--top;
		size[y]-=size[x];
		father[x]=x;
	}
}
signed main()
{
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i)
	{
		col[i]=read();
		father[i]=i;
		father[i+n]=i+n;
		size[i]=size[i+n]=1;
	}
	for(int i=1;i<=m;++i)
	{
		mem[i].u=read(),mem[i].v=read();
		if(col[mem[i].v]>col[mem[i].u])
			swap(mem[i].u,mem[i].v);
	}
	sort(mem+1,mem+m+1,cmp);
	for(int i=1;i<=m;++i)
		if(col[mem[i].u]==col[mem[i].v])
		{
			merge(mem[i].u,mem[i].v+n,0);
			merge(mem[i].v,mem[i].u+n,0);
		}
	for(int i=1;i<=n;++i)
		if(find(i)==find(i+n))
			if(!pd[col[i]])
				pd[col[i]]=1,++cnt;
	for(int l=1,r;l<=m;l=r+1)
	{
		r=l;
		while(r+1<=m && col[mem[r+1].u]==col[mem[l].u] && col[mem[r+1].v]==col[mem[l].v])
			++r;
		if(col[mem[l].u]==col[mem[l].v])
			continue;
		if(pd[col[mem[l].u]] || pd[col[mem[l].v]])
			continue;
		int flag=0;
		for(int i=l;i<=r;++i)
		{
			merge(mem[i].u,mem[i].v+n,1);
			merge(mem[i].v,mem[i].u+n,1);
			if(find(mem[i].u)==find(mem[i].u+n) || find(mem[i].v)==find(mem[i].v+n))
			{
				flag=1;
				break;
			}
		}
		ans+=flag;
		Delete();
	}
	ans+=cnt*(K-1)-cnt*(cnt-1)/2;
	printf("%lld\n",K*(K-1)/2-ans);
	return 0;
}