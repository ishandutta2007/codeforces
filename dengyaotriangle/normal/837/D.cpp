#include<bits/stdc++.h>

using namespace std;

const int maxn=205;
const int vv=6000;

struct num{
	short n2,n5;
	long long o;
};

num x[maxn];
int n,m;
int dp[2][maxn][vv];
int ans;

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i].o;
	for(int i=1;i<=n;i++){
		long long cur=x[i].o;
		while(cur%2==0){
			cur/=2;
			x[i].n2++;
		}
		while(cur%5==0){
			cur/=5;
			x[i].n5++;
		}
	}
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<vv;k++){
				dp[i%2][j][k]=dp[(i-1)%2][j][k];
				if(j>=1&&k>=x[i].n5) if(dp[(i-1)%2][j-1][k-x[i].n5]!=-1) dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j-1][k-x[i].n5]+x[i].n2);
				//cout<<i<<j<<k<<' '<<dp[i%2][j][k]<<endl;
			}
		}
	}
	int ans=0;
	for(int i=0;i<vv;i++){
		//cout<<dp[n%2][m][i];
		if(dp[n%2][m][i]!=-1) ans=max(ans,min(i,dp[n%2][m][i]));
	}
	cout<<ans;
	return 0;
}