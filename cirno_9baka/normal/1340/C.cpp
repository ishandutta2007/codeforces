#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int i,j,n,m,x[N],g,r,f[10005][1005];
int q[10000005],a,b,tmp[100005],t;
long long ans=1000000000000000ll;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;++i)
		scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	scanf("%d %d",&g,&r);
	memset(f,-1,sizeof(f));
	f[1][0]=0;
	q[a=b=1]=g+1;
	while(a<=b)
	{
		t=0;
		while(a<=b)
		{
			int u=q[a]/(g+1),v=q[a]%(g+1);
			if(v==g)
				tmp[++t]=u*(g+1)+v;
			if(u!=1)
			{
				if(x[u]-x[u-1]+v<=g)
					if(f[u-1][x[u]-x[u-1]+v]==-1)
					{
						f[u-1][x[u]-x[u-1]+v]=f[u][v];
						q[++b]=(u-1)*(g+1)+x[u]-x[u-1]+v;
					}
			}
			if(u!=n)
			{
				if(x[u+1]-x[u]+v<=g)
				{
					if(f[u+1][x[u+1]-x[u]+v]==-1)
					{
						f[u+1][x[u+1]-x[u]+v]=f[u][v];
						q[++b]=(u+1)*(g+1)+x[u+1]-x[u]+v;
					}
				}
			}
			++a;
		}
		a=1,b=0;
		for(i=1;i<=t;++i)
		{
			int u=tmp[i]/(g+1);
			if(f[u][0]==-1)
			{
				f[u][0]=f[u][g]+1;
				q[++b]=u*(g+1);
			}
		}
	}
	for(i=0;i<=g;++i)
		if(f[n][i]!=-1)
			ans=min(ans,1ll*(g+r)*f[n][i]+i);
	if(ans>=1000000000000000ll)
		puts("-1");
	else
		cout<<ans;
}