#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define LL long long
#define maxn 40010
using namespace std;
struct node
{
	int l,r,max,p;
}st[4*maxn*51];
int n,k;
int a[40000];
int f[40000][52];
int root[52];
int pre[40000],tot;
int newnode()
{
	tot++;
	st[tot].l=st[tot].r=st[tot].max=st[tot].p=0;
	return tot;
}
void clear(int t)
{
	if (st[t].l==0)st[t].l=newnode();
	if (st[t].r==0)st[t].r=newnode();
	st[st[t].l].max+=st[t].p;
	st[st[t].r].max+=st[t].p;
	st[st[t].l].p+=st[t].p;
	st[st[t].r].p+=st[t].p;
	st[t].p=0;
}
void insert(int t,int l,int r,int a,int b,int k)
{
	if (a<=l&&r<=b)
	{
		st[t].max+=k;
		st[t].p+=k;
		return;
	}
	if (st[t].p!=0)clear(t);
	int mid=(l+r)/2;
	if (a<=mid)
	{
		if (st[t].l==0)st[t].l=newnode();
		insert(st[t].l,l,mid,a,b,k);
	}
	if (b>mid)
	{
		if (st[t].r==0)st[t].r=newnode();
		insert(st[t].r,mid+1,r,a,b,k);
	}
	st[t].max=max(st[st[t].l].max,st[st[t].r].max);
}
int getmax(int t,int l,int r,int a,int b)
{
	if (st[t].max==0)return 0;
	if (a<=l&&r<=b)return st[t].max;
	int mid=(l+r)/2;
	int ans=0;
	if (a<=mid)ans=max(ans,getmax(st[t].l,l,mid,a,b));
	if (b>mid)ans=max(ans,getmax(st[t].r,mid+1,r,a,b));
	return ans;
}
void work()
{
	memset(f,0,sizeof(f));
	memset(pre,0,sizeof(pre));
	tot=-1;
	newnode();
	for(int i=0;i<=k;i++)root[i]=newnode();
	f[0][0]=0;


	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if (j>i)break;
			insert(root[j-1],0,n,pre[a[i]],i-1,1);
			f[i][j]=getmax(root[j-1],0,n,0,i-1);
			insert(root[j],0,n,i,i,f[i][j]);
			
		}
		pre[a[i]]=i;
	}
	cout<<f[n][k]<<endl;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	work();
	return 0;
}