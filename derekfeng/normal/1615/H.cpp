#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,a[1005],b[1005],A[1005],B[1005],id[1005],tg[1005],cnt;
vector<int>all,g[1005],init;
bool ans[1005];
const ll INF=1e16;
struct Dinic{
	struct edge{
		int to;ll cap;int rev;
		edge(int to,ll cap,int rev): to(to),cap(cap),rev(rev) {} 
	};
	vector<edge>g[1005];
	int n,lev[1005],iter[1005];
	bool vis[1005];
	void init(int N){
		n=N;
		for(int i=1;i<=N;i++)g[i].clear();
	}
	void addedge(int u,int v,ll w){
		g[u].push_back(edge(v,w,g[v].size()));
		g[v].push_back(edge(u,0,g[u].size()-1));
	}
	void bfs(int s){
		memset(lev,-1,(n+2)<<2);
		queue<int>que;
		lev[s]=0,que.push(s);
		while(!que.empty()){
			int u=que.front();que.pop();
			for(auto x:g[u]){
				if(x.cap==0||lev[x.to]>=0)continue;
				lev[x.to]=lev[u]+1,que.push(x.to);
			}
		}
	}
	ll dfs(int x,int t,ll F){
		if(x==t)return F;
		for(int &i=iter[x];i<g[x].size();i++){
			edge &e=g[x][i];
			if(lev[e.to]>lev[x]&&e.cap>0){
				ll d=dfs(e.to,t,min(F,e.cap));
				if(d>0){
					e.cap-=d;
					g[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	ll maxflow(int s,int t){
		ll ret=0;
		for(;;){
			bfs(s);
			if(lev[t]<0)return ret;
			memset(iter,0,(n+2)<<2);
			ll f;
			while((f=dfs(s,t,INF))>0)ret+=f;  
		}
	}
	vector<pii>getCut(int s,int t){
		vector<pii>v;
		bfs(s);
		for(int i=1;i<=n;i++)if(lev[i]!=-1)
			for(auto E:g[i])if(lev[E.to]==-1&&E.cap==0&&(i==s||E.to==t))
				v.push_back({i,E.to});
		return v;
	}
}Gr;
void solve(vector<int>v,int l,int r){
	if(l==r){
		for(auto x:v)b[x]=all[l];
		return;
	}
	int md=(l+r)>>1;
	int pl=all[md],pr=all[md+1],tot=2,S=1,T=2;
	++cnt;
	for(auto x:v)A[x]=abs(a[x]-pl),B[x]=abs(a[x]-pr),id[x]=++tot,tg[x]=cnt;
	Gr.init(tot);
	for(auto x:v){
		ll d=B[x]-A[x];
		if(d<0)Gr.addedge(S,id[x],-d),ans[id[x]]=1;
		else Gr.addedge(id[x],T,d),ans[id[x]]=0;
		for(auto y:g[x])if(tg[y]==cnt)Gr.addedge(id[x],id[y],INF);
	}
	Gr.maxflow(S,T);
	vector<pii>CUT=Gr.getCut(S,T);
	for(auto x:CUT){
		if(x.fi==S)ans[x.se]=0;
		if(x.se==T)ans[x.fi]=1;
	}
	vector<int>vl,vr;
	for(auto x:v){
		if(ans[id[x]]==0)vl.push_back(x);
		if(ans[id[x]]==1)vr.push_back(x);
	}
	solve(vl,l,md),solve(vr,md+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),all.push_back(a[i]),init.push_back(i);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	solve(init,0,all.size()-1);
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
}