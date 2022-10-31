#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
const int N=105;
int n,x,c[N],sum;
double dp[105][10005],ans,m;
int main()
{
	scanf("%d%d",&n,&x);
	rep(i,n)scanf("%d",c+i),sum+=c[i];
	dp[0][0]=1;
	rep(i,n)for(int j=i;j;--j)for(int k=c[i];k<=10000;++k)
		dp[j][k]+=dp[j-1][k-c[i]];
	double ans=0;
	for(int i=0;i<n;++i){
		if(i==0)m=1;else m=m*(n-i+1)/i;
		for(int j=0;j<=10000;++j){
			//if(dp[i][j]>1e-8)printf("%d %d %lf %lf %lf %lf\n",i,j,dp[i][j],m,x*(1+1/(1-1.*i/n))/2,1.*(sum-j)/(n-i));
			ans+=dp[i][j]/m*min(x*(1+1/(1-1.*i/n))/2,1.*(sum-j)/(n-i));
		}
	}
	printf("%.15lf\n",ans);
	return 0;
}