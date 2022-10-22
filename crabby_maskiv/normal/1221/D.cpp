#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll dp[N][3];
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i]>>b[i];
		dp[0][0]=dp[0][1]=dp[0][2]=0;
		for(i=1;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=inf;
		for(i=1;i<=n;i++){
			for(j=0;j<3;j++)
				for(k=0;k<3;k++)
					if(a[i]+j!=a[i-1]+k)
						dp[i][j]=min(dp[i][j],dp[i-1][k]+j*b[i]);
		}
		cout<<min(min(dp[n][0],dp[n][1]),dp[n][2])<<endl;
	}
	return 0;
}