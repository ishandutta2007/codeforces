#include<bits/stdc++.h>
using namespace std;//5003*5003*4
bool vis[5003];
pair<int,int>dp[5003][5003];
vector<pair<int,int> >v[5003],v2[5003];
int a[5003],b,n,m,c,cnt,t,tr;
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i].first])
			dfs(v[x][i].first);
	a[--cnt]=x;
}
void out(int i,int x){
	if(i==0)return;
	out(i-1,dp[i][x].second);
	cout<<x+1<<' ';
}
int main(){
	cin>>n>>m>>t;
	cnt=n;
	for(int i=0;i<m;i++)
	{
		cin>>tr>>b>>c;
		v[--tr].push_back(make_pair(--b,c));
		v2[b].push_back(make_pair(tr,c));
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i); 
	//cout<<endl;
	for(int i=0;i<5003;i++)
		for(int j=0;j<5003;j++)
			dp[i][j].first=1000000003;
	dp[1][0].first=0ll;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<v2[a[j]].size();k++)
				if(dp[i][a[j]].first>(dp[i-1][v2[a[j]][k].first].first+v2[a[j]][k].second)
				&&(dp[i-1][v2[a[j]][k].first].first+v2[a[j]][k].second)>=0)
					dp[i][a[j]].first=(dp[i-1][v2[a[j]][k].first].first+v2[a[j]][k].second),
					dp[i][a[j]].second=v2[a[j]][k].first;
		}
		/*for(int j=0;j<n;j++)
			cout<<dp[i][j].first<<' ';
		cout<<endl;*/
	}
	for(int i=n;i>0;i--)
		if(dp[i][n-1].first<=t)
		{
			cout<<i<<endl;
			out(i,n-1);
			return 0;
		}
}
//