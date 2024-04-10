#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,q,deg[100004],cnt;
vector<pii>tr[100004];
int len,lst,sum;
pii node,h[100004];
void dfs(int u,int fa){
	h[u]={0,u};
	for(auto [v,w]:tr[u])if(v!=fa){
		dfs(v,u);
		if(h[v].fi+h[u].fi+w>len)if(v!=fa){
			len=h[v].fi+h[u].fi+w;
			node={h[v].se,h[u].se};
		}
		if(h[v].fi+w>h[u].fi)
			h[u]={h[v].fi+w,h[v].se};		
	}
}
struct TreeInfo{
	int rt,L[100004],ls[100004];
	int N,dep[100004],tg[100004],pre[100004];
	pii C[100004];
	int par[17][100004];
	void dfs(int u,int fa){
		int tmp=dep[u];ls[u]=0;
		for(auto [v,w]:tr[u])if(v!=fa){
			dep[v]=dep[u]+w,dfs(v,u);
			if(L[v]>tmp)tmp=L[v],ls[u]=v;
		}
		L[u]=tmp;
	}
	void dfs0(int u,int fa,bool ok){
		if(ok)C[++N]={L[u]-dep[fa],u};
		if(ls[u])dfs0(ls[u],u,0);
		for(auto [v,w]:tr[u])if(v!=fa&&v!=ls[u])
			dfs0(v,u,1);
	}
	void dfs1(int u,int tag){
		while(u)tg[u]=tag,u=ls[u];
	}
	void dfs2(int u,int fa){
		par[0][u]=fa;
		for(int i=1;i<17;i++)if(par[i-1][u])
			par[i][u]=par[i-1][par[i-1][u]];
		for(auto [v,w]:tr[u])if(v!=fa)dfs2(v,u);
	}
	void built(int RT){
		rt=RT,dep[rt]=0,dfs(rt,0);
		L[0]=N=0,dfs0(rt,0,1);
		sort(C+1,C+N+1,greater<pii>());
		pre[0]=0;for(int i=1;i<=N;i++)pre[i]=pre[i-1]+C[i].fi;
		for(int i=1;i<=N;i++)dfs1(C[i].se,i);
		memset(par,0,sizeof(par)),dfs2(rt,0);
	}
	int bs(int u,int k){
		for(int i=16;~i;i--)if(par[i][u]){
			int v=par[i][u];
			if(tg[v]>k)u=v;
		}
		return par[0][u];
	}
	int qry(int u,int k){
		if(k==1)return L[u];
		if(tg[u]<=k)return pre[k];
		int t=bs(u,k-1),ans=pre[k-1]+L[u]-dep[t];
		t=bs(u,k),ans=max(ans,pre[k]+L[u]-L[t]);
		return ans;
	}
}t1,t2;
int main(){
	scanf("%d%d",&n,&q);
	if(n==1){while(q--)puts("0");return 0;}
	for(int i=1;i<n;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		tr[u].push_back({v,w}),tr[v].push_back({u,w});
		deg[u]++,deg[v]++,sum+=w;
	}
	for(int i=1;i<=n;i++)cnt+=(deg[i]==1);
	dfs(1,0);
	t1.built(node.fi);
	t2.built(node.se);
	while(q--){
		int u,k;scanf("%d%d",&u,&k);
		u=(u+lst-1)%n+1,k=(k+lst-1)%n+1;
		if(k*2>=cnt)printf("%d\n",(lst=sum));
		else{
			k=k*2-1;
			printf("%d\n",(lst=max(t1.qry(u,k),t2.qry(u,k))));
		}
	}
}