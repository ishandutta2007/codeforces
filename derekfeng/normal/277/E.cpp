#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef pair<db,int> pdi;
#define fi first
#define se second
#define mkp make_pair
const db INF=1e9;
struct edge{
	int to,rev,cap;
	db cost;
	edge(int a,int b,int c,db d):to(a),rev(b),cap(c),cost(d){}
};
vector<edge>g[803];
void addedge(int fr,int to,int cap,db cost){
	g[fr].push_back(edge(to,(int)g[to].size(),cap,cost));
	g[to].push_back(edge(fr,(int)g[fr].size()-1,0,-cost));
}
db dis[803],h[803];
int pe[803],pv[803],a[803];
int ans1;db ans2;
void MCMF(int s,int t,int n){
	while(1){
		priority_queue<pdi,vector<pdi>,greater<pdi> >pq;
		fill(dis,dis+1+n,INF);
		dis[s]=0,pq.push(mkp(0,s)),a[s]=INF;
		while(!pq.empty()){
			pdi u=pq.top();pq.pop();
			db w=u.fi;int x=u.se;
			if(x==t)break;
			if(dis[x]<w)continue;
			for(int i=0;i<g[x].size();i++){
				edge e=g[x][i];
				db w1=w+e.cost+h[x]-h[e.to];
				if(e.cap>0&&dis[e.to]>w1){
					dis[e.to]=w1;
					pe[e.to]=i;
					pv[e.to]=x;
					a[e.to]=min(e.cap,a[x]);
					pq.push(mkp(w1,e.to));
				}
			}
		}
		if(dis[t]==INF)return;
		for(int i=1;i<=n;i++)h[i]=min(h[i]+dis[i],INF);
		int b=a[t];	
		ans1+=b,ans2+=b*h[t];
		for(int i=t;i!=s;){
			int pa=pv[i],pg=pe[i];
			edge &e=g[pa][pg];
			e.cap-=b;
			g[i][e.rev].cap+=b; 
			i=pa;
		}
	}
}
int n,x[803],y[803];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]),addedge(0,i,2,0),addedge(i+n,2*n+1,1,0);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(y[i]>y[j])addedge(i,j+n,1,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
	MCMF(0,2*n+1,2*n+1);
	if(ans1!=n-1){
		puts("-1");return 0;
	}
	printf("%.6lf",ans2);
}