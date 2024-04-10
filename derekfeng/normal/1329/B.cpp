#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,d,m;
ll dp[33][33],ans;
void MAIN(){
	ans=0;
	int CNT;
	for (int j=0;j<31;j++){
		if ((1<<j)>d) break;
		CNT=j;
	}
	memset (dp,0,sizeof(dp));
	for (int i=0;i<CNT;i++) dp[0][i]=(1<<i);
//	for (int i=0;i<CNT;i++) cout<<dp[0][i]<<"\n";
	dp[0][CNT]=d-(1<<CNT)+1; 
	for (int i=0;i<31;i++){
		for (int j=0;j<=CNT;j++) if (dp[i][j]>0){
			for (int k=j+1;k<CNT;k++)
				dp[i+1][k]=(dp[i+1][k]+dp[i][j]*(1<<k)%m)%m;
			if (j!=CNT)dp[i+1][CNT]=(dp[i+1][CNT]+dp[i][j]*(d-(1<<CNT)+1))%m;
			ans=(ans+dp[i][j])%m;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	cin>>t;
	while (t--){
		cin>>d>>m;
		MAIN();
	}
}