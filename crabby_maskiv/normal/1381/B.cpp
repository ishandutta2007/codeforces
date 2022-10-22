#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4005;
int n,m;
int dp[N][N];
int a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;n<<=1;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				dp[i][j]=0;
		}
		dp[n][1]=n+1;
		dp[n][0]=a[n];
		for(i=n-1;i;i--){
			for(j=0;j<=n-i;j++){
				if(a[i]<dp[i+1][j])
					dp[i][j+1]=max(dp[i][j+1],dp[i+1][j]);
				if((j==0||a[i]<a[i+1])&&dp[i+1][j]!=0)
					dp[i][n-i-j+1]=max(dp[i][n-i-j+1],a[i+1]);
			}
		}
//		for(i=1;i<=n;i++){
//			for(j=1;j<=n-i+1;j++) cout<<dp[i][j]<<" ";
//			cout<<endl;
//		}
		if(dp[1][n/2]==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}