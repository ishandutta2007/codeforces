#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=998244353;
const int N=10000005;
int n,a[N],q,i,t[N],p[N],x[N],mx=0,vis[N],ans[N];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d %d",&t[i],&p[i]);
		if(t[i]==1)
			scanf("%d",&x[i]);
	}
	for(i=q;i>=1;i--)
		if(t[i]==1&&vis[p[i]]==0)
		{
			ans[p[i]]=max(x[i],mx);
			vis[p[i]]=1;
		}
		else
			if(t[i]==2)
				mx=max(mx,p[i]);
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			ans[i]=max(a[i],mx);
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
}