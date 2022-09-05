#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
#define eef(i,x)for(int i=head[x],y=e[i].to;y;i=e[i].next,y=e[i].to)
int read(){char c=getchar();int d=0,f=1;for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());return d*f;}
char Read(){char c=getchar();while(c<'0'||c>'9')c=getchar();return c;}
typedef pair<int,int>PII;
typedef long long LL;
const int N=1000001;
int n,m,q;
int cnt,Cnt,head[N];struct edge{int to,next;}e[N*8];
void addedge(int x,int y){e[++cnt]=(edge){y,head[x]};head[x]=cnt;}
void Addedge(int x,int y){addedge(x,y);addedge(y,x);}
int tot,dfn[N],low[N],top,stk[N],bel[N],val[N];bool instk[N];
void dfs(int f,int x){
	low[x]=dfn[x]=++tot;
	eef(i,x) if (!dfn[y]) {
		stk[++top]=i>>1; dfs(x,y);
		low[x]=min(low[x],low[y]);
		if (low[y]>=dfn[x]) {
			Cnt++; val[Cnt]=x;
			while (top) {
				int edge=stk[top--];
				bel[edge]=Cnt; if (edge==(i>>1)) break;
			}
		}
	} else if (dfn[y]<dfn[x]&&y!=f) {
		stk[++top]=i>>1;
		low[x]=min(low[x],dfn[y]); 
	}
}
int dep[N],F[N][20];
void DFS(int f,int x){
	dep[x]=dep[f]+1;F[x][0]=f;
	ref(i,1,19)if(F[x][i-1]&&F[F[x][i-1]][i-1])
		F[x][i]=F[F[x][i-1]][i-1];
	eef(i,x)if(y!=f&&(i>>1)>m)
		DFS(x,y);
}
int lca(int x,int y){
 	if(dep[x]<dep[y])swap(x,y);
 	def(i,19,0)if(F[x][i]&&dep[F[x][i]]>=dep[y])x=F[x][i];
 	if(x==y)return x;
 	def(i,19,0)if(F[x][i]&&F[y][i]&&F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
 	return F[x][0];
}
int main(){
	n=read();m=read(),q=read();
	cnt=1; ref(i,1,m)Addedge(read(),read());
	Cnt=n; dfs(0,1);
	ref(i,n+1,Cnt)Addedge(i,val[i]);
	ref(i,1,m){
		if(e[i<<1].to==val[bel[i]])
			Addedge(bel[i],e[i<<1|1].to);
		if(e[i<<1|1].to==val[bel[i]])
			Addedge(bel[i],e[i<<1].to);
	}
	DFS(0,1);
	ref(i,1,q){
		int x=read(),y=read(),L=lca(x,y);
		int ans=dep[x]+dep[y]-dep[L]-dep[L];
		ans/=2;
		printf("%d\n",ans);
	}
}