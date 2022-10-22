#include<cstdio>
#include<vector>
#include<algorithm>
const int N=5e5+3;
struct edge{int v,nxt;}g[N+N];
int n,head[N],k,h[N][2],fu[N],fd[N],p[N],ans[2][N];
struct node{int a,b;};
std::vector<int>bb[N];
std::vector<node>b[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs0(int u,int fa){
	int v;
	h[u][0]=h[u][1]=0;
	bb[u].push_back(0);
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa){
	  Dfs0(v,u);
	  if(h[v][0]+1>h[u][0])h[u][1]=h[u][0],h[u][0]=h[v][0]+1,p[u]=v;
	  else if(h[v][0]+1>h[u][1])h[u][1]=h[v][0]+1;
	  bb[u].push_back(h[v][0]+1);
	}
}
void Dfs1(int u,int fa){
	int v,tmp;node psh;
	std::sort(bb[u].begin(),bb[u].end());
	for(int i=0,j=0;i<bb[u].size();i++)if(i==bb[u].size()-1||bb[u][i+1]!=bb[u][i]){
	  psh=(node){bb[u][i],0};
	  for(;j<=i;j++)++psh.b;
	  b[u].push_back(psh);
	}
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa){
	  tmp=h[u][v==p[u]]+1;
	  fu[v]=tmp,fd[v]=h[v][0]+1;
	  if(tmp>h[v][0])h[v][0]=tmp,p[v]=u;
	  else if(tmp>h[v][1])h[v][1]=tmp;
	  bb[v].push_back(tmp);
	  Dfs1(v,u);
	}
}
int main(){
	int u,v,c;
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	Dfs0(1,0);
	Dfs1(1,0);
	for(u=1;u<=n;u++){
	  c=0;
	  for(int i=b[u].size()-1;~i;i--){
		ans[1][b[u][i].a]=std::max(ans[1][b[u][i].a],c+1);
		c+=b[u][i].b;
		if(b[u][i].a)ans[1][b[u][i].a-1]=std::max(ans[1][b[u][i].a-1],c);
		ans[0][b[u][i].a]=std::max(ans[0][b[u][i].a],c);
	  }
	  for(int i=head[u];i;i=g[i].nxt)if(u==1||g[i].v!=1&&fd[g[i].v]<fd[u]){
		v=g[i].v;
		b[0].clear();
		for(int i=0,j=0;i<b[u].size()||j<b[v].size();){
		  if(i<b[u].size()&&j<b[v].size()&&b[u][i].a==b[v][j].a)
			b[0].push_back((node){b[u][i].a,b[u][i].b+b[v][j].b}),i++,j++;
		  else if(i<b[u].size()&&(j==b[v].size()||b[u][i].a<b[v][j].a))
			b[0].push_back(b[u][i]),i++;
		  else if(j<b[v].size()&&(i==b[u].size()||b[u][i].a>b[v][j].a))
			b[0].push_back(b[v][j]),j++;
		}
		c=0;
		for(int i=b[0].size()-1;~i;i--){
		  if(b[0][i].a==fu[v])--b[0][i].b;
		  if(b[0][i].a==fd[v])--b[0][i].b;
		  c+=b[0][i].b;
		  ans[0][b[0][i].a]=std::max(ans[0][b[0][i].a],c);
		}
	  }
	}
	ans[0][n]=ans[1][n]=1;
	for(int i=n-1;i;i--){
	  ans[0][i]=std::max(ans[0][i],ans[0][i+1]);
	  ans[1][i]=std::max(ans[1][i],ans[1][i+1]);
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i&1][i>>1]);
	return 0;
}