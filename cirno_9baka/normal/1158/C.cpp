#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
typedef long long ll;
int n,i,m,t,le[500005],head[5000005],Next[20000005],adj[20000005],k,p[500005],u,pts[5000005],q[5000005],l,r,ord[5000005],ans[500005],fans[500005];
void Push(int u,int v)
{
	pts[v]++;
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void Build(int i,int l,int r)
{
	int mid=(l+r)/2;
	if(l==r)
	{
		p[l]=i;
		u=max(u,i);
		return;
	}
	Push(i,i*2);
	Push(i,i*2+1);
	Build(i*2,l,mid);
	Build(i*2+1,mid+1,r);
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(ll>rr)
		return;
	if(l>=ll&&r<=rr)
	{
		Push(x,i);
		return;
	}
	int mid=(l+r)/2;
	if(mid>=ll)
		modify(i*2,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i*2+1,mid+1,r,ll,rr,x);
}
bool cmp(int a,int b)
{
	return ord[p[a]]>ord[p[b]];
}
int main(){
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		k=0;
		u=0;
		Build(1,1,n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&le[i]);
			if(le[i]!=-1)
			{
				modify(1,1,n,i+1,le[i]-1,p[i]);
				if(le[i]!=n+1)
					Push(p[le[i]],p[i]);
			}
		}
		l=1;r=0;
		for(i=1;i<=u;i++)
			if(pts[i]==0)
				q[++r]=i;
		while(l<=r)
		{
			for(i=head[q[l]];i!=0;i=Next[i])
			{
				pts[adj[i]]--;
				if(pts[adj[i]]==0)
					q[++r]=adj[i];
			}
			l++;
		}
		for(i=1;i<=u;i++)
		{
			head[i]=0;
			pts[i]=0;
		}
		if(r!=u)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=r;i++)
			ord[q[i]]=i;
		for(i=1;i<=n;i++)
			ans[i]=i;
		sort(ans+1,ans+1+n,cmp);
		for(i=1;i<=n;i++)
			fans[ans[i]]=i;
		for(i=1;i<=n;i++)
			printf("%d ",fans[i]);
		printf("\n");
	}
}