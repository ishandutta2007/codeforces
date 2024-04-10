#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,sz[1000005],w[1000005];
int lst[1000005],rt[1000005];
vector<int>g[1000005];
int sta[1000005],N,num[1000005];
vector<int>ask[1000005];
vector<int>info[1000005];
int all[1000005];
void dfs(int x,int pa){
	sz[x]=1,sta[++N]=x;
	int nlst,W=w[x];
	if(x>n){
		rt[x]=sta[lst[W]+1];
		nlst=lst[W],lst[W]=N;
	}
	for(auto y:g[x])if(y!=pa)
		dfs(y,x),sz[x]+=sz[y];
	if(x>n){
		lst[W]=nlst;--N;
		for(auto y:g[x])if(y!=pa)
			info[x].push_back(sz[y]-num[y]);
		if(rt[x]==1)all[w[x]]+=sz[x];
		num[rt[x]]+=sz[x];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d%d",&u,&v,&w[n+i]);
		g[u].push_back(n+i),g[n+i].push_back(u);
		g[v].push_back(n+i),g[n+i].push_back(v);
	}
	dfs(1,0);
	ll ans=0;
	for(int i=n+1;i<n+n;i++){
		ll s=0,z=0;
		if(rt[i]==1)z=n+n-1-all[w[i]];
		else z=sz[rt[i]]-num[rt[i]];
		info[i].push_back(z);
		for(auto x:info[i]){
			int t=(x+1)/2;
			ans+=s*t,s+=t;
		}
	}
	printf("%lld",ans);
}