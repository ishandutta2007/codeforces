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
int n,a[200010],lim[800040],ful[800040],tree[800040],m;
void build(int l,int r,int bj)
{
	if(l==r)
	{
		lim[bj]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	lim[bj]=lim[bj*2]+lim[bj*2+1];
}
void xg(int l,int r,int &zone,int &v,int bj)
{
	if(ful[bj])
	{
		zone=r+1;
		return;
	}
	if(!v) return;
	if(zone==l && tree[bj]+v>=lim[bj])
	{
		ful[bj]=1;
		v-=(lim[bj]-tree[bj]);
		tree[bj]=lim[bj];
		zone=r+1;
		return;
	}
	if(l==r)
	{
		tree[bj]+=v;
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid) xg(l,mid,zone,v,bj*2);
	if(mid<zone) xg(mid+1,r,zone,v,bj*2+1);
	tree[bj]=tree[bj*2]+tree[bj*2+1];
	ful[bj]=(ful[bj*2]&ful[bj*2+1]);
}
int cx(int l,int r,int zone,int bj)
{
	if(ful[bj]) return -1;
	if(l==r) return tree[bj];
	int mid=(l+r)/2;
	if(zone<=mid) return cx(l,mid,zone,bj*2);
	else return cx(mid+1,r,zone,bj*2+1);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	a[++n]=0x3f3f3f3f3f3f3f3f;
	build(1,n,1);
	m=read();
	while(m--)
	{
		int type=read();
		if(type==1)
		{
			int u=read(),v=read();
			xg(1,n,u,v,1);
		}
		else
		{
			int u=read();
			int v=cx(1,n,u,1);
			//cout<<"cao "<<v<<" ";
			if(v==-1) printf("%lld\n",a[u]);
			else printf("%lld\n",v);
		}
	}
	return 0;
}