#include <bits/stdc++.h>
using namespace std;
#define N 405
int T,n,m,ans,w[N],s1[N],s2[N],s3[N];char a[N][N];
void slv()
{
	scanf("%d %d",&n,&m);ans=1e9;for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=n-4;++i)
	{
		for(int j=1;j<=m;++j) w[j]=0,s1[j]=s1[j-1]+a[i][j]-48;
		for(int j=i+1;j<=n;++j)
		{
			for(int k=1;k<=m;++k) s2[k]=s2[k-1]+a[j][k]-48;
			if(j>i+3) for(int k=m,nw=1e9;k>3;--k)
			{
				nw=min(nw,s3[k-1]-s1[k-1]-s2[k-1]-w[k]+(k-1)*2);
				ans=min(ans,s1[k-3]+s2[k-3]-s3[k-3]-w[k-3]+(j-i-k+2)*2+nw);
			}for(int k=1;k<=m;++k) w[k]+=a[j][k]-48,s3[k]=s3[k-1]+w[k];
		}
	}printf("%d\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}