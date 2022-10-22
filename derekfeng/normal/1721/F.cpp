#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=(1<<20);
int n1,n2,m,q;
vector<int>vec;
vector<pii>edg;
bool del[400004];
int mch[400004];
struct Dinic{
	struct edge{
		int to,cap,rev;
		edge(int to,int cap,int rev): to(to),cap(cap),rev(rev) {} 
	};
	vector<edge>g[400004];
	int lev[400004],iter[400004];
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
	void sfb(int s){
		memset(lev,-1,sizeof(lev));
		queue<int>que;
		lev[s]=0,que.push(s);
		while(!que.empty()){
			int u=que.front();que.pop();
			for(auto x:g[u]){
				if(x.cap>0||lev[x.to]>=0)continue;
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
	void getans(){
		bfs(0);
		for(int i=1;i<=n1;i++)if(lev[i]<0)
			vec.push_back(i);
		sfb(n1+n2+1);
		for(int i=1;i<=n2;i++)if(lev[n1+i]<0)
			vec.push_back(n1+i);
		for(int i=1;i<=n1;i++)
			for(auto e:g[i])if(e.to!=0&&e.cap==0)
				edg.push_back({i,e.to});
	}
}Gr;
map<pii,int>mp;
int main(){
	scanf("%d%d%d%d",&n1,&n2,&m,&q);
	for(int i=1;i<=n1;i++)Gr.addedge(0,i,1);
	for(int i=1;i<=n2;i++)Gr.addedge(n1+i,n1+n2+1,1);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		Gr.addedge(u,n1+v,1),mp[{u,n1+v}]=i;
	}
	int ans=Gr.maxflow(0,n1+n2+1);ll sm=0;
	Gr.getans();
	for(auto [a,b]:edg)mch[a]=b,mch[b]=a,sm+=mp[{a,b}];
	while(q--){
		int op;scanf("%d",&op);
		if(op==1){
			ans--;
			while(!vec.empty()){
				int u=vec.back();
				if(!del[u])break;
				vec.pop_back();
			}
			if(!vec.empty()){
				int u=vec.back(),U=u;vec.pop_back();
				int v=mch[u];if(u>v)swap(u,v);
				sm-=mp[{u,v}],del[u]=del[v]=1;
				puts("1");
				printf("%d\n",U<=n1?U:n1-U);
			}else{
				while(!edg.empty()){
					auto [a,b]=edg.back();
					if(!del[a])break;
					edg.pop_back();
				}
				auto [u,v]=edg.back();
				edg.pop_back(),sm-=mp[{u,v}];
				puts("2");
				printf("%d %d\n",u,n1-v);
			}
			printf("%lld\n",sm);
		}else{
			printf("%d\n",ans);
			for(auto [a,b]:edg)
				if(!del[a])printf("%d ",mp[{a,b}]);puts("");
		}
		fflush(stdout);
	}
}