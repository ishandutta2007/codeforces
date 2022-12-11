#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 64
int v[MN+5][MN+5];
double f[MN+5][MN+5][MN+5],p[MN+5][MN+5][MN+5],ans,mx;
void dp(int l,int r,int s)
{
	if(l==r){p[l][r][l]=1;return;}
	int mid=l+r>>1,i,j;
	dp(l,mid,s>>1);dp(mid+1,r,s>>1); 
	for(i=l;i<=mid;++i)
	{
		for(mx=0,j=mid+1;j<=r;++j)
			p[l][r][i]+=p[l][mid][i]*p[mid+1][r][j]*v[i][j]/100,
			mx=max(mx,f[mid+1][r][j]);
		f[l][r][i]=f[l][mid][i]+mx+s*p[l][r][i];
	}
	for(i=mid+1;i<=r;++i)
	{
		for(mx=0,j=l;j<=mid;++j)
			p[l][r][i]+=p[l][mid][j]*p[mid+1][r][i]*v[i][j]/100,
			mx=max(mx,f[l][mid][j]);
		f[l][r][i]=mx+f[mid+1][r][i]+s*p[l][r][i];
	}
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=1<<n;++i)for(j=1;j<=1<<n;++j)scanf("%d",&v[i][j]);
	dp(1,1<<n,1<<n-1);
	for(i=1;i<=1<<n;++i)ans=max(ans,f[1][1<<n][i]);
	printf("%.10lf",ans);
}