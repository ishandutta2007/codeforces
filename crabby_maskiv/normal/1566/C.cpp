#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
int dp[N][3];
char a[N],b[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		cin>>(a+1)>>(b+1);
		for(i=0;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=-1e9;
		if(a[1]=='0'&&b[1]=='0') dp[1][0]=1;
		if(a[1]=='1'&&b[1]=='0') dp[1][2]=2;
		if(a[1]=='0'&&b[1]=='1') dp[1][2]=2;
		if(a[1]=='1'&&b[1]=='1') dp[1][1]=0;
		for(i=2;i<=n;i++){
			if(a[i]=='1'&&b[i]=='1'){
				dp[i][2]=max(dp[i][2],dp[i-1][0]+1);
				dp[i][2]=max(dp[i][2],dp[i-1][2]);
				dp[i][1]=max(dp[i][1],dp[i-1][1]);
				dp[i][1]=max(dp[i][1],dp[i-1][0]);
				dp[i][1]=max(dp[i][1],dp[i-1][2]);
			}
			else if(a[i]=='0'&&b[i]=='0'){
				dp[i][2]=max(dp[i][2],dp[i-1][1]+2);
				dp[i][2]=max(dp[i][2],dp[i-1][2]);
				dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
				dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
				dp[i][0]=max(dp[i][0],dp[i-1][2]+1);
			}
			else{
				dp[i][2]=max(dp[i][2],dp[i-1][0]+2);
				dp[i][2]=max(dp[i][2],dp[i-1][1]+2);
				dp[i][2]=max(dp[i][2],dp[i-1][2]+2);
			}
		//	cerr<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
		}
		cout<<max(max(dp[n][0],dp[n][1]),dp[n][2])<<endl;
	}
	return 0;
}