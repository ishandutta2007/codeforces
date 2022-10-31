#include<bits/stdc++.h>
const int N=4505;
using namespace std;

int n,m,dp[N][N];
int l[N],s[N],c[N];

void gx(int&x,int y){x=max(x,y);}

main(){
	cin>>n>>m;
	for(int i=n;i>=1;i--)cin>>l[i];
	for(int i=n;i>=1;i--)cin>>s[i];
	for(int i=1;i<=n+m;i++)cin>>c[i];
	memset(dp,-2,sizeof(dp));
	for(int i=1;i<=n+m;i++)dp[i][0]=0;
	for(int i=1;i<=n;i++){
		int t=l[i];
		for(int j=n;j;j--)
			gx(dp[t][j],dp[t][j-1]-s[i]+c[t]);
		for(int j=t,k=n;j<=n+m;j++,k>>=1)
			for(int x=0;x<=k;x++)
				gx(dp[j+1][x>>1],dp[j][x]+c[j+1]*(x>>1));
	}
	cout<<dp[n+m][0]<<endl;
}