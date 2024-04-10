#include<bits/stdc++.h>
using namespace std;
int n,m,s,x[300003],y[300003],w[300003],idx[200003];
vector<int>v[200003],g[200003];
long long dis[200003];
void dijkstra(){
	memset(dis,31,sizeof(dis));
	dis[s]=0;
	priority_queue<pair<long long,int> >Q;
	Q.push({0,s});
	while(Q.size()){
		long long len=-Q.top().first;
		int nw=Q.top().second;
		Q.pop();
		if(dis[nw]!=len)continue;
		for(int i=0;i<v[nw].size();i++)
			if(dis[v[nw][i]]>len+g[nw][i]){
				dis[v[nw][i]]=len+g[nw][i];
				Q.push({-dis[v[nw][i]],v[nw][i]});
			}
	}
}
bool cmp(int x,int y){
	return dis[x]<dis[y];
}
int pa[18][200003],dep[200003],ans[200003];
int lca(int x,int y){
	if(x==-1)return y;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)
		if((1<<i)&dep[x]-dep[y])
			x=pa[i][x];
	if(x==y)return x;
	for(int i=17;i>=0;i--)
		if(pa[i][x]!=pa[i][y])
			x=pa[i][x],y=pa[i][y];
	return pa[0][x];
}
int sz[200003],res;
void dfs(int x){
	sz[x]=1;
	for(int i=0;i<g[x].size();i++){
		dfs(g[x][i]);
		sz[x]+=sz[g[x][i]];
		res=max(res,sz[g[x][i]]);
	}
}
int main(){
	cin>>n>>m>>s;s--;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",x+i,y+i,w+i);
		x[i]--;y[i]--;
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
		g[x[i]].push_back(w[i]);
		g[y[i]].push_back(w[i]);
	}
	dijkstra();
	for(int i=0;i<n;i++)
		v[i].clear(),idx[i]=i,g[i].clear();
	for(int i=0;i<m;i++){
		if(dis[x[i]]+w[i]==dis[y[i]])
			v[y[i]].push_back(x[i]);
		if(dis[y[i]]+w[i]==dis[x[i]])
			v[x[i]].push_back(y[i]);
	}
	sort(idx,idx+n,cmp);
	memset(pa,-1,sizeof(pa));
	ans[s]=s; 
	for(int i=0;i<n;i++){
		if(v[idx[i]].size()==0)continue;
		ans[idx[i]]=-1;
		for(int j=0;j<v[idx[i]].size();j++)
			ans[idx[i]]=lca(ans[idx[i]],v[idx[i]][j]);
		pa[0][idx[i]]=ans[idx[i]];
		dep[idx[i]]=dep[ans[idx[i]]]+1;
		for(int j=1;j<18;j++)
			if(pa[j-1][idx[i]]!=-1)
				pa[j][idx[i]]=pa[j-1][pa[j-1][idx[i]]];
		g[ans[idx[i]]].push_back(idx[i]);
	}
	dfs(s);
	cout<<res;
}