#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const ll M=998244353;
const int N=1000005;
int n,m,q,i,j,a[500005],b[500005],mn[5000005],lazy[5000005],c,l,r;
void pushup(int x)
{
	if(mn[x*2]<mn[x*2+1])
		mn[x]=mn[x*2];
	else
		mn[x]=mn[x*2+1];
	mn[x]+=lazy[x];
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]+=x;
		mn[i]+=x;
		return;
	}
	int mid=(l+r)/2;
	if(mid>=ll)
		modify(i*2,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i*2+1,mid+1,r,ll,rr,x);
	pushup(i);
}
int Query(int i,int l,int r,int x)
{
	if(l==r)
		return l;
	int mid=(l+r)/2;
	x+=lazy[i];
	if(mn[i*2+1]+x<0)
		return Query(i*2+1,mid+1,r,x);
	else
		return Query(i*2,l,mid,x);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		modify(1,1,1000000,1,a[i],-1);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		modify(1,1,1000000,1,b[i],1);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d",&c,&l,&r);
		if(c==1)
		{
			modify(1,1,1000000,1,a[l],1);
			a[l]=r;
			modify(1,1,1000000,1,a[l],-1);
		}
		if(c==2)
		{
			modify(1,1,1000000,1,b[l],-1);
			b[l]=r;
			modify(1,1,1000000,1,b[l],1);
		}
		if(mn[1]>=0)
			printf("-1\n");
		else
			printf("%d\n",Query(1,1,1000000,0));
	}
}