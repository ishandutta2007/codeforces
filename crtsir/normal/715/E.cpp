#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int C[503][503],m;
void calc(int n,int (*f)[503],int *F){
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		int fac=1;
		for(int j=1;j<=i;j++){
			for(int k=0;k<=n;k++)
				f[i][k+1]=(f[i][k+1]+1ll*f[i-j][k]*fac)%mod;
			fac=1ll*fac*(i-j)%mod;
		}
	}
	for(int i=0;i<=n;i++){
		int fac=1;
		for(int j=n;j>=0;j--){
			F[i]=(F[i]+1ll*fac*f[j][i]%mod*C[n][j])%mod;
			fac=1ll*fac*(m+n-j)%mod;
		}
	}
}
int n,p[503],q[503],f[503][503],g[503][503],ans[1503],F[503],G[503];
bool vis[503];
int cnt[2][2],lst,cir,dp[503][503],DP[503];
void dfs(int x){
	vis[x]=1;
	lst=x;
	if(q[x]==-1||vis[q[x]])
		return;
	dfs(q[x]);
}
int main(){
	for(int i=0;i<503;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	memset(p,-1,sizeof(p));
	cin>>n;
	for(int i=0;i<n;i++){
		int a;cin>>a;a--;
		if(a!=-1)p[i]=a+n;
	}
	for(int i=0;i<n;i++){
		int a;cin>>a;a--;
		if(a!=-1)p[a+n]=i;
	}memset(q,-1,sizeof(q));
	for(int i=0;i<n+n;i++)
		if(p[i]!=-1)
			q[p[i]]=i;
	for(int i=0;i<n+n;i++)
		if(p[i]==-1){
			dfs(i);
			cnt[i/n][lst/n]++;
		}m=cnt[0][0];
	for(int i=0;i<n+n;i++)
		if(!vis[i]){
			dfs(i);
			cir++;
		}
	dp[0][0]=1;
	for(int i=1;i<=m;i++){
		int fac=1;
		for(int j=1;j<=i;j++){
			fac=1ll*fac*(i-j+1)%mod;
			for(int k=0;k<=i-j;k++)
				dp[i][k+1]=(dp[i][k+1]+1ll*dp[i-j][k]*fac)%mod;
			fac=1ll*fac*(i-j)%mod;
		}
	}for(int i=0;i<=n;i++)DP[i]=dp[m][i];
	calc(cnt[0][1],f,F);
	calc(cnt[1][0],g,G);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				ans[i+j+k+cir]=(ans[i+j+k+cir]+1ll*F[i]*G[j]%mod*DP[k])%mod;
	for(int i=n;i>0;i--)
		cout<<ans[i]<<' ';
}