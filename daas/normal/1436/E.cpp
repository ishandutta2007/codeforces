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
int n,pd[100010],tree[400001],last[100001];
void xg(int l,int r,int zone,int v,int bj)
{
	if(l==r)
	{
		tree[bj]=v;
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid)
		xg(l,mid,zone,v,bj*2);
	else
		xg(mid+1,r,zone,v,bj*2+1);
	tree[bj]=min(tree[bj*2],tree[bj*2+1]);
}
int cx(int l,int r,int L,int R,int bj)
{
	if(L<=l && r<=R)
		return tree[bj];
	int mid=(l+r)/2,bck=n;
	if(L<=mid)
		bck=cx(l,mid,L,R,bj*2);
	if(mid<R)
		bck=min(bck,cx(mid+1,r,L,R,bj*2+1));
	return bck;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int v=read();
		if((v==1 && last[v]!=i-1) || (v!=1 && cx(1,n,1,v-1,1)>last[v]))
			pd[v]=1;
		xg(1,n,v,i,1);
		last[v]=i;
	}
	for(int i=1;i<=n;++i)
		if((i==1 && last[i]!=n) || (i!=1 && cx(1,n,1,i-1,1)>last[i]))
			pd[i]=1;
	if(tree[1]>0)
		pd[n+1]=1;
	for(int i=1;i<=n+2;++i)
		if(!pd[i])
		{
			printf("%d\n",i);
			return 0;
		}
	return 0;
}