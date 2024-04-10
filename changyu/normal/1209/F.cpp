#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
const int V=1e6,M=1e9+7;
struct edge{int v,c,nxt;}g[V];
int n,m,k,t,dep[V],q[V],l,r,d[7],head[V],dis[V],a1[V],a2[V],a3[V];
std::vector<int>h[V];
inline void Insert(int u,int v,int c){g[++k]=(edge){v,c,head[u]};head[u]=k;}
bool Cmp(const int&u,const int&v){return a1[u]==a1[v]?a2[u]<a2[v]:a1[u]<a1[v];}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	t=n;
	for(int j=1;j<=m;j++){
	  scanf("%d%d",&u,&v);
	  r=0;
	  for(int jj=j;jj;jj/=10)d[++r]=jj%10;
	  if(r==1)Insert(u,v,d[1]),Insert(v,u,d[1]);
	  else{
	  	Insert(u,++t,d[r]);
		for(int jj=r-1;jj>=2;jj--)
		  Insert(t,t+1,d[jj]),++t;
		Insert(t,v,d[1]);
		Insert(v,++t,d[r]);
		for(int jj=r-1;jj>=2;jj--)
		  Insert(t,t+1,d[jj]),++t;
		Insert(t,u,d[1]);
	  }
	}
	q[l=r=0]=1;dep[1]=1;
	for(;l<=r;){
	  u=q[l++];
	  h[dep[u]].push_back(u);
	  for(int i=head[u];i;i=g[i].nxt)if(!dep[v=g[i].v])
		q[++r]=v,dep[v]=dep[u]+1;
	}
	dis[1]=0;
	memset(a1,1,sizeof a1);memset(a2,1,sizeof a2);
	for(int j=1;h[j].size();j++){
	  std::sort(h[j].begin(),h[j].end(),Cmp);
	  r=0;
	  for(int i=0;i<h[j].size();i++){
		u=h[j][i];
		if(!i||a1[u]!=a1[h[j][i-1]]||a2[u]!=a2[h[j][i-1]])++r;
		a3[u]=r;
		for(int i=head[u];i;i=g[i].nxt)
		  if(dep[v=g[i].v]>dep[u]&&(a3[u]<a1[v]||a3[u]==a1[v]&&g[i].c<a2[v]))
			a1[v]=a3[u],a2[v]=g[i].c,dis[v]=(dis[u]*10ll+g[i].c)%M;
	  }
	}
	for(u=2;u<=n;u++)printf("%d\n",dis[u]);
	return 0;
}