#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,q,i,a[N],mn[N*4],mnn[N*4],tree[N*4],lazy[N*4],ans[N];
struct str{
	int l,r,x;
}b[N];
bool cmp(str a,str b)
{
	return a.l>b.l;
}
void Build(int i,int l,int r)
{
	mnn[i]=r;
	//mn[i]=n+1;
	if(l==r)
		return;
	int mid=l+r>>1;
	Build(i<<1,l,mid);
	Build(i<<1|1,mid+1,r);
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		mn[i]+=x;
		lazy[i]+=x;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	mn[i]=min(mn[i<<1],mn[i<<1|1]);
	mnn[i]=(mn[i]==mn[i<<1|1]?mnn[i<<1|1]:mnn[i<<1]);
	mn[i]+=lazy[i];
}
void modify2(int i)
{
	while(i<=n)
	{
		++tree[i];
		i+=-i&i;
	}
}
int Query(int i)
{
	int ans=0;
	while(i)
	{
		ans+=tree[i];
		i-=-i&i;
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=q;++i)
	{
		scanf("%d %d",&b[i].l,&b[i].r);
		b[i].x=i;
	}
	sort(b+1,b+1+q,cmp);
	for(i=1;i<=n;++i)
		if(a[i]>i)
			a[i]=n+1;
		else
			a[i]=i-a[i];
	int l=n;
	Build(1,1,n);
	modify(1,1,n,1,n,n+1);
	for(i=1;i<=q;++i)
	{
		while(l>b[i].l)
		{
			modify(1,1,n,l,l,-(n+1)+a[l]);
			//cout<<mn[1]<<endl;
			//cout<<l<<' '<<mn[1]<<' '<<mnn[1]<<endl;
			while(mn[1]<=0)
			{
				int u=mnn[1];
				modify(1,1,n,u,u,3*n+1);
				modify(1,1,n,u,n,-1);
				modify2(u);
			}
			--l;
		}
		ans[b[i].x]=Query(n-b[i].r);
	}
	for(i=1;i<=q;++i)
		printf("%d\n",ans[i]);
}