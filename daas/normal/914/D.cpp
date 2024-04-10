#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const double eps=1e-6;
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
int n,m,value[500001],tree[2000001],ans;
inline int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
inline void up(int bj)
{
	tree[bj]=gcd(tree[bj*2],tree[bj*2+1]);
}
inline void build(int l,int r,int bj)
{
	if(l==r)
	{
		tree[bj]=value[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	up(bj);
}
inline void cx(int l,int r,int L,int R,int x,int bj)
{
	if(ans>1)
		return;
	if(l==r)
	{
		++ans;
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid && tree[bj*2]%x)
		cx(l,mid,L,R,x,bj*2);
	if(mid<R && tree[bj*2+1]%x)
		cx(mid+1,r,L,R,x,bj*2+1);
}
inline void xg(int l,int r,int zone,int v,int bj)
{
	if(l==zone && r==zone)
	{
		tree[bj]=v;
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid)
		xg(l,mid,zone,v,bj*2);
	else
		xg(mid+1,r,zone,v,bj*2+1);
	up(bj);
}
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
		value[i]=read();
	build(1,n,1);
	m=read();
	for(register int i=1;i<=m;++i)
	{
		int type=read();
		if(type==1)
		{
			int l=read(),r=read(),x=read();
			ans=0;
			cx(1,n,l,r,x,1);
			printf("%s\n",ans<=1?"YES":"NO");
		}
		else
		{
			int zone=read(),v=read();
			xg(1,n,zone,v,1);
		}
	}
	return 0;
}