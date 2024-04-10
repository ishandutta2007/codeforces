#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
int dp[N][3];
char a[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>(a+1);
		n=strlen(a+1);
		for(i=0;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=1e9;
		if(a[1]=='0') dp[1][0]=1;
		else dp[1][1]=0;
		for(i=2;i<=n;i++){
			if(a[i]=='1'){
				dp[i][2]=min(dp[i][2],dp[i-1][0]+1);
				dp[i][2]=min(dp[i][2],dp[i-1][2]);
				dp[i][1]=min(dp[i][1],dp[i-1][1]);
				dp[i][1]=min(dp[i][1],dp[i-1][0]);
				dp[i][1]=min(dp[i][1],dp[i-1][2]);
			}
			else{
				dp[i][2]=min(dp[i][2],dp[i-1][1]+2);
				dp[i][2]=min(dp[i][2],dp[i-1][2]);
				dp[i][0]=min(dp[i][0],dp[i-1][0]);
				dp[i][0]=min(dp[i][0],dp[i-1][1]+1);
				dp[i][0]=min(dp[i][0],dp[i-1][2]+1);
			}
		}
		cout<<min(min(dp[n][0],dp[n][1]),dp[n][2])<<endl;
	}
	return 0;
}