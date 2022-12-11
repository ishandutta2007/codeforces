#include<bits/stdc++.h>
using namespace std;
const int N=110,M=1010;
int n,m,d[N][N],s,b,k,h,ver[M*M],nxt[M*M],head[M],tot,pre[M*2],vis[M*2],ti,ans;
struct node{int p,a,f;}a[M];
struct node1{int p,a;}c[M];
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
bool dfs(int x){
	for(int i=head[x],y;i;i=nxt[i]){
		if(vis[y=ver[i]]==ti)continue;
		vis[y]=ti;
		if(!pre[y]||dfs(pre[y])){
			pre[y]=x;return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		d[x][y]=d[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	scanf("%d%d%d%d",&s,&b,&k,&h);
	for(int i=1;i<=s;i++)scanf("%d%d%d",&a[i].p,&a[i].a,&a[i].f);
	for(int i=1;i<=b;i++)scanf("%d%d",&c[i].p,&c[i].a);
	for(int i=1;i<=s;i++)for(int j=1;j<=b;j++)
		if(c[j].a<=a[i].a&&d[a[i].p][c[j].p]<=a[i].f)add(i,j);
	for(ti=1;ti<=s;ti++)if(dfs(ti))ans++;
	cout<<(1ll*s*h<1ll*ans*k?1ll*s*h:1ll*ans*k);
	return 0;
}