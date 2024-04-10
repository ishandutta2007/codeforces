#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int d,n,m,l[200003],p[23];
int val[23][23],lst[23][23];
void add(int x){
	for(int i=0;i<=m;i++)
		for(int j=i+1;j<=m+1;j++)
			lst[i][j]=val[i][j];
	for(int i=0;i<=m;i++)
		for(int j=i+1;j<=m+1;j++)
			if(x==p[i]||x==p[j])
				val[i][j]=0;
			else
				if(p[i]<x&&x<p[j])
					val[i][j]=1ll*val[i][j]*min(min(x-p[i],p[j]-x),d+1)%mod;
}
void remove(){
	for(int i=0;i<=m;i++)
		for(int j=i+1;j<=m+1;j++)
			val[i][j]=lst[i][j];
}
int dp[23];
int solve(){
	memset(dp,0,sizeof(dp));
	dp[0]=mod-1;
	for(int i=1;i<=m+1;i++)
		for(int j=0;j<i;j++)
			dp[i]=(dp[i]+(mod-1ll)*dp[j]%mod*val[j][i])%mod;
	return dp[m+1];
}
int main(){
	scanf("%d%d%d",&d,&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",l+i);
	for(int i=1;i<=m;i++)
		scanf("%d",p+i);
	sort(p+1,p+m+1);
	p[0]=-d*3;p[m+1]=d*3;
	for(int i=0;i<=m;i++)
		for(int j=i+1;j<=m+1;j++)
			val[i][j]=1;
	for(int i=0;i<n;i++)
		add(l[i]);
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		add(x);
		printf("%d\n",solve());
		remove();
	}
}