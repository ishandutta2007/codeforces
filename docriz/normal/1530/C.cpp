#include<bits/stdc++.h>
using namespace std;
int T,n,x,a[2][105],b[2][105],sum[2],siz[2];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[0][x]++;	
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[1][x]++;	
		}
		int l=0,r=200000,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			for(int i=0;i<=100;i++)b[0][i]=a[0][i],b[1][i]=a[1][i];
			b[0][100]+=mid;
			b[1][0]+=mid;
			sum[0]=sum[1]=0;
			siz[0]=siz[1]=0;
			int num=n+mid-(n+mid)/4;
			for(int i=100;i>=0;i--)
			{
				for(int j=0;j<2;j++)
				{ 
					int q=min(num-siz[j],b[j][i]);
					sum[j]+=q*i;
					siz[j]+=q;
				}
			}
			if(sum[0]>=sum[1])r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}