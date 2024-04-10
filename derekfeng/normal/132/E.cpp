#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int inf=1e9,M=130000;
const ll INF=1e18;
struct edge{
	int to,rev,cap,cost;
	edge(int a,int b,int c,int d):to(a),rev(b),cap(c),cost(d){}
};
vector<edge>g[M];
void addedge(int fr,int to,int cap,int cost){
	g[fr].push_back(edge(to,(int)g[to].size(),cap,cost));
	g[to].push_back(edge(fr,(int)g[fr].size()-1,0,-cost));
}
ll dis[M],h[M];
int pe[M],pv[M],a[M],N=3;
pii MCMF(int s,int t){
	pii ret={0,0};
	while(1){
		priority_queue<pii,vector<pii>,greater<pii> >pq;
		fill(dis+1,dis+N+1,INF);
		dis[s]=0,pq.push({0,s}),a[s]=inf;
		while(!pq.empty()){
			auto [w,x]=pq.top();pq.pop();
			if(x==t)break;
			if(dis[x]<w)continue;
			for(int i=0;i<g[x].size();i++){
				edge e=g[x][i];
				ll w1=w+e.cost+h[x]-h[e.to];
				if(e.cap>0&&dis[e.to]>w1){
					dis[e.to]=w1;
					pe[e.to]=i,pv[e.to]=x;
					a[e.to]=min(e.cap,a[x]);
					pq.push({w1,e.to});
				}
			}
		}
		if(dis[t]==INF)return ret;
		for(int i=1;i<=N;i++)h[i]=min(h[i]+dis[i],INF);
		int b=a[t];	
		ret.second+=b,ret.first+=h[t]*b;
		for(int i=t;i!=s;){
			int pa=pv[i],pg=pe[i];
			edge &e=g[pa][pg];
			e.cap-=b;
			g[i][e.rev].cap+=b; 
			i=pa;
		}
	}
}
int n,z,m,S=1,D=3,T=2,v[255],t[255];
int id[2][255][255];
vector<int>all;
vector<pii>opt;
int cur[30];
int main(){
	scanf("%d%d",&n,&z);all.push_back(-1e9);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]),all.push_back(v[i]);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=n;i++)t[i]=lower_bound(all.begin(),all.end(),v[i])-all.begin()+1;
	m=all.size();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)id[0][i][j]=++N,id[1][i][j]=++N;
	addedge(S,D,z,0);
	addedge(D,id[0][1][1],inf,0),addedge(D,id[0][1][t[1]],1,__builtin_popcount(v[1]));
	for(int i=1;i<=n;i++){
		if(i>1){
			for(int j=1;j<=m;j++)addedge(id[1][i-1][j],id[0][i][j],inf,0);
			for(int j=1;j<=m;j++)addedge(id[1][i-1][j],id[0][i][t[i]],1,__builtin_popcount(v[i]));
		}
		for(int j=1;j<=m;j++){
			addedge(id[0][i][j],id[1][i][j],inf,inf);
			if(j==t[i])addedge(id[0][i][j],id[1][i][j],1,0);
		}
	}
	for(int i=1;i<=m;i++)addedge(id[1][n][i],T,inf,0);
	pii ret=MCMF(S,T);
	ret.first-=(ll)inf*n*(z-1);
	for(int i=0;i<z;i++)cur[i]=1;
	for(int i=1;i<=n;i++){
		if(i==1){
			cur[0]=t[1];
			opt.push_back({all[t[i]-1],0});
		}else{
			for(int j=1;j<=m;j++)if(j!=t[i])
				for(auto e:g[id[1][i-1][j]])
					if(e.cap==0&&e.to==id[0][i][t[i]]){
						for(int k=0;k<z;k++)if(cur[k]==j){
							cur[k]=t[i];
							opt.push_back({all[t[i]-1],k});
							break;
						}
					}
		}
		for(int j=0;j<z;j++)
			if(cur[j]==t[i]){
				opt.push_back({-1,j});
				break;
			}
	}
	printf("%d %lld\n",opt.size(),ret.first);
	for(auto [p,c]:opt){
		if(p<0)printf("print(%c)\n",(char)c+'a');
		else printf("%c=%d\n",(char)c+'a',p);
	}
}