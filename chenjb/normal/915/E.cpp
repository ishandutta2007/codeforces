#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define N 700
#define M 210000
using namespace std;
struct node
{
	int l,r,p,sum;
}st[15000000];
int tot;
int newnode()
{
	tot++;
	st[tot].l=st[tot].r=st[tot].sum=0;
	st[tot].p=-1;
	return tot;
}
void clear(int t,int l,int r)
{
	if (st[t].l==0)st[t].l=newnode();
	if (st[t].r==0)st[t].r=newnode();
	int mid=(l+r)/2;
	int ln=st[t].l;
	int rn=st[t].r;
	st[ln].p=st[t].p;
	st[rn].p=st[t].p;
	st[ln].sum=(mid-l+1)*st[t].p;
	st[rn].sum=(r-mid)*st[t].p;
	st[t].p=-1;
}
void modify(int t,int l,int r,int a,int b,int c)
{
	if (a<=l && r<=b)
	{
		st[t].p=c;
		st[t].sum=(r-l+1)*c;
		return;
	}
	if (st[t].p!=-1)clear(t,l,r);
	int mid=(l+r)/2;
	if (a<=mid)
	{
		if (st[t].l==0)st[t].l=newnode();
		modify(st[t].l,l,mid,a,b,c);
	}
	if (b>mid)
	{
		if (st[t].r==0)st[t].r=newnode();
		modify(st[t].r,mid+1,r,a,b,c);
	}
	st[t].sum=st[st[t].l].sum+st[st[t].r].sum;
}
int n,q;
int main()
{
	scanf("%d%d",&n,&q);
	tot=-1;
	newnode();
	newnode();
	for(int i=1;i<=q;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if (k==2)k=0;
		modify(1,1,n,l,r,k);
		printf("%d\n",n-st[1].sum);
	}
}