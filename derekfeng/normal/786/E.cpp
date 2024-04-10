#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=1e5;
struct Dinic{
	struct edge{
		int to,cap,rev;
		edge(int to,int cap,int rev): to(to),cap(cap),rev(rev) {} 
	};
	vector<edge>g[60004];int lev[60004],iter[60004];
	void addedge(int u,int v,int w){
		g[u].push_back(edge(v,w,g[v].size()));
		g[v].push_back(edge(u,0,g[u].size()-1));
	}
	void bfs(int s){
		memset(lev,-1,sizeof(lev));queue<int>que;lev[s]=0,que.push(s);
		while(!que.empty()){
			int u=que.front();que.pop();
			for(auto x:g[u]){
				if(x.cap==0||lev[x.to]>=0)continue;
				lev[x.to]=lev[u]+1,que.push(x.to);
			}
		}
	}
	int dfs(int x,int t,int F){
		if(x==t)return F;
		for(int &i=iter[x];i<g[x].size();i++){
			edge &e=g[x][i];if(lev[e.to]>lev[x]&&e.cap>0){
				int d=dfs(e.to,t,min(F,e.cap));
				if(d>0){e.cap-=d;g[e.to][e.rev].cap+=d;return d;}
			}
		}return 0;
	}
	int maxflow(int s,int t){
		int ret=0;for(;;){
			bfs(s);if(lev[t]<0)return ret;
			memset(iter,0,sizeof(iter));
			int f;while((f=dfs(s,t,INF))>0)ret+=f; 
		}
	}
	vector<pii>getCut(int s,int t){
		vector<pii>v;bfs(s);
		for(int i=1;i<=t;i++)if(lev[i]!=-1)
			for(auto E:g[i])if(lev[E.to]==-1&&E.cap==0&&(i==s||E.to==t))
				v.push_back({i,E.to});
		return v;
	}
}Gr;
vector<pii>tr[20004];int n,m,N,fi[20004];
int sz[20004],hs[20004],fa[20004],cnt;
int nx[20004],dfn[20004],inv[20004];
void dfs(int x){
	sz[x]=1;
	for(auto [y,i]:tr[x])if(y!=fa[x]){
		fa[y]=x,fi[y]=i,dfs(y),sz[x]+=sz[y];
		if(sz[y]>sz[hs[x]])hs[x]=y;
	}
}
void dfs0(int x,int H){
	dfn[x]=++cnt,inv[cnt]=x,nx[x]=H;
	if(hs[x])dfs0(hs[x],H);
	for(auto [y,i]:tr[x])if(y!=fa[x]&&y!=hs[x])dfs0(y,y);
}
void init(int l,int r){
	if(l!=r){
		int md=(l+r)>>1;
		int id=(l+r)|(l!=r);
		int ls=(l+md)|(l!=md);
		int rs=(md+1+r)|(md+1!=r);
		Gr.addedge(ls,id,INF),Gr.addedge(rs,id,INF);
		init(l,md),init(md+1,r);
	}
}
void upd(int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){Gr.addedge((l+r)|(l!=r),x,INF);return;}
	int md=(l+r)>>1;upd(l,md,a,b,x),upd(md+1,r,a,b,x);
}
void qry(int x,int u,int v){
	for(;;){
		if(dfn[v]<dfn[u])swap(u,v);
		int t=nx[v];
		if(dfn[t]<=dfn[u]&&dfn[u]<=dfn[v]){
			upd(1,n,dfn[u]+1,dfn[v],x);return;
		}upd(1,n,dfn[t],dfn[v],x),v=fa[t];
	}
}
int main(){
	scanf("%d%d",&n,&m),N=n+n;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		tr[u].push_back({v,i}),tr[v].push_back({u,i});
	}
	dfs(1),dfs0(1,1),init(1,n);
	for(int i=1;i<=n;i++)Gr.addedge(N+m+1,i<<1,1);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		Gr.addedge(N+i,N+m+2,1),qry(N+i,u,v);
	}
	printf("%d\n",Gr.maxflow(N+m+1,N+m+2));
	vector<pii>ans=Gr.getCut(N+m+1,N+m+2);
	vector<int>ans0,ans1;
	for(auto[a,b]:ans)if(a==N+m+1)ans0.push_back(b);
	for(auto[a,b]:ans)if(b==N+m+2)ans1.push_back(a);
	printf("%d ",(int)ans1.size());
	for(auto x:ans1)printf("%d ",x-N);puts("");
	printf("%d ",(int)ans0.size());
	for(auto x:ans0)printf("%d ",fi[inv[x>>1]]);;
}