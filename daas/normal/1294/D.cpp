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
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,num,tree[1600001],value[400001];
inline void build(int l,int r,int bj)
{
	if(l==r)
	{
		tree[bj]=l;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	tree[bj]=tree[bj*2];
}
inline void xg(int l,int r,int zone,int bj)
{
	if(l==zone && r==zone)
		return;
	int mid=(l+r)/2;
	if(zone<=mid)
		xg(l,mid,zone,bj*2);
	else
		xg(mid+1,r,zone,bj*2+1);
	if(value[tree[bj*2]]<=value[tree[bj*2+1]])
		tree[bj]=tree[bj*2];
	else
		tree[bj]=tree[bj*2+1];
}
int main()
{
	n=read(),num=read();
	build(0,num-1,1);
	for(register int i=1;i<=n;++i)
	{
		int p=read()%num;
		value[p]+=1;
		xg(0,num-1,p,1);
		int stop=tree[1];
		printf("%d\n",num*value[stop]+stop);
	}
	return 0;
}