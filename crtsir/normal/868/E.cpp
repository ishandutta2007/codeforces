#include<bits/stdc++.h>
using namespace std;
vector<int>v[53],g[53];
int n,rt,m,sz[53];
int calcsz(int x,int p){
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			sz[x]+=calcsz(v[x][i],x);
	return sz[x];
}
int dp[53][53][53][53],val[53][53];
int solve(int x,int y,int sz1,int sz2){
	if(!(sz1+sz2))
		return 0;
	if(dp[x][y][sz1][sz2]>=0)
		return dp[x][y][sz1][sz2];
	if(v[y].size()==1)
		if(sz2){
			dp[x][y][sz1][sz2]=solve(y,x,sz2,0)+val[x][y];
			return dp[x][y][sz1][sz2];
		}else
			return 0;
	int f[53];
	memset(f,0,sizeof(f));
	f[0]=19260817;
	for(int i=0;i<v[y].size();i++)
		if(v[y][i]!=x)
			for(int j=sz1;j;j--)
				for(int k=j;k;k--)
					f[j]=max(f[j],min(f[j-k],solve(y,v[y][i],k,sz1+sz2-k)+g[y][i]));
	dp[x][y][sz1][sz2]=f[sz1];
	return f[sz1];
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;a--;b--;
		v[a].push_back(b);
		g[a].push_back(c);
		v[b].push_back(a);
		g[b].push_back(c);
		val[a][b]=c;
		val[b][a]=c;
	}
	cin>>rt>>m;rt--;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		sz[x-1]++;
	}
	calcsz(rt,-1);
	int ans=19260817;
	memset(dp,192,sizeof(dp));
	for(int i=0;i<v[rt].size();i++)
		ans=min(ans,solve(rt,v[rt][i],sz[v[rt][i]],m-sz[v[rt][i]])+g[rt][i]);
	cout<<ans;
}