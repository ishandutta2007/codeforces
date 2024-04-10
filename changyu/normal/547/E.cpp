#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=2e5+3,Q=5e5+3;
struct edge{int v,nxt;}g[N];
int n,m,son[N][26],e[N][26],t,p[N],q[N],l,r,fail[N],head[N],k,dfn[N],dfc,siz[N],fa[N];char s[N];
ll ans[Q],bt[N];
struct query{int k,r,p;}qry[Q+Q];
bool Cmp(const query&a,const query&b){return a.r<b.r;}
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u){
	int v;
	dfn[u]=dfc++,siz[u]=1;
	for(int i=head[u];i;i=g[i].nxt)
	  v=g[i].v,Dfs(v),siz[u]+=siz[v];
}
inline void Add(int k){for(;k&&k<=t;k+=k&-k)++bt[k];}
inline ll Sum(int k){ll s=0;for(;k;k-=k&-k)s+=bt[k];return s;}
signed main(){
	int k,x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
	  scanf("%s",s);
	  k=0;
	  for(int j=0,c;s[j];j++){
		c=s[j]-'a';
		if(!son[k][c]){
		  e[k][c]=son[k][c]=++t;
		  fa[t]=k;
		}
		k=son[k][c];
	  }p[i]=k;
	}
	l=0,r=-1;
	for(int c=0;c<26;c++)
	  if(e[0][c])
		fail[e[0][c]]=0,q[++r]=e[0][c];
	for(;l<=r;){
	  k=q[l++];
	  Insert(fail[k],k);
	  for(int c=0;c<26;c++)
		if(e[k][c])
		  fail[e[k][c]]=e[fail[k]][c],q[++r]=e[k][c];
		else e[k][c]=e[fail[k]][c];
	}
	Dfs(0);
	for(int j=1;j<=m;j++){
	  scanf("%d%d%d",&x,&y,&z);
	  qry[j]=(query){p[z],y,j};
	  qry[j+m]=(query){p[z],x-1,-j};
	}
	std::sort(qry+1,qry+1+m+m,Cmp);
	for(int j=1,i=1;j<=m+m;j++){
	  for(;i<=qry[j].r;i++)
		for(k=p[i];k;k=fa[k])Add(dfn[k]);
	  x=1;
	  if(qry[j].p<0)x=-1,qry[j].p=-qry[j].p;
	  ans[qry[j].p]+=x*(Sum(dfn[qry[j].k]+siz[qry[j].k]-1)-Sum(dfn[qry[j].k]-1));
	}
	for(int j=1;j<=m;j++)printf("%lld\n",ans[j]);
	return 0;
}