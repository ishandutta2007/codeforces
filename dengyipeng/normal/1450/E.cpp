#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 205
#define maxm 2005
using namespace std;

int n,m,i,j,k,f[maxn][maxn],col[maxn],vis[maxn],ans,id;

void dfs(int x){
	vis[x]=1;
	for(int i=1;i<=n;i++) if (f[x][i]<=n){
		if (!vis[i]) col[i]=col[x]^1,dfs(i); else 
		if (col[i]==col[x]) 
			printf("NO\n"),exit(0);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(f,127,sizeof(f));
	for(i=1;i<=m;i++){
		int x,y; scanf("%d%d%d",&x,&y,&k);
		if (k) f[x][y]=1,f[y][x]=-1;
		else f[x][y]=f[y][x]=1;
	}
	memset(vis,0,sizeof(vis));
	dfs(1);
	for(i=1;i<=n;i++) f[i][i]=0;
	for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++)
		if (f[i][k]<=1e9&&f[k][j]<=1e9)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(i=1;i<=n;i++) if (f[i][i]<0) printf("NO\n"),exit(0);
	id=1;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if (abs(f[i][j])>ans)
		ans=abs(f[i][j]),id=i;
	printf("YES\n%d\n",ans);
	for(i=1;i<=n;i++) printf("%d ",n+f[id][i]);
}