#include<bits/stdc++.h>
using namespace std;
int n,m,d;
vector<int>v[100003],rv[100003],V;
string s[100003];
bool used[100003];
void dfs(int x){
	used[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!used[v[x][i]])
			dfs(v[x][i]);
	V.push_back(x);
}
int col[100003];
void rdfs(int x,int y){
	col[x]=y;used[x]=1;
	for(int i=0;i<rv[x].size();i++)
		if(!used[rv[x][i]])
			rdfs(rv[x][i],y);
}
void init(){
	memset(used,0,sizeof(used));
	for(int i=0;i<n;i++)
		if(!used[i])
			dfs(i);
	memset(used,0,sizeof(used));
	while(V.size()){
		if(!used[V.back()])
			rdfs(V.back(),m++); 
		V.pop_back();
	}
}
bool vis[53][100003];
pair<int,int>q[50000003];
int ss,tt;
void coloring(int x,int tp){
	ss=0,tt=0;q[0]={tp,x};vis[tp][x]=1;
	while(ss<=tt){
		int nwt=(q[ss].first+1)%d,nwx=q[ss].second;ss++;
		for(int i=0;i<v[nwx].size();i++)
			if(!vis[nwt][v[nwx][i]])
				if(col[nwx]==col[v[nwx][i]]){
					vis[nwt][v[nwx][i]]=1;
					q[++tt]={nwt,v[nwx][i]};
				}
	}
}
int T[100003],val[100003],minn[100003];
int dp[53][100003],ans;
vector<int>g[100003];
void solve(int nw){
	for(int i=0;i<rv[nw].size();i++)
		for(int j=0;j<d;j++)
			dp[(j+d-val[rv[nw][i]])%T[nw]][minn[nw]]=max(dp[j][rv[nw][i]],dp[(j+d-val[rv[nw][i]])%T[nw]][minn[nw]]);
	for(int _=0;_<T[nw];_++)
		for(int i=0;i<rv[nw].size();i++){
			for(int j=(_+val[rv[nw][i]])%T[nw];j<d;j+=T[nw])
				if(s[rv[nw][i]][j]=='1'){
					dp[_][minn[nw]]++;
					break;
				}
		}
	for(int i=0;i<rv[nw].size();i++)
		for(int j=0;j<d;j++){
			ans=max(ans,dp[(j+d-val[rv[nw][i]])%T[nw]][minn[nw]]);
			dp[j][rv[nw][i]]=dp[(j+d-val[rv[nw][i]])%T[nw]][minn[nw]];
		}
	for(int i=0;i<rv[nw].size();i++)
		for(int j=0;j<v[rv[nw][i]].size();j++)
			for(int k=0;k<d;k++)
				dp[(k+1)%d][v[rv[nw][i]][j]]=max(dp[(k+1)%d][v[rv[nw][i]][j]],dp[k][rv[nw][i]]);
}
void findorder(int nw){
	used[nw]=1;
	for(int i=0;i<rv[nw].size();i++)
		for(int j=0;j<v[rv[nw][i]].size();j++)
			if(!used[col[v[rv[nw][i]][j]]])
				findorder(col[v[rv[nw][i]][j]]);
	V.push_back(nw);
}
int main(){
	cin>>n>>m>>d;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		v[x].push_back(y);
		rv[y].push_back(x);
	}m=0;
	for(int i=0;i<n;i++)
		cin>>s[i];
	init();
	memset(used,0,sizeof(used));
	for(int i=0;i<n;i++){
		if(!used[col[i]]){
			used[col[i]]=1;
			coloring(i,0);
			minn[col[i]]=i;
			T[col[i]]=d;
			for(int j=d;j>0;j--)
				if(vis[j][i])
					T[col[i]]=j;
		}
		for(int j=d;j>=0;j--)
			if(vis[j][i])
				val[i]=j;
	}
	for(int i=0;i<n;i++)
		rv[i].clear();
	for(int i=0;i<n;i++)
		rv[col[i]].push_back(i);
	V.clear();
	memset(used,0,sizeof(used));
	findorder(col[0]);
	memset(dp,192,sizeof(dp));
	dp[0][0]=0;
	while(V.size()){
		solve(V.back());
		V.pop_back();
	}cout<<ans;
}