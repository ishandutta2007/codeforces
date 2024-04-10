#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> G[100010];
int ed[100010][3],dfn[100010],deg[100010];
bool check(int c){
	for(int i=1;i<=n;i++){
		G[i].clear();
		deg[i]=dfn[i]=0;
	}
	for(int i=1;i<=m;i++){
		if(ed[i][2]>c){
			G[ed[i][0]].push_back(ed[i][1]);
			deg[ed[i][1]]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
	int tot=0;
	while(q.size()){
		int x=q.front();q.pop();
		dfn[x]=++tot;
		for(int i=0;i<G[x].size();i++){
			deg[G[x][i]]--;
			if(!deg[G[x][i]]) q.push(G[x][i]);
		}
	}
	return tot==n;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d %d %d",&ed[i][0],&ed[i][1],&ed[i][2]);
	int l=0,r=1e9,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	check(l);
	vector<int> vec;
	for(int i=1;i<=m;i++){
		if(dfn[ed[i][1]]<dfn[ed[i][0]]) vec.push_back(i);
	}
	printf("%d %d\n",l,vec.size());
	for(int i=0;i<vec.size();i++) printf("%d ",vec[i]);
}