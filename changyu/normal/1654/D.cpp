#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+3,M=998244353;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
bool np[N];
int d[N],n,ans,a[N],f[N],mx[N];
struct edge{int v,x,y;};
std::vector<edge>g[N];
void Dfs0(int u,int fa){
	int v;
	for(int i=0;i<g[u].size();i++)if((v=g[u][i].v)!=fa){
		for(int j=g[u][i].x;j>1;j/=d[j])--f[d[j]];
		for(int j=g[u][i].y;j>1;j/=d[j])++f[d[j]],mx[d[j]]=std::max(mx[d[j]],f[d[j]]);
		Dfs0(v,u);
		for(int j=g[u][i].x;j>1;j/=d[j])++f[d[j]];
		for(int j=g[u][i].y;j>1;j/=d[j])--f[d[j]];
	}
}
void Dfs1(int u,int fa){
	int v;
	ans=(ans+a[u])%M;
	for(int i=0;i<g[u].size();i++)if((v=g[u][i].v)!=fa)a[v]=(ll)a[u]*g[u][i].x%M*Pow(g[u][i].y,M-2)%M,Dfs1(v,u);
}
signed main(){
	int u,v,x,y;
	for(int i=2;i<N;i++)if(!np[i]){
		d[i]=i;
		for(int j=i+i;j<N;j+=i)np[j]=1,d[j]=d[j]?d[j]:i;
	}
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear(),f[i]=mx[i]=0;
	for(int i=1;i<n;i++)scanf("%d%d%d%d",&u,&v,&x,&y),g[u].push_back((edge){v,y,x}),g[v].push_back((edge){u,x,y});
	Dfs0(1,0);
	a[1]=1;
	for(int i=1;i<=n;i++)if(mx[i]>0)a[1]=(ll)a[1]*Pow(i,mx[i])%M;
	ans=0;
	Dfs1(1,0);
	printf("%d\n",ans);
	}return 0;
}