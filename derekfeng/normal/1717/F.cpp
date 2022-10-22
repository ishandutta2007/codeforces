#include<bits/stdc++.h>
using namespace std;
const int INF=(1<<30);
struct Dinic{
	struct edge{
		int to,cap,rev;
		edge(int to,int cap,int rev): to(to),cap(cap),rev(rev) {} 
	};
	vector<edge>g[20005];
	int lev[20005],iter[20005];
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
int n,m,deg[10005];
int a[10005],s[10005];
int u[10005],v[10005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		deg[u[i]]--,deg[v[i]]--,Gr.addedge(0,i,1);
		Gr.addedge(i,m+u[i],1),Gr.addedge(i,m+v[i],1);
	}
	int w=0;
	for(int i=1;i<=n;i++)if(s[i]==1){
		if((a[i]-deg[i])&1)return puts("NO"),0;
		if(a[i]<deg[i])return puts("NO"),0;
		Gr.addedge(m+i,n+m+1,(a[i]-deg[i])>>1);
		w+=(a[i]-deg[i])>>1;
	}
	if(Gr.maxflow(0,n+m+1)!=w)return puts("NO"),0;
	for(int i=1;i<=n;i++)if(s[i]==0)Gr.addedge(m+i,n+m+1,INF);
	if(w+Gr.maxflow(0,n+m+1)!=m)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=m;i++){
		int pos=-1;
		for(auto e:Gr.g[i])if(e.to!=0&&e.cap==0)pos=e.to-m;
		printf("%d %d\n",(u[i]^v[i]^pos),pos);
	}
}