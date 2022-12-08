#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
double dp[maxn][maxn];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) dp[i][0]=1.0,dp[i][1]=1.*i/(i+1);
	for (int i=1;i<=n;++i){
		for (int j=2;j<=m;++j){
			double cur=1.*i/(i+j);
			//printf("%.3lf %d %d\n",cur,i,j);
			cur+=1.*j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*dp[i-1][j-2];
			// 2 2 1
			//printf("%.3lf %d %d\n",cur,i,j);
			if (j>=3) cur+=1.*j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*dp[i][j-3]; 
			// 2 2 2
			dp[i][j]=cur;
		}
	}
	printf("%.9lf",dp[n][m]);
	return 0;
}