#include<cstdio>
using namespace std;
int n,x[6001],y[6001];
long long ans,C[2][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		++C[(x[i]&3)>>1][(y[i]&3)>>1];
	}
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			ans+=C[i][j]*(C[i][j]-1)*(C[i][j]-2)/3/2;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				for(int w=0;w<2;++w)
                    if(i!=k || j!=w)
						ans+=C[i][j]*(C[i][j]-1)/2*C[k][w];
	printf("%lld\n",ans);
	return 0;
}