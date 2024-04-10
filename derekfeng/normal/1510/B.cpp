#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
const int INF=1e9;
int d,n;
struct edge{
	int to,cap,rev,cost;
	edge(int to,int cap,int rev,int cost): to(to),cap(cap),rev(rev),cost(cost){}
};
vector<edge>g[2103];
void addedge(int u,int v,int w,int c){
	g[u].push_back(edge(v,w,g[v].size(),c));
	g[v].push_back(edge(u,0,g[u].size()-1,-c));
}
int s,t,N;
int pv[2103],pe[2103],h[2103],dis[2103],a[2103];
void mcmf(){
	int ret1=0,ret2=0;
	for(;;){
		fill(dis,dis+N+1,INF);
		priority_queue<pii,vector<pii>,greater<pii> >pq;
		dis[s]=0,a[s]=INF,pq.push(mkp(0,s));
		while(!pq.empty()){
			pii u=pq.top();pq.pop();
			int x=u.se,w=u.fi;
			if(x==t)break;
			if(dis[x]<w)continue;
			for(int i=0;i<g[x].size();i++){
				edge e=g[x][i];
				int w1=w+e.cost+h[x]-h[e.to];
				if(e.cap==0||dis[e.to]<=w1)continue;
				dis[e.to]=w1,pe[e.to]=i,pv[e.to]=x;
				a[e.to]=min(e.cap,a[x]);
				pq.push(mkp(w1,e.to));
			}
		}
		if(dis[t]==INF){ 
			cout<<ret2-1<<"\n";
			return;
		}
		for(int i=0;i<=N;i++)h[i]=min(h[i]+dis[i],INF);
		int b=a[t];
		ret1+=b,ret2+=b*h[t];
		int cur=t;
		while(cur!=s){
			edge &e=g[pv[cur]][pe[cur]];
			e.cap-=b,g[cur][e.rev].cap+=b;
			cur=pv[cur];
		}
	}
}
int id[1025],p[1025];
int cnt=0;
vector<int>vec[1025];
int nxt[1025],deg[1025];
int used=0;
void dfs(int x,int fr){
	used++;
	int msk=p[x]^fr;
	for(int i=0;i<d;i++)if((1<<i)&msk)printf("%d ",i);
	if(nxt[x]==0)return;
	dfs(nxt[x],p[x]);
}
int main(){
	scanf("%d%d",&d,&n);
	s=0,t=2*n+2,N=2*n+2;
	id[0]=n+1;
	for(int i=1;i<=n;i++){
		int msk=0;
		char buf[12];scanf("%s",buf);
		for(int j=0;j<d;j++)if(buf[j]=='1')msk|=(1<<j);
		id[msk]=i,p[i]=msk;
	}
	for(int i=0;i<(1<<d);i++)if(id[i]){
		for(int j=i;j;j=(j-1)&i)if(id[j]&&i!=j)
			addedge(id[j],id[i]+n+1,1,__builtin_popcount(i)-__builtin_popcount(j));
		if(i>0)addedge(id[0],id[i]+n+1,1,__builtin_popcount(i));
	}
	addedge(s,n+1,INF,1);
	for(int i=1;i<=n;i++)addedge(s,i,1,0),addedge(i+n+1,t,1,0);
	mcmf();
	for(int i=1;i<=n;i++){
		for(auto e:g[i])if(e.cap==0&&e.to>n+1){
			nxt[i]=e.to-n-1;deg[e.to-n-1]=1;break;
		}
	}
	for(int i=1;i<=n;i++)if(!deg[i]){
		dfs(i,0);
		if(used<n)putchar('R'),putchar(' ');
	}
}