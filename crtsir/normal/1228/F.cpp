#include<bits/stdc++.h>
using namespace std;
int n;
int dis[131071];
vector<int>v[131071];
vector<int>tryer,road,res;
int ans;
void dfs(int x,int l){
	for(int i=0;i<v[x].size();i++)
		if(!dis[v[x][i]])
			dis[v[x][i]]=l+1, 
			dfs(v[x][i],l+1);
}
void dfs2(int now,int t){
	tryer.push_back(now);
	if(now==t){
		road=tryer;
		return;
	}
	dis[now]=1;
	for(int i=0;i<v[now].size();i++)
		if(!dis[v[now][i]])
			dfs2(v[now][i],t);
	tryer.pop_back(); 
}
pair<int,int>check(int x){
	int cnt=0;
	vector<int>valid,spec;
	dis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!dis[v[x][i]]){
			pair<int,int>tmp=check(v[x][i]);
			if(tmp.first==0)return make_pair(0,2147483647);
			else if(tmp.first==1)valid.push_back(tmp.second);
			else spec.push_back(tmp.second);
			cnt++;
		}
	if(spec.size()>1)return make_pair(0,-1);
	sort(valid.begin(),valid.end());
	if(cnt==0)return make_pair(1,0);
	if(cnt>3)return make_pair(0,2147483647);
	if(cnt==1){
		ans=x;
		if(valid.size()==1&&valid[0]==0)return make_pair(2,1);
		else return make_pair(0,2147483647);
	}
	if(cnt==2){
		if(valid.size()>=2&&valid[0]==valid[1])return make_pair(1,valid[0]+1);
		else if(valid.size()==1&&valid[0]==spec[0])return make_pair(2,valid[0]+1);
		else return make_pair(0,2147483647);
	}
	if(cnt==3){
		ans=x;
		if(valid.size()==3&&valid[0]==valid[1]&&valid[1]+1==valid[2])return make_pair(2,valid[2]+1);
		else return make_pair(0,2147483647); 
	}
	return make_pair(0,2147483647);
}
int main(){
	cin>>n;
	for(int i=3;i<pow(2,n);i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dis[0]=1;
	dfs(0,1);
	pair<int,int>tmp=make_pair(0,0);
	for(int i=0;i<pow(2,n)-1;i++)
		tmp=max(tmp,make_pair(dis[i],i));
	int s=tmp.second;
	memset(dis,0,sizeof(dis));
	dis[s]=1;
	dfs(s,1);
	tmp.first=0;
	for(int i=0;i<pow(2,n-1);i++)
		tmp=max(tmp,make_pair(dis[i],i));
	int t=tmp.second;
	memset(dis,0,sizeof(dis));
	dfs2(s,t);
	for(int i=max(0,int(road.size()/2-2));i<=min(road.size()-1,road.size()/2+3);i++)
	{
		memset(dis,0,sizeof(dis));
		pair<int,int>resulty=check(road[i]);
		if(resulty.first==2)
			res.push_back(ans);
	}
	cout<<res.size()<<endl;
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++)cout<<res[i]+1<<' ';
}