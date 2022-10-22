#include<cstdio>
typedef long long ll;
const int M=1e9+7;
inline int Mod(int a){return a<M?a:a-M;}
inline int Inv(int a){int s=1,m=M-2;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
const int N=3003;
struct edge{int v,nxt;}g[N];
int n,d,head[N],k,f[N][N],c[N][N],ans,C;
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u){
	int v;
	for(int j=1;j<=n;j++)f[u][j]=1;
	for(int i=head[u];i;i=g[i].nxt){
	  v=g[i].v,Dfs(v);
	  for(int j=1;j<=n;j++)f[u][j]=(ll)f[u][j]*f[v][j]%M;
	}
	for(int j=1;j<=n;j++)f[u][j]=Mod(f[u][j]+f[u][j-1]);
}
int main(){
	int u,v;
	scanf("%d%d",&n,&d);
	for(v=2;v<=n;v++)scanf("%d",&u),Insert(u,v);
	Dfs(1);
	if(d<=n)return 0*printf("%d",f[1][d]);
	for(int i=0;i<=n;i++){
	  c[i][0]=1;
	  for(int j=1;j<=i;j++)c[i][j]=Mod(c[i-1][j-1]+c[i-1][j]);
	}
	C=1;
	for(int j=1;j<=n;j++){
	  for(int k=1;k<j;k++)
		f[1][j]=Mod(f[1][j]-(ll)c[j][k]*f[1][k]%M+M);
	  C=(ll)C*Inv(j)%M*(d-j+1)%M;
	  ans=(ans+(ll)f[1][j]*C)%M;
	}
	printf("%d",ans);
	return 0;
}