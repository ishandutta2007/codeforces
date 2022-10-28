#include<bits/stdc++.h>
using namespace std;
#define N 8888
const int inf=0x3f3f3f3f;
typedef long long ll;
namespace MCMF{
	int head[N];
	int ecnt,S,T;
	struct Edge{
		int nxt,to,val,cost;
	}edge[N<<4];
	void add(int a,int b,int c,int d){
		edge[++ecnt]={head[a],b,c,d};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c,int d){
		add(a,b,c,d);
		add(b,a,0,-d);
	}
	void init(int _S,int _T){
		memset(head,0,sizeof(head));
		ecnt=1;
		S=_S,T=_T;
	}
	int vis[N],dis[N],maxcost;
	queue<int> q;
	bool SPFA(){
		memset(dis,~0x3f,sizeof(dis));
		q.push(S);
		dis[S]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].val&&dis[v]<dis[u]+edge[i].cost){
					dis[v]=dis[u]+edge[i].cost;
					if(!vis[v]){
						q.push(v),vis[v]=1;
					}
				}
			}
		}
		return dis[T]>-inf;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		vis[u]=1;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]==dis[u]+edge[i].cost&&!vis[v]&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
				maxcost+=k*edge[i].cost;
			}
		}
		vis[u]=0;
		if(!flow)dis[u]=inf;
		return flow;	
	}
	pair<int,int> Dinic(){
		maxcost=0;
		int maxflow=0;
		while(SPFA()){
			maxflow+=dfs(S,inf);
		}
		return make_pair(maxflow,maxcost);
	}
}
int n,K,a[1<<20],vis[1<<20],cnt,id[1<<20];
mt19937 rnd(time(0));
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	K=min(K,1<<n-1);
	for(int i=0;i<(1<<n);++i){
		cin>>a[i];
	}
	for(int j=0;j<n;++j){
		static int p[1<<20];
		for(int i=0;i<(1<<n);++i)p[i]=i;
		nth_element(p,p+2*K,p+(1<<n),[&](int x,int y){return a[x^(1<<j)]+a[x]>a[y^(1<<j)]+a[y];});
		for(int i=0;i<2*K;++i){
			vis[p[i]]=1;	
		}
	}
	for(int i=0;i<(1<<n);++i){
		if(vis[i])id[i]=++cnt;	
	}
	MCMF::init(cnt+2,cnt+3);
	MCMF::adde(cnt+2,cnt+1,K,0);
	for(int i=0;i<(1<<n);++i){
		if(vis[i]){
			if(__builtin_popcount(i)&1)MCMF::adde(id[i],MCMF::T,1,a[i]);
			else MCMF::adde(cnt+1,id[i],1,a[i]);
		}	
	}
	for(int i=0;i<(1<<n);++i){
		if(!vis[i]||__builtin_popcount(i)&1)continue;
		for(int j=0;j<n;++j){
			if(vis[i^(1<<j)]){
				MCMF::adde(id[i],id[i^(1<<j)],1,0);
			}	
		}
	}
	cout<<MCMF::Dinic().second<<'\n';
	return 0;
}