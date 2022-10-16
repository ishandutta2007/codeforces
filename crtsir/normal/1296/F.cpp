#include<bits/stdc++.h>
using namespace std;
int n,m,a[5003],b[5003],x[5003],y[5003],g[5003],s[5003],val[5003];
vector<pair<int,int> >v[5003];
vector<int>path;
bool cmp(int nx,int ny){
	return g[nx]<g[ny];
}
bool vis[5003];
void dfs(int nx,int ny,int nz){
	if(vis[nx]==1)return;
	vis[nx]=1;
	if(nx==ny){
		for(int i=0;i<path.size();i++)val[path[i]]=nz;
		vis[nx]=0;
		return;
	}
	for(int i=0;i<v[nx].size();i++){
		path.push_back(v[nx][i].second);
		dfs(v[nx][i].first,ny,nz);
		path.pop_back();
	}
	vis[nx]=0;
}
bool dfs2(int nx,int ny,int nz){
	if(vis[nx]==1)return 0;
	vis[nx]=1;
	if(nx==ny){
		bool ret=0;
		for(int i=0;i<path.size();i++)ret|=(val[path[i]]==nz);
		vis[nx]=0;
		return ret;
	}
	bool ret=0;
	for(int i=0;i<v[nx].size();i++){
		path.push_back(v[nx][i].second);
		ret|=dfs2(v[nx][i].first,ny,nz);
		path.pop_back();
	}
	vis[nx]=0;
	return ret;
}
bool check(int i){
	return dfs2(a[s[i]],b[s[i]],g[s[i]]);
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++)cin>>x[i]>>y[i],x[i]--,y[i]--,v[x[i]].push_back(make_pair(y[i],i)),v[y[i]].push_back(make_pair(x[i],i));
	for(int i=0;i<n-1;i++)val[i]=1e6;
	cin>>m;
	for(int i=0;i<m;i++){cin>>a[i]>>b[i]>>g[i];a[i]--;b[i]--;s[i]=i;}
	sort(s,s+m,cmp);
	for(int i=0;i<m;i++)dfs(a[s[i]],b[s[i]],g[s[i]]);
	for(int i=0;i<m;i++)
		if(!check(i)){
			cout<<-1;
			return 0;
		}
	for(int i=0;i<n-1;i++)cout<<val[i]<<' ';
}