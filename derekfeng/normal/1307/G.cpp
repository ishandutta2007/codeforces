#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int Inf=0x3f3f3f3f;
struct edge{
	int to,cap,rev,cost;
	edge(int to,int cap,int rev,int cost): to(to),cap(cap),rev(rev),cost(cost){}
};
vector<edge>g[53];
void addedge(int u,int v,int w,int c){
	g[u].push_back(edge(v,w,g[v].size(),c));
	g[v].push_back(edge(u,0,g[u].size()-1,-c));
}
ld Min(const ld A,const ld B){return A<B?A:B;}
int n,m,u,v,w,q,x,cnt,f[53],C[53],dis[53];
ld ans;
bool ins[53];
int	lste[53],lstv[53],cap[53];
void spfa(){
	queue<int>que;
	for(int i=1;i<=n;i++)dis[i]=Inf;
	dis[1]=0,que.push(1),cap[1]=Inf;
	while(!que.empty()){
		int u=que.front();que.pop();ins[u]=0;
		for(edge &e:g[u])if(e.cap>0){
			int W=dis[u]+e.cost;
			if(W<dis[e.to]){
				dis[e.to]=W,cap[e.to]=min(cap[u],e.cap);
				lste[e.to]=e.rev,lstv[e.to]=u;
				if(!ins[e.to])que.push(e.to);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d%d",&u,&v,&w),addedge(u,v,1,w);
	while(1){
		spfa();
		if(dis[n]==Inf)break;
		int cost=dis[n],flow=cap[n];
		for(int i=n;i>1;i=lstv[i]){
			edge &e=g[i][lste[i]];
			e.cap+=flow;
			g[lstv[i]][e.rev].cap-=flow;
		}
		++cnt;
		f[cnt]=f[cnt-1]+flow,C[cnt]=C[cnt-1]+cost*flow;
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x),ans=Inf;
		for(int i=1;i<=cnt;i++)ans=Min(ans,(ld)(C[i]+x)/(ld)f[i]);
		printf("%.6Lf\n",ans);
	}
}