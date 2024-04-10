#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
#define fi first
#define se second
#define mkp make_pair
struct edge{
	int to,rev,cap,cost;
	edge(int a,int b,int c,int d):to(a),rev(b),cap(c),cost(d){}
};
vector<edge>g[20005];
void addedge(int fr,int to,int cap,int cost){
	g[fr].push_back(edge(to,(int)g[to].size(),cap,cost));
	g[to].push_back(edge(fr,(int)g[fr].size()-1,0,-cost));
}
int n,K,b[5005];
int dis[20005],h[20005];
int pe[20005],pv[20005],a[20005];
bool ins[20005];
pii MCMF(int s,int t){
	pii ret=mkp(0,0);
	while(1){
		queue<int>que;
		fill(dis,dis+4+4*n,INF);
		fill(ins,ins+4+4*n,0);
		dis[s]=0,que.push(s),a[s]=INF,ins[s]=1;
		while(!que.empty()){
			int x=que.front();que.pop(),ins[x]=0;
			int w=dis[x];
			for(int i=0;i<g[x].size();i++){
				edge e=g[x][i];
				int w1=w+e.cost+h[x]-h[e.to];
				if(e.cap>0&&dis[e.to]>w1){
					dis[e.to]=w1;
					pe[e.to]=i;
					pv[e.to]=x;
					a[e.to]=min(e.cap,a[x]);
					if(!ins[e.to])ins[e.to]=1,que.push(e.to);
				}
			}
		}
		if(dis[t]==INF)return ret;
		for(int i=0;i<=4*n+4;i++)h[i]=min(h[i]+dis[i],INF);
		int b=a[t];
		ret.fi+=b,ret.se+=b*h[t];
		for(int i=t;i!=s;){
			int pa=pv[i],pg=pe[i];
			edge &e=g[pa][pg];
			e.cap-=b;
			g[i][e.rev].cap+=b; 
			i=pa;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	addedge(4*n+1,4*n+2,2,0);
	int s=4*n+2,t=4*n+3;
	for(int i=1;i<=n;i++){
		addedge(s,i,1,0),addedge(i+n,t,1,0);
		addedge(i+n+n+n,i,INF,0);
		addedge(i,i+n,1,-1),addedge(i,i+n+n,INF,0);
		for(int j=i+1;j<=n;j++)if(b[i]+1==b[j]){
			addedge(i+n,j,INF,0);break;
		}
		for(int j=i+1;j<=n;j++)if(b[i]-1==b[j]){
			addedge(i+n,j,INF,0);break;
		}
		for(int j=i+1;j<=n;j++)if(b[i]==b[j]){
			addedge(i+n+n,j,INF,0);break;
		}
		for(int j=i+1;j<=n;j++)if(b[i]%7==b[j]%7){
			addedge(i+n+n+n,j+n+n+n,INF,0);addedge(i+n,j+n+n+n,INF,0);break;
		}
	}
	printf("%d",-MCMF(4*n+1,4*n+3).se);
}