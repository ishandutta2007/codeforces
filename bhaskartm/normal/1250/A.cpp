#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,k,ans,a[N],c[N][21],f[N][21];
short b[N*10];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1,x,y;i<=n;i++)
		{
			scanf("%d",&x),y=1;
			for(int j=2;j*j*j<=x;j++)
			{
				while(x%(j*j)==0)x/=j*j;
				while(x%j==0)x/=j,y*=j;
			}
			int xx=sqrt(x);
			if(xx*xx==x)a[i]=y;else a[i]=x*y;
		}
		for(int i=0;i<=k;i++)
		{
			for(int j=1;j<=n;j++)b[a[j]]=0;
			int p=0,num=0;
			for(int j=1;j<=n;j++)
			{
				if(j>1)
				{
					if(--b[a[j-1]])--num;
				}
				while(num<=i&&p<=n)if(b[a[++p]]++)++num;
				c[j][i]=p;
			}
		}
		for(int i=2;i<=n+1;i++)for(int j=0;j<=k;j++)f[i][j]=n;
		for(int i=1;i<=n;++i)
		for(int j=0;j<=k;++j)
		if(f[i][j]<n)
		for(int t=0;j+t<=k;++t)
		f[c[i][t]][j+t]=min(f[c[i][t]][j+t],f[i][j]+1);
		ans=f[n+1][0];
		for(int i=1;i<=k;i++)ans=min(ans,f[n+1][i]);
		printf("%d\n",ans);
	}
}