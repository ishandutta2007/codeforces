#include<bits/stdc++.h>
using namespace std;
long long dp[103][103][103],n,m,k,p[103][103],c[103],ans=55555555555555555;
int main(){
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)cin>>c[i];
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
			cin>>p[i][j];
	for(int i=0;i<103;i++)for(int j=0;j<103;j++)for(int i1=0;i1<103;i1++)dp[i][j][i1]=555555555555555555;
	if(c[1]==0)
		for(long long i=1;i<=m;i++)
			dp[1][i][1]=p[1][i]; 
	else
		dp[1][c[1]][1]=0; 
	for(long long i=2;i<=n;i++)
		if(c[i]==0)
			for(long long j=1;j<=m;j++)
				for(long long j1=1;j1<=m;j1++)
					for(long long i1=0;i1<=k;i1++)
						if(i1-(j!=j1)!=-1)
							dp[i][j1][i1]=min(dp[i][j1][i1],dp[i-1][j][i1-(j!=j1)]+p[i][j1]);else; 
		else
			for(long long j=1;j<=m;j++)//lastcolour
				for(long long i1=0;i1<=k;i1++)//nowbeauty
					if(i1-(j!=c[i])!=-1)
						dp[i][c[i]][i1]=min(dp[i-1][j][i1-(j!=c[i])],dp[i][c[i]][i1]);else;
	for(int i=1;i<=m;i++)ans=min(ans,dp[n][i][k]);
	if(ans==55555555555555555)cout<<-1;else cout<<ans; 
}