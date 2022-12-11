#include<bits/stdc++.h>
using namespace std;
const int N=20,mod=1e9+7;
int n,T,t[N],g[N],ans,num[4],J[N],I[N],dp[N][N][N][N];bool vis[N];
int solve(int x,int y,int z,int la){
	if(!x&&!y&&!z)return 1;
	if(dp[x][y][z][la])return dp[x][y][z][la];
	if(la!=1&&x)(dp[x][y][z][la]+=solve(x-1,y,z,1))%=mod;
	if(la!=2&&y)(dp[x][y][z][la]+=solve(x,y-1,z,2))%=mod;
	if(la!=3&&z)(dp[x][y][z][la]+=solve(x,y,z-1,3))%=mod;
	return dp[x][y][z][la];
}
int calc(int x,int y,int z){
	if(y<z)swap(y,z);if(x<y)swap(x,y);if(y<z)swap(y,z);
	return 1ll*J[x]*J[y]%mod*J[z]%mod*solve(x,y,z,0)%mod;
}
void dfs(int now,int re){
	if(re<0)return;
	if(now>n){
		if(!re)(ans+=calc(num[1],num[2],num[3]))%=mod;
		return;
	}
	num[g[now]]++;
	dfs(now+1,re-t[now]);
	num[g[now]]--;
	dfs(now+1,re);
}
int main(){
	J[0]=1;
	for(int i=1;i<=20;i++)J[i]=1ll*J[i-1]*i%mod;
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)scanf("%d%d",&t[i],&g[i]);
	dfs(1,T);
	printf("%d\n",ans);
	return 0;
}