#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 605
#define ll long long
using namespace std;

int n,m,i,j,k,a[maxn][maxn],vis[maxn];
ll dis[maxn],f[maxn];

void upd(int x){
	vis[x]=1; int D=dis[x]%n;
	for(i=1;i<=n;i++) if (a[x][i]) 
		f[(i+D-1)%n+1]=a[x][i]; 
	else f[(i+D-1)%n+1]=1e18;
	ll mi=1e18;
	for(i=1;i<=n;i++) mi=min(mi,f[i]-i+n);
	for(i=1;i<=n;i++){
		mi=min(mi,f[i]-i);
		if (!vis[i]) dis[i]=min(dis[i],dis[x]+mi+i);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		x++,y++,a[x][y]=z;
	}
	for(int st=1;st<=n;st++){
		memset(dis,127,sizeof(dis));
		memset(vis,0,sizeof(vis));
		vis[st]=1,dis[st]=0,upd(st);
		for(int now=1;now<n;now++){
			int p=0;
			for(i=1;i<=n;i++) if (!vis[i]&&(!p||dis[i]<dis[p])) p=i;
			upd(p);
		}
		for(i=1;i<=n;i++) printf("%lld ",dis[i]);
		printf("\n");
	}
}