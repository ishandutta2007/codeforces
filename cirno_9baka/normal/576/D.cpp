#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const int M=998244353;
const int N=100005,E=262144;
int n,m,c,u,v,w,f[31][205][205],i,j,k,l,r,d[205],p[205],tmp[205],vis[205],q[205],ans=2147483640;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=0;k<=30;++k)
				f[k][i][j]=2147483640;
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		f[0][u][v]=min(f[0][u][v],w);
		d[++c]=w;
	}
	sort(d+1,d+1+c);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			f[0][i][j]=lower_bound(d+1,d+1+c,f[0][i][j])-d;
	for(l=1;l<=30;++l)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				for(k=1;k<=n;++k)
					f[l][j][k]=min(f[l][j][k],max(f[l-1][j][i],f[l-1][i][k]));
	p[1]=1;
	//for(i=1;i<=c;++i)
	//	scanf("%d",&d[i]);
	for(i=1;i<=c;++i)
	{
		int t=d[i]-d[i-1];
		for(j=0;j<=30;++j)
			if((t>>j)&1)
			{
				memcpy(tmp,p,sizeof(tmp));
				memset(p,0,sizeof(p));
				for(k=1;k<=n;++k)
					if(tmp[k])
						for(l=1;l<=n;++l)
							if(f[j][k][l]<i)
								p[l]=1;
			}
		q[l=r=1]=n;
		memset(vis,-1,sizeof(vis));
		vis[n]=0;
		while(l<=r)
		{
			for(j=1;j<=n;++j)
				if(f[0][j][q[l]]<=i)
					if(vis[j]==-1)
					{
						vis[j]=vis[q[l]]+1;
						q[++r]=j;
					}
			++l;
		}
		for(j=1;j<=n;++j)
			if(p[j]&&vis[j]!=-1)
				ans=min(ans,d[i]+vis[j]);
	}
	if(ans>(1<<30))
		puts("Impossible");
	else
		cout<<ans;
}