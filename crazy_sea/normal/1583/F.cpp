#include<cstdio>
#include<algorithm>
#define N 1010
using namespace std;
int p[N][N],n,k,ans;
void solve(int l,int r,int cnt)
{
	if(l==r) return;
	if(cnt>ans) ans=cnt;
	int len=r-l+1,c;
	if(len<=k)
	{
		for(int i=l;i<=r;i++)
			for(int j=i+1;j<=r;j++)
				p[i][j]=cnt;
		return;
	}
	c=len/k+(len%k>0);
	for(int i=l;i<=r;i++)
	{
		for(int j=i+1;j<=r;j++)
			if((i-l)/c!=(j-l)/c) p[i][j]=cnt;
	}
	for(int i=1;i<=k;i++)
		solve(l+(i-1)*c,min(r,l+i*c-1),cnt+1);
}
int main()
{
	scanf("%d%d",&n,&k);
	solve(1,n,1);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			printf("%d ",p[i][j]);
}