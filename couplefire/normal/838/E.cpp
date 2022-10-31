#include <bits/stdc++.h>
using namespace std;
const int maxn=2600;
int n;
double a[maxn],b[maxn],ans;
double dp[2][maxn][maxn];
double dis(int x,int y) {
	return sqrt((a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lf%lf",&a[i],&b[i]);
	for (int i=1;i<n;i++)
		for (int j=0;j<n;j++){
			int l1=(j-1+n)%n,l2=(j-i+n)%n;
			int r1=(j+1)%n,r2=(j+i)%n;
			dp[0][i][j]=max(dp[0][i-1][l1]+dis(l1,j),dp[1][i-1][l2]+dis(l2,j));
			dp[1][i][j]=max(dp[1][i-1][r1]+dis(r1,j),dp[0][i-1][r2]+dis(r2,j));
		}
	for (int i=0;i<n;i++)
		ans=max(ans,max(dp[0][n-1][i],dp[1][n-1][i]));
	printf("%.10f\n",ans);
}