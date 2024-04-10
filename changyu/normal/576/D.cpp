#include<algorithm>
#include<bitset>
#include<cstdio>
const int N=151,INF=0x3f3f3f3f;
struct edge{int u,v,c;}e[N];
bool Cmp(const edge&a,const edge&b){return a.c<b.c;}
int n,m,ans,q[N],l,r,d[N];
struct matrix{std::bitset<N>a[N],b[N];}g,f,t,one,t0;
inline void Mult(matrix&c,matrix a,matrix b){
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
		c.a[i][j]=(a.a[i]&b.b[j]).count()>0,
		c.b[i][j]=(a.a[j]&b.b[i]).count()>0;
}
inline void Pow(matrix&c,matrix a,int m){
	c=one,t0=a;
	for(;m;m>>=1)m&1?Mult(c,c,t0):(void)0,Mult(t0,t0,t0);
}
inline int Calc(const matrix&f,const matrix&g){
	int u,v;
	l=0,r=-1;
	for(u=1;u<=n;u++)
	  if(f.a[1][u])d[u]=0,q[++r]=u;
	  else d[u]=INF;
	for(;l<=r;){
	  u=q[l++];
	  for(v=1;v<=n;v++)if(g.a[u][v]&&d[v]==INF)
		d[v]=d[u]+1,q[++r]=v;
	}return d[n];
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
	std::sort(e+1,e+1+m,Cmp);
	for(int i=1;i<=n;i++)one.a[i][i]=one.b[i][i]=1;
	f=one;
	ans=INF;
	for(int i=1;i<=m;i++){
	  Pow(t,g,e[i].c-e[i-1].c);
	  Mult(f,f,t);
	  u=e[i].u,v=e[i].v;
	  g.a[u][v]=g.b[v][u]=1;
	  ans=std::min(ans,e[i].c+Calc(f,g));
	}
	ans==INF?puts("Impossible"):printf("%d\n",ans);
	return 0;
}