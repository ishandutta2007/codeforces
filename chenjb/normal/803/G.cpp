#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long
struct node
{
	int l,r,p;
	int ans;
}st[50*100000];
int f[100011][25];
int n,k,q,tot;

int min(int x,int y)
{
	if (x<y)return x; else return y;
}

int getmin(int l,int r)
{
	int t1,t2,t3,t4;
	if (r-l+1>=n)t1=t3=1,t2=t4=n;
	else if ((l-1)/n==(r-1)/n)
	{
		l%=n; if(l==0)l=n;
		r%=n; if(r==0)r=n;
		t1=t3=l;
		t2=t4=r;
	}
	else
	{
		l%=n; if (l==0)l=n;
		r%=n; if (r==0)r=n;
		t1=l; t2=n;
		t3=1; t4=r;
	}
	int t=log(t2-t1+1)/log(2);
	int ans=min(f[t1][t],f[t2-(1<<t)+1][t]);
	t=log(t4-t3+1)/log(2);
	ans=min(ans,min(f[t3][t],f[t4-(1<<t)+1][t]));
	return ans;
}

int newnode(int l,int r)
{
	tot++;
	st[tot].l=st[tot].r=st[tot].p=0;
	st[tot].ans=getmin(l,r);
	return tot;
}

void clear(int t)
{
	int l=st[t].l;
	int r=st[t].r;
	st[l].p=st[l].ans=st[t].p;
	st[r].p=st[r].ans=st[t].p;
	st[t].p=0;
}
void insert(int t,int l,int r,int a,int b,int x)
{
	if (a<=l&&r<=b)
	{
		st[t].p=x;
		st[t].ans=x;
		return;
	}
	int mid=(l+r)/2;
	if (st[t].l==0)st[t].l=newnode(l,mid);
	if (st[t].r==0)st[t].r=newnode(mid+1,r);
	if (st[t].p!=0)clear(t);
	if (a<=mid)insert(st[t].l,l,mid,a,b,x);
	if (b>mid) insert(st[t].r,mid+1,r,a,b,x);
	st[t].ans=min(st[st[t].l].ans,st[st[t].r].ans);
}

int query(int t,int l,int r,int a,int b)
{
	if (a<=l&&r<=b)return st[t].ans;
	int mid=(l+r)/2;
	if (st[t].l==0)st[t].l=newnode(l,mid);
	if (st[t].r==0)st[t].r=newnode(mid+1,r);
	if (st[t].p!=0)clear(t);
	int ans=2147483647;
	if (a<=mid)ans=min(ans,query(st[t].l,l,mid,a,b));
	if (b>mid) ans=min(ans,query(st[t].r,mid+1,r,a,b));
	st[t].ans=min(st[st[t].l].ans,st[st[t].r].ans);
	return ans;
}

using namespace std;
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&f[i][0]);
	for(int j=1;j<=25;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	tot=0;
	newnode(1,k*n);
	st[1].ans=getmin(1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int way,l,r,x;
		scanf("%d",&way);
		if (way==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			insert(1,1,n*k,l,r,x);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,1,n*k,l,r));
		}
	}
	return 0;
}