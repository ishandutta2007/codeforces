#include<cstdio>
#define max(a,b)a>b?a:b
const int N=1e6+9;
int dp[N][3][3],n,m,b[N],a;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a),b[a]++;
	for(int i=1;i<=m;i++)
	  for(int j=0;j<3&&j<=b[i]&&j<=b[i+1]&&j<=b[i+2];j++)
		for(int k=0;k<3&&k<=b[i-1]&&k<=b[i]-j&&k<=b[i+1]-j;k++){
		  for(int l=0;l<3&&l<=(i<2?0:b[i-2])&&l<=b[i-1]-k&&l<=b[i]-j-k;l++)
			dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+j+(b[i]-j-k-l)/3);
		}
	printf("%d",dp[m][0][0]);
	return 0;
}