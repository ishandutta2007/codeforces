#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
#define fi first
#define se second
#define mkp make_pair
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int INF=1e9;
struct edge{
	int to,rev,cap,cost;
	edge(int a,int b,int c,int d):to(a),rev(b),cap(c),cost(d){}
};
vector<edge>g[2005];
void addedge(int fr,int to,int cap,int cost){
	g[fr].push_back(edge(to,(int)g[to].size(),cap,cost));
	g[to].push_back(edge(fr,(int)g[fr].size()-1,0,-cost));
}
int n,K;
int dis[2005],h[2005];
int pe[2005],pv[2005],a[2005];
bool ins[2005];
pii MCMF(int s,int t){
	pii ret=mkp(0,0);
	while(1){
		queue<int>que;
		fill(dis,dis+2+2*n,INF);
		fill(ins,ins+2+2*n,0);
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
		for(int i=0;i<=2*n+1;i++)h[i]=min(h[i]+dis[i],INF);
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
piiii p[1003];
bool ans[1003];
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i].fi.fi,&p[i].fi.se,&p[i].se.fi),p[i].se.se=i;
	sort(p+1,p+1+n);
	addedge(0,1,K,0);
	for(int i=1;i<=n;i++){
		addedge(i,i+1,INF,0);
		addedge(i,i+n+1,1,-p[i].se.fi);
		int lb=lower_bound(p+1,p+1+n,mkp(mkp(p[i].fi.fi+p[i].fi.se,0),mkp(0,0)))-p;
		addedge(i+n+1,lb,INF,0);
	}
	MCMF(0,n+1);
	for(int i=1;i<=n;i++){
		bool ok=1;
		for(int j=0;j<g[i].size();j++)if(g[i][j].cap==0&&g[i][j].to==i+n+1){
			ok=0;
			ans[p[i].se.se]=1;
			break;
		}
		if(ok)ans[p[i].se.se]=0;
	}
	for(int i=1;i<=n;i++)putchar(ans[i]+'0'),putchar(' ');
}