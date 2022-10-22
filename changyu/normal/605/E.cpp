#include<cstdio>
#include<algorithm>
const double INF=1e8;
const int N=1003;
int n,g[N][N],used[N];double d[N],t[N];
int main(){
	int u,v;
	scanf("%d",&n);
	for(u=1;u<=n;u++)for(v=1;v<=n;v++)
	  scanf("%d",&g[u][v]);
	for(u=1;u<=n;u++)d[u]=INF;
	d[n]=0;
	for(int j=1;j<=n;j++){
	  u=0;
	  for(v=1;v<=n;v++)if(!used[v]&&d[v]<INF-1&&(!u||d[v]*(1-t[u])<d[u]*(1-t[v])))u=v;
	  used[u]=1;
	  d[u]/=1-t[u];
	  for(v=1;v<=n;v++)if(g[v][u]&&!used[v])
		if(d[v]==INF){
		  d[v]=1+d[u]*(g[v][u]/100.0);
		  t[v]=1-g[v][u]/100.0;
		}
		else{
		  d[v]+=d[u]*(g[v][u]/100.0)*t[v];
		  t[v]*=1-g[v][u]/100.0;
		}
	}printf("%.12lf\n",d[1]);
	return 0;
}