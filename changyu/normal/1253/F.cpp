#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
typedef long long ll;
typedef std::pair<ll,int> P;
const ll INF=1e18;
const int N=1e5+3;
struct node{int v,c,nxt;}g[600003];
struct edge{int u,v;ll c;}e[300003];
struct query{int v,p;};
bool Cmp(const edge&a,const edge&b){return a.c<b.c;}
std::vector<int>b[N];
std::vector<query>qry[N];
int n,m,d,q,head[N],k,p[N];ll dis[N],ans[300003];
inline void Insert(int u,int v,int c){g[++k]=(node){v,c,head[u]};head[u]=k;}
void Sp(){
	int u,v;
	std::priority_queue<P,std::vector<P>,std::greater<P> >p;
	for(u=1;u<=n;u++)dis[u]=INF;
	for(u=1;u<=d;u++)p.push(P(dis[u]=0,u));
	for(;!p.empty();){
	  u=p.top().second;
	  if(p.top().first!=dis[u]){p.pop();continue;}
	  p.pop();
	  for(int i=head[u];i;i=g[i].nxt)if(dis[v=g[i].v]>dis[u]+g[i].c)
		p.push(P(dis[v]=dis[u]+g[i].c,v));
	}
}
int main(){
	int u,v,x,y,c;
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(;m--;)scanf("%d%d%d",&u,&v,&c),Insert(u,v,c),Insert(v,u,c);
	for(int j=1;j<=q;j++){
	  scanf("%d%d",&u,&v);
	  qry[u].push_back((query){v,j}),qry[v].push_back((query){u,j});
	}
	Sp();
	m=0;
	for(u=1;u<=n;u++)
	  for(int i=head[u];i;i=g[i].nxt)
		if((v=g[i].v)>u)e[++m]=(edge){u,v,g[i].c+dis[u]+dis[v]};
	std::sort(e+1,e+1+m,Cmp);
	for(u=1;u<=n;u++)p[u]=u,b[u].push_back(u);
	for(int i=1;i<=m;i++){
	  u=p[e[i].u],v=p[e[i].v];
	  if(u==v)continue;
	  if(b[u].size()>b[v].size())std::swap(u,v);
	  for(int j=0;j<b[u].size();j++){
		x=b[u][j];
		for(int k=0;k<qry[x].size();k++)
		  if(p[qry[x][k].v]==v)ans[qry[x][k].p]=e[i].c;
	  }
	  for(int j=0;j<b[u].size();j++){
		x=b[u][j];
		p[x]=v,b[v].push_back(x);
	  }
	}
	for(int j=1;j<=q;j++)printf("%lld\n",ans[j]);
	return 0;
}