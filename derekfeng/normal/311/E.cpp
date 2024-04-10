#include<bits/stdc++.h>
using namespace std;
const int INF=(1<<30);
struct Dinic{
	struct edge{
		int to,cap,rev;
		edge(int to,int cap,int rev): to(to),cap(cap),rev(rev) {} 
	};
	vector<edge>g[12005];
	int lev[12005],iter[12005];
	void init(){
		for(int i=0;i<12005;i++)g[i].clear();
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
int n,m,g,a[10002],b[10002];
int w[2002],p[2002],c[2002],sum;
int S,T;
int main(){
	Gr.init();
	scanf("%d%d%d",&n,&m,&g),S=n+m+1,T=n+m+2;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(a[i]==0)Gr.addedge(S,i,b[i]);
		else Gr.addedge(i,T,b[i]);
	}
	for(int i=1;i<=m;i++){
		int N;scanf("%d%d%d",&c[i],&w[i],&N);
		sum+=w[i];
		while(N--){
			int x;scanf("%d",&x);
			if(c[i]==0)Gr.addedge(n+i,x,INF);
			else Gr.addedge(x,n+i,INF);
		}
		scanf("%d",&p[i]);
		if(p[i])w[i]+=g;
		if(c[i]==0)Gr.addedge(S,n+i,w[i]);
		else Gr.addedge(n+i,T,w[i]);
	}
	printf("%d",sum-Gr.maxflow(S,T));
}