#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int INF=(1<<20);
struct Dinic{
	struct edge{
		int to,cap,rev;
		edge(int to,int cap,int rev): to(to),cap(cap),rev(rev) {} 
	};
	vector<edge>g[105];
	int lev[105],iter[105];
	void init(int N){
		for(int i=1;i<=N;i++)g[i].clear();
	}
	void addedge(int u,int v,int w){
		g[u].push_back(edge(v,w,g[v].size()));
		g[v].push_back(edge(u,0,g[u].size()-1));
	}
	void bfs(int s){
		memset(lev,-1,sizeof(lev));
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
	int dfs(int x,int t,int F){
		if(x==t)return F;
		for(int &i=iter[x];i<g[x].size();i++){
			edge &e=g[x][i];
			if(lev[e.to]>lev[x]&&e.cap>0){
				int d=dfs(e.to,t,min(F,e.cap));
				if(d>0){
					e.cap-=d;
					g[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	int maxflow(int s,int t){
		int ret=0;
		for(;;){
			bfs(s);
			if(lev[t]<0)return ret;
			memset(iter,0,sizeof(iter));
			int f;
			while((f=dfs(s,t,INF))>0)ret+=f; 
		}
	}
}Gr;
int pri[200005],tot;
bool flg[200005];
void init(){
	for(int i=2;i<=2e5;i++){
		if(!flg[i])pri[++tot]=i;
		for(int j=1;j<=tot&&i*pri[j]<=2e5;j++){
			flg[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int n,K;
int p[105],c[105],l[105];
bool check(int x){
	int mx=-1;
	vector<pii>f,g;
	for(int i=1;i<=n;i++)if(l[i]<=x){
		if(c[i]==1)mx=max(mx,p[i]);
		else{
			if(c[i]&1)f.push_back({c[i],p[i]});
			else g.push_back({c[i],p[i]});
		}
	}
	if(mx!=-1)f.push_back({1,mx});
	int P=f.size(),Q=g.size(),sum=0;
	for(int i=0;i<P;i++)sum+=f[i].se;
	for(int i=0;i<Q;i++)sum+=g[i].se;
	Gr.init(P+Q+2);
	for(int i=1;i<=P;i++)Gr.addedge(P+Q+1,i,f[i-1].se);
	for(int i=1;i<=Q;i++)Gr.addedge(P+i,P+Q+2,g[i-1].se);
	for(int i=1;i<=P;i++)for(int j=1;j<=Q;j++)if(!flg[f[i-1].fi+g[j-1].fi])
		Gr.addedge(i,P+j,INF);
	return sum-Gr.maxflow(P+Q+1,P+Q+2)>=K;
}
int main(){
	init();
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i],&c[i],&l[i]);
	int ld=-1,rd=101;
	while(rd>ld+1){
		int md=(ld+rd)/2;
		if(check(md))rd=md;
		else ld=md;
	}
	if(!check(rd))puts("-1");
	else printf("%d",rd);
}