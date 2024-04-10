#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[3003];
ll ans;
ll dp[3003][3003][2];
int main(){
	cin>>T;
	while(T--){
		ans=0,cin>>n;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=0;k<2;k++)dp[i][j][k]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)ans+=dp[j][a[i]][1];
			for(int j=1;j<=n;j++)dp[a[i]][j][1]+=dp[a[i]][j][0];
			for(int j=1;j<i;j++)dp[a[j]][a[i]][0]++;
		}
		cout<<ans<<"\n";
	}
}