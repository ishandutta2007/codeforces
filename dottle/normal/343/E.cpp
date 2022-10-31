#include<bits/stdc++.h>
using namespace std;
int read() {
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
const int N=1005,INF=1e9;
int n,m;
namespace maxflow {
	struct Edge {
		int v,nxt,flow;
	}e[N*5],te[N*5];
	int head[N],cur[N],thead[N],sze=1,S,T,dep[N];
	void clear() {
		memcpy(head,thead,sizeof(head));
		memcpy(e,te,sizeof(e));
	}
	void link(int u,int v,int flow) {
		te[++sze].v=v;
		te[sze].nxt=thead[u];
		te[sze].flow=flow;
		thead[u]=sze;
	}
	void Elink(int u,int v,int flow) {
		link(u,v,flow);
		link(v,u,flow);
	}
	bool bfs() {
		queue<int>q;q.push(S);
		memset(dep,-1,sizeof(dep));
		dep[S]=0;
		while(!q.empty()) {
			int u=q.front();q.pop();
			for(int i=head[u];i;i=e[i].nxt) {
				int v=e[i].v;
				if(dep[v]==-1&&e[i].flow>0) {
					dep[v]=dep[u]+1;
					q.push(v);
				}
			}
		}
		return dep[T]!=-1;
	}
	int dfs(int u,int a) {
		if(u==T||a==0)return a;
		int flow=0,d;
		for(int &i=cur[u];i;i=e[i].nxt) {
			int v=e[i].v;
			if(dep[v]==dep[u]+1&&((d=(dfs(v,min(a,e[i].flow))))>0)) {
				a-=d;
				flow+=d;
				e[i].flow-=d;
				e[i^1].flow+=d;
				if(a==0)break;
			}
		}
		return flow;
	}
	int Dinic(int SS,int TT) {
		S=SS;T=TT;
		int flow=0;
		while(bfs()) {
			for(int i=0;i<=n;++i)cur[i]=head[i];
			flow+=dfs(S,INF);
		}
		return flow;
	}
}
int totm,totn,fa[N],lst=-1,val[N],dep[N],hhh;
struct E {int u,v,w;}e[N];
vector<int>G[N],ans;
void build(vector<int>S) {
	if(S.size()==1)return;
	maxflow::clear();
	int U=S.front(),V=S.back();
	e[++totm]={U,V,maxflow::Dinic(U,V)};
	vector<int>lS,rS;
	for(int v:S)
		if(maxflow::dep[v]==-1)rS.push_back(v);
		else lS.push_back(v);
	vector<int>().swap(S);
	build(lS);build(rS);
}
int find(int x) {
	if(fa[x]==x)return x;
	return find(fa[x]);
}
int lca(int x,int y) {
	while(x!=y) {
		if(dep[x]<dep[y])y=fa[y];
		else x=fa[x];
	}
	return x;
}
void dfs(int u) {
	for(int v:G[u])dep[v]=dep[u]+1,dfs(v);
	if(G[u].empty())ans.push_back(u);
}
int main() {
	n=read();m=read();
	vector<int>all;
	for(int i=1;i<=n;++i)all.push_back(i);
	for(int i=1;i<=m;++i) {
		int u=read(),v=read(),w=read();
		maxflow::Elink(u,v,w);
	}
	build(all);
	sort(e+1,e+totm+1,[](E p,E q){return p.w>q.w;});
	totn=n;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=totm;++i) {
		int u=find(e[i].u),v=find(e[i].v);
		++totn;fa[totn]=totn;val[totn]=e[i].w;
		G[totn].push_back(u);G[totn].push_back(v);
		fa[u]=fa[v]=totn;
	}
	dfs(totn);
	for(int i=0;0<ans.size()-1-i;++i)hhh+=val[lca(ans[i],ans[i+1])];
//	hhh+=val[lca(ans.front(),ans.back())];
	printf("%d\n",hhh);
	for(int v:ans)printf("%d ",v);
	return 0;
}