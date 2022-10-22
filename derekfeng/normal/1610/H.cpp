#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,par[20][300004],dep[300004];
vector<int>tr[300004];
priority_queue<pii>pq;
int a[300004],b[300004];
int bit[300004],dfn[300004],cnt,sz[300004];
bool del[300004];
void dfs(int x){
	dfn[x]=++cnt,sz[x]=1;
	for(auto y:tr[x])
		dep[y]=dep[x]+1,dfs(y),sz[x]+=sz[y];
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;~i;i--)if((1<<i)&(dep[u]-dep[v]))u=par[i][u];
	if(u==v)return u;
	for(int i=19;~i;i--)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
	return par[0][u];
}
int getc(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int D=dep[u]-dep[v]-1;
	for(int i=19;~i;i--)if((1<<i)&D)u=par[i][u];
	return u;
}
int qr(int i){
	int res=0;
	for(;i<=n;i+=(i&-i))res+=bit[i];
	return res;
}
void upd(int i){
	for(;i;i-=(i&-i))bit[i]++;
}
int ask(int l,int r){
	return qr(l)-qr(r+1);
}
int ans;
vector<int>vec;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)scanf("%d",&par[0][i]),tr[par[0][i]].push_back(i);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)if(par[i-1][j])
			par[i][j]=par[i-1][par[i-1][j]];
	dfs(1);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(dep[a[i]]>dep[b[i]])swap(a[i],b[i]);
		int Lca=lca(a[i],b[i]);
		if(Lca==a[i]){
			if(dep[b[i]]==dep[a[i]]+1)return puts("-1"),0;
			pq.push({dep[a[i]],i}),del[i]=1;
		}
	}
	while(!pq.empty()){
		auto [w,i]=pq.top();pq.pop();
		int A=a[i],B=b[i],C=getc(A,B);
		if(ask(dfn[C],dfn[B]-1)+ask(dfn[B]+sz[B],dfn[C]+sz[C]-1)>0)continue;
		ans++,vec.push_back(C),upd(dfn[C]);
	}
	for(int i=1;i<=m;i++)if(!del[i]){
		if(ask(1,dfn[a[i]]-1)+ask(dfn[a[i]]+sz[a[i]],dfn[b[i]]-1)+ask(dfn[b[i]]+sz[b[i]],n)==0){
			ans++;
			break;
		}
	}
	printf("%d",ans);
}