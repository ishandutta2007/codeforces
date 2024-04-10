#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
const int INF=1e9;
int n,m,s,t;
struct edge{
	int to,cap,rev,cost;
	edge(int to,int cap,int rev,int cost): to(to),cap(cap),rev(rev),cost(cost){}
};
vector<edge>g[110];
void addedge(int u,int v,int w,int c){
	g[u].push_back(edge(v,w,g[v].size(),c));
	g[v].push_back(edge(u,0,g[u].size()-1,-c));
}
int pv[110],pe[110],h[110],dis[110],a[110];
void mcmf(){
	int ret1=0,ret2=0;
	for(;;){
		fill(dis+1,dis+n*2+5,INF);
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
			printf("%d",ret2);
			return;
		}
		for(int i=1;i<=n*2+4;i++)h[i]=min(h[i]+dis[i],INF);
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
int L[55],R[55];
int main(){
	scanf("%d%d",&n,&m);
	s=n+n+1,t=n+n+2;
	for(int i=1;i<=n;i++)L[i]=1,R[i]=n;
	for(int i=1;i<=m;i++){
		int op,l,r,v;scanf("%d%d%d%d",&op,&l,&r,&v);
		for(int j=l;j<=r;j++){
			if(op==1)L[j]=max(L[j],v);
			else R[j]=min(R[j],v);
			if(L[j]>R[j])return puts("-1"),0;
		}
	}
	for(int i=1;i<=n;i++)addedge(s,i,1,0);
	for(int i=1;i<=n;i++)for(int j=L[i];j<=R[i];j++)addedge(i,j+n,1,0);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)addedge(i+n,t,1,j*j-(j-1)*(j-1));
	mcmf();
}