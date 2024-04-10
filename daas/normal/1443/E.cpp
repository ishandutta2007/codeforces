#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
#define lowbit(k) (k&-k)
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
int n,q,a[200001],p[200001],sum[10],tree[200001],Tree[800001];
void xg(int zone,int v)
{
	while(zone<=n)
	{
		tree[zone]+=v;
		zone+=lowbit(zone);
	}
}
int cx(int zone)
{
	int bck=0;
	while(zone)
	{
		bck+=tree[zone];
		zone-=lowbit(zone);
	}
	return bck;
}
void XG(int l,int r,int zone,int v,int bj)
{
	if(l==r)
	{
		Tree[bj]+=v;
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid)
		XG(l,mid,zone,v,bj*2);
	else
		XG(mid+1,r,zone,v,bj*2+1);
	Tree[bj]=Tree[bj*2]+Tree[bj*2+1];
}
int CX(int l,int r,int K,int bj)
{
	if(l==r)
		return l;
	int mid=(l+r)/2;
	if(Tree[bj*2]>=K)
		return CX(l,mid,K,bj*2);
	else
		return CX(mid+1,r,K-Tree[bj*2],bj*2+1);
}
signed main()
{
	n=read(),q=read();
	sum[0]=1;
	for(int i=1;i<=9;++i)
		sum[i]=sum[i-1]*i;
	for(int i=1;i<=n;++i)
		a[i]=i,p[i]=0,xg(i,i);
	while(q--)
	{
		int type=read();
		if(type==1)
		{
			int l=read(),r=read();
			printf("%lld\n",cx(r)-cx(l-1));
		}
		else
		{
			int x=read(),len=min(n-1,9ll),rest=0;
			for(int i=len;i>=0;--i)
			{
				p[n-i]+=x/sum[i];
				x%=sum[i];
			}
			for(int i=0;i<=len;++i)
			{
				p[n-i]+=rest;
				rest=p[n-i]/(i+1);
				p[n-i]%=(i+1);
				if(i==len && rest)
					++len;
			}
			for(int i=0;i<=len;++i)
				xg(n-i,-a[n-i]),XG(1,n,a[n-i],1,1);
			for(int i=len;i>=0;--i)
			{
				a[n-i]=CX(1,n,p[n-i]+1,1);
				xg(n-i,a[n-i]);
				XG(1,n,a[n-i],-1,1);
			}
		}
	}
	return 0;
}