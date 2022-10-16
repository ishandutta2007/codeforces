#include<bits/stdc++.h>
using namespace std;
long long dp[7][15625],pw[7],a[7],b[7],n,m,c[7][7],nw,msk;
inline void dfs(int fr,int tm,int nwmsk,int cst){
	if(tm==0){
		dp[nw][nwmsk]=min(dp[nw][nwmsk],dp[nw-1][msk]+cst);
		return;
	}
	for(int i=fr;i<m;i++){
		if(i!=-1&&nwmsk/pw[i]%5>=b[i])
			continue;
		if(fr!=i)cst+=c[nw][i];
		dfs(i,tm-1,nwmsk+pw[i],cst);
		if(fr!=i)cst-=c[nw][i];
	}
}
int popcount(int x){
	int ret=0;
	while(x){
		ret+=x%5;x/=5;
	}return ret;
} 
int cntt=0;
int main(){
	memset(dp,31,sizeof(dp));
	dp[0][0]=0;
	pw[0]=1;
	for(int i=1;i<7;i++)
		pw[i]=pw[i-1]*5;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],cntt+=a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=0;j<pw[m];j++){
			nw=i;msk=j;
			dfs(-1,a[i],j,0);
		}
	long long ans=360000003;
	for(int i=0;i<pw[m];i++)
		if(popcount(i)>=cntt)
			ans=min(ans,dp[n][i]);
	if(ans==360000003)
		cout<<-1;
	else
		cout<<ans;
}