#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e6+50,M=810;
int n,m,k,id[N],cnt,iid[N],ver[N*2],edge[N*2],nxt[N*2],head[N],tot,q,lim;bool flag[N];LL dis[M][M],d[N];
struct node{int x,y,z;bool friend operator <(node a,node b){return a.z<b.z;}}E[N];
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;
	ver[++tot]=x;edge[tot]=z;nxt[tot]=head[y];head[y]=tot;
}
void dfs(int x){
	flag[x]=0;iid[id[x]=++cnt]=x;dis[cnt][cnt]=0;
	for(int i=head[x],y;i;i=nxt[i])if(flag[y=ver[i]]&&edge[i]<=lim)dfs(y);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].z),add(E[i].x,E[i].y,E[i].z);
	sort(E+1,E+m+1);memset(dis,0x3f,sizeof(dis));lim=E[min(k,m)].z;
	for(int i=1;i<=min(k,m);i++)flag[E[i].x]=flag[E[i].y]=1;
	for(int i=1;i<=n;i++)if(flag[i]){
		cnt=0;dfs(i);
		for(int x=1;x<=cnt;x++)for(int j=head[iid[x]],y;j;j=nxt[j])if(iid[y=id[ver[j]]]==ver[j])dis[x][y]=dis[y][x]=edge[j];
		for(int k=1;k<=cnt;k++)
			for(int i=1;i<=cnt;i++)
				for(int j=1;j<=cnt;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int i=1;i<cnt;i++)for(int j=i+1;j<=cnt;j++)d[++q]=dis[i][j];
		for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++)dis[i][j]=1e18;
	}
	sort(d+1,d+q+1);printf("%lld\n",d[k]);
	return 0;
}