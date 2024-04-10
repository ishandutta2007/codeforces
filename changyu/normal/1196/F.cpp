#include<cstdio>
#include<algorithm>
const int N=2e5+3,K=403;const long long INF=1e18;
struct edge{int u,v,c;}e[N];
bool Cmp(const edge&e1,const edge&e2){return e1.c<e2.c;}
int p[N],t,c,n,m,k;long long d[K+K][K+K],ans[(K+K)*(K+K)];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int j=1;j<=m;j++)
	  scanf("%d%d%d",&e[j].u,&e[j].v,&e[j].c);
	std::sort(e+1,e+1+m,Cmp);
	for(int i=1;i<K+K;i++)
	  for(int j=1;j<K+K;j++)
		d[i][j]=INF;
	for(int j=1;j<=k&&j<=m;j++){
	  p[e[j].u]=p[e[j].u]?p[e[j].u]:++t;
	  p[e[j].v]=p[e[j].v]?p[e[j].v]:++t;
	  d[p[e[j].u]][p[e[j].v]]=d[p[e[j].v]][p[e[j].u]]=std::min((long long)e[j].c,d[p[e[j].u]][p[e[j].v]]);
	}
	for(int l=1;l<=t;l++)
	  for(int i=1;i<=t;i++)
		for(int j=1;j<=t;j++)
		  d[i][j]=std::min(d[i][l]+d[l][j],d[i][j]);
	for(int i=1;i<=t;i++)
	  for(int j=i+1;j<=t;j++)
		ans[++c]=d[i][j];
	std::sort(ans+1,ans+c+1);
	printf("%lld",ans[k]);
	return 0;
}