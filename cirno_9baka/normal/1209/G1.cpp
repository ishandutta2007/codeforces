#include<bits/stdc++.h>
using namespace std;
int n,i,a[200005],lazy[1000005],mn[1000005],sum[1000005],mx[1000005],mxr[1000005],mxl[1000005],x,y,q;
set<int> p[200005];
void pushup(int i)
{
	if(mn[i<<1]<mn[i<<1|1])
	{
		mn[i]=mn[i<<1];
		sum[i]=sum[i<<1]+max(mxr[i<<1],mx[i<<1|1])-mxr[i<<1];
		mxr[i]=max(mxr[i<<1],mx[i<<1|1]);
		mxl[i]=mxl[i<<1];
	}
	if(mn[i<<1]>mn[i<<1|1])
	{
		mn[i]=mn[i<<1|1];
		sum[i]=sum[i<<1|1]-mxl[i<<1|1]+max(mxl[i<<1|1],mx[i<<1]);
		mxl[i]=max(mxl[i<<1|1],mx[i<<1]);
		mxr[i]=mxr[i<<1|1];
	}
	if(mn[i<<1]==mn[i<<1|1])
	{
		mn[i]=mn[i<<1];
		mxl[i]=mxl[i<<1];
		mxr[i]=mxr[i<<1|1];
		sum[i]=sum[i<<1]+sum[i<<1|1]-mxl[i<<1|1]-mxr[i<<1]+max(mxl[i<<1|1],mxr[i<<1]);
	}
	mx[i]=max(mx[i<<1],mx[i<<1|1]);
}
void pushdown(int i)
{
	lazy[i<<1]+=lazy[i];
	lazy[i<<1|1]+=lazy[i];
	mn[i<<1]+=lazy[i];
	mn[i<<1|1]+=lazy[i];
	lazy[i]=0;
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]+=x;
		mn[i]+=x;
		return;
	}
	pushdown(i);
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	pushup(i);
}
void Add(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		mx[i]+=y;
		mxl[i]+=y;
		sum[i]+=y;
		return;
	}
	pushdown(i);
	int mid=l+r>>1;
	if(mid>=x)
		Add(i<<1,l,mid,x,y);
	else
		Add(i<<1|1,mid+1,r,x,y);
	pushup(i);
}
int main()
{
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p[a[i]].insert(i);
	}
	for(i=1;i<=200000;++i)
		if(!p[i].empty())
		{
			if(p[i].size()!=1)
				modify(1,1,n,*p[i].begin(),*(--p[i].end())-1,1);
			Add(1,1,n,*p[i].begin(),p[i].size());
		}
	printf("%d\n",n-sum[1]);
	while(q--)
	{
		scanf("%d %d",&x,&y);
		if(p[a[x]].size()>1)
		modify(1,1,n,*p[a[x]].begin(),*(--p[a[x]].end())-1,-1);
		if(p[y].size()>1)
			modify(1,1,n,*p[y].begin(),*(--p[y].end())-1,-1);
		Add(1,1,n,*p[a[x]].begin(),-p[a[x]].size());
		if(!p[y].empty())
			Add(1,1,n,*p[y].begin(),-p[y].size());
		p[a[x]].erase(x);
		p[y].insert(x);
		if(p[a[x]].size()>1)
			modify(1,1,n,*p[a[x]].begin(),*(--p[a[x]].end())-1,1);
		if(p[y].size()>1)
			modify(1,1,n,*p[y].begin(),*(--p[y].end())-1,1);
		if(!p[a[x]].empty())
			Add(1,1,n,*p[a[x]].begin(),p[a[x]].size());
		Add(1,1,n,*p[y].begin(),p[y].size());
		printf("%d\n",n-sum[1]);
		a[x]=y;
	}
}