#include <bits/stdc++.h>
#define maxn 1009
using namespace std;
int p[maxn];
int n,m,w;
int a[maxn],b[maxn];
long long wt[maxn],val[maxn];
vector<int>G[maxn];
int id[maxn];
int findset(int x){
	return x==p[x]?x:p[x]=findset(p[x]);
}
void unionset(int x,int y){
	p[findset(x)]=findset(y);
}
long long dp[maxn][maxn];
int main(){
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		unionset(x,y);
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(findset(i)==i)
			id[i]=++tot;
	}
	for(int i=1;i<=n;i++){
		int fa=findset(i);
		wt[id[fa]]+=a[i];
		val[id[fa]]+=b[i];
		G[id[fa]].push_back(i);
	}
	long long ans=0;
	for(int i=1;i<=tot;i++){
		for(int j=0;j<=w;j++){
			dp[i][j]=dp[i-1][j];
			if(wt[i]<=j){
				dp[i][j]=max(dp[i][j],dp[i-1][j-wt[i]]+val[i]);
			}
		}
		for(int j=0;j<=w;j++){
			for(int k=0;k<(int)G[i].size();k++){
				int cur=G[i][k];
				if(j>=a[cur])
					dp[i][j]=max(dp[i][j],dp[i-1][j-a[cur]]+b[cur]);
			}
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}