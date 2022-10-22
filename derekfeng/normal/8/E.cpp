#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll K;
ll dp[30][2][2];
int a[55];
ll dfs(int l,int r,int c1,int c2){
	if(l+1>r-1)return 1;
	if(~dp[l][c1][c2])return dp[l][c1][c2];
	ll &res=dp[l][c1][c2];
	res=0;
	for(int i=0;i<2;i++)if(i==a[l+1]||a[l+1]<0)
		for(int j=0;j<2;j++)if(j==a[r-1]||a[r-1]<0)
			if(l+1!=r-1||i==j)if((!c1||i<=j)&&(!c2||i<=1-j))
				res+=dfs(l+1,r-1,c1&(i==j),c2&(i!=j));
	return res;
}
int main(){
	scanf("%d%I64d",&n,&K);K++;
	memset(a,-1,sizeof(a));
	memset(dp,-1,sizeof(dp));
	if(dfs(0,n+1,1,1)<K)return puts("-1"),0;
	for(int i=1;i<=n;i++){
		memset(dp,-1,sizeof(dp));
		a[i]=0;
		ll sum=dfs(0,n+1,1,1);
		if(K>sum)K-=sum,a[i]=1;
	}
	for(int i=1;i<=n;i++)putchar(a[i]+'0');
}