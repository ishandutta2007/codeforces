#include<bits/stdc++.h>
using namespace std;vector<int>v[233];
int n,k,dis[233][233],dp[233][233],cst[233],res[233],realans[233];
void dfs(int x,int p){
	for(int i=0;i<n;i++)dp[x][i]=cst[dis[x][i]]+k;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p){
			dfs(v[x][i],x);
			for(int j=0;j<n;j++)
				dp[x][j]+=min(dp[v[x][i]][res[v[x][i]]],dp[v[x][i]][j]-k);
		}
	pair<int,int>ans=make_pair(233333333,233333333);
	for(int i=0;i<n;i++)
		ans=min(ans,make_pair(dp[x][i],i));
	res[x]=ans.second;
}
void pth(int x,int p,int nw){
	realans[x]=nw;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			if(dp[v[x][i]][res[v[x][i]]]<dp[v[x][i]][nw]-k)
				pth(v[x][i],x,res[v[x][i]]);
			else
				pth(v[x][i],x,nw);
}
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++)cin>>cst[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dis[i][j]=2333;
	for(int i=0;i<n;i++)
		dis[i][i]=0;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;a--;b--;
		dis[a][b]=1;
		dis[b][a]=1;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(0,-1);
	cout<<dp[0][res[0]]<<endl;
	pth(0,-1,res[0]);
	for(int i=0;i<n;i++)cout<<realans[i]+1<<' ';
}