#include<bits/stdc++.h>
using namespace std;
int n,x[2003],y[2003],dp[4003][4003],circ[4003][4003];
vector<int>v[4003],ans; 
int dfs(int l,int r){
	if(l==r)return bool(circ[l][r]);
	if(dp[l][r]>=0)return dp[l][r];
	dp[l][r]=max(dfs(l,r-1),dfs(l+1,r));
	for(int i=0;i<v[r].size();i++)
		if(x[v[r][i]]>=l)
			dp[l][r]=max(dp[l][r],dfs(l,x[v[r][i]])+dfs(x[v[r][i]],r));
	dp[l][r]+=bool(circ[l][r]);
	return dp[l][r];
}
void path(int l,int r){
	if(circ[l][r])ans.push_back(circ[l][r]);
	if(l==r)return;
	if(dp[l][r]==bool(circ[l][r])+dp[l][r-1]){path(l,r-1);return;}
	if(dp[l][r]==bool(circ[l][r])+dp[l+1][r]){path(l+1,r);return;}
	for(int i=0;i<v[r].size();i++)
		if(x[v[r][i]]>l)
			if(dp[l][r]==bool(circ[l][r])+dp[l][x[v[r][i]]]+dp[x[v[r][i]]][r]){
				path(l,x[v[r][i]]);path(x[v[r][i]],r);return;
			}
}
int main(){
	cin>>n;
	vector<int>tmp;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;x[i]=a-b;y[i]=a+b; 
		tmp.push_back(a-b);
		tmp.push_back(a+b);
	}
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	map<int,int>mp;int cnt=0;
	for(int i=0;i<tmp.size();i++)mp[tmp[i]]=cnt++;
	for(int i=0;i<n;i++)
		x[i]=mp[x[i]],y[i]=mp[y[i]];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)circ[x[i]][y[i]]=i+1,v[y[i]].push_back(i);
	cout<<dfs(0,cnt-1)<<endl;
	path(0,cnt-1);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
}