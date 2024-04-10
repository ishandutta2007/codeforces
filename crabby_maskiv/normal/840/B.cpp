#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m;
vector<int> c[N];
int fa[N];
int d[N];
int uu[N],vv[N];
vector<int> g[N];
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
void merge(int u,int v){
	u=rt(u);v=rt(v);
	if(u==v) return;
	fa[u]=v;
}
vector<int> ans;
bool vis[N];
int cur[N];
void dfs(int u){
	vis[u]=1;
	for(auto i:g[u]){
		int v=vv[i],w=uu[i];
		if(v==u) v=w;
		if(vis[v]||d[v]==-1) continue;
		dfs(v);
		if(cur[v]!=d[v]){
			cur[v]^=1;
			cur[u]^=1;
			ans.push_back(i);
		}
	}
}
void solve(const vector<int> &a){
	vector<int> tmp;
	int cnt=0;
	for(auto u:a){
		cnt+=d[u];
		for(auto i:g[u]){
			int v=vv[i],w=uu[i];
			if(v==u) v=w;
			if(d[v]==-1)
				tmp.push_back(i);
		}
	}
	if(tmp.size()==0&&(cnt&1)){
		cout<<-1;
		exit(0);
	}
	tmp.resize(cnt&1);
	for(auto i:tmp){
		ans.push_back(i);
		if(d[uu[i]]==-1) cur[vv[i]]=1;
		else cur[uu[i]]=1;
	}
	dfs(a[0]);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>d[i];
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++){
		cin>>uu[i]>>vv[i];
		g[uu[i]].push_back(i);
		g[vv[i]].push_back(i);
		if(d[uu[i]]>=0&&d[vv[i]]>=0)
			merge(uu[i],vv[i]);
	}
	for(i=1;i<=n;i++)
		c[rt(i)].push_back(i);
	for(i=1;i<=n;i++)
		if(c[i].size()>0&&d[i]!=-1) solve(c[i]);
	cout<<ans.size()<<endl;
	for(auto x:ans)
		cout<<x<<endl;
	return 0;
}