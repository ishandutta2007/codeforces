#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n1,n2,n3,n,m;
int a[N];
int dp[N][2];
int main(){
	int i,j;
	cin>>n1>>n2>>n3;
	for(i=1;i<=n1;i++){
		int x;cin>>x;a[x]=1;
	}
	for(i=1;i<=n2;i++){
		int x;cin>>x;a[x]=2;
	}
	for(i=1;i<=n3;i++){
		int x;cin>>x;a[x]=3;
	}
	n=n1+n2+n3;
	memset(dp,0x3f,sizeof(dp));
	dp[n+1][0]=dp[n+1][1]=0;
	for(i=n;i;i--){
		dp[i][0]=dp[i+1][0]+(a[i]==2);
		dp[i][1]=min(dp[i+1][1],dp[i+1][0])+(a[i]==3);
	}
	int ans=min(dp[1][0],dp[1][1])+n1;
	int cnt1=0;
	for(i=1;i<=n;i++){
		cnt1+=(a[i]==1);
		ans=min(ans,(n1-cnt1)+(i-cnt1)+min(dp[i+1][0],dp[i+1][1]));
	}
	cout<<ans;
	return 0;
}