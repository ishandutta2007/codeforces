#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 605
#define ll long long
using namespace std;

int n,m,q,i,j,k,bz[maxn][maxn];
ll f[maxn][maxn],s[maxn][maxn],g[maxn],a[maxn][maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) f[i][j]=1e18;
	for(i=1;i<=n;i++) f[i][i]=0;
	for(i=1;i<=m;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		a[x][y]=a[y][x]=z;
		f[x][y]=min(f[x][y],(ll)z);
		f[y][x]=min(f[y][x],(ll)z);
	}
	for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	memset(s,128,sizeof(s));
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		s[x][y]=max(s[x][y],(ll)z);
		s[y][x]=max(s[y][x],(ll)z);
	}
	for(int x=1;x<=n;x++){
		memset(g,128,sizeof(g));
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) if (s[i][j]>=0)
			g[j]=max(g[j],s[i][j]-f[x][i]);
		for(i=1;i<=n;i++) if (g[i]>=0) for(int y=1;y<=n;y++) 
			if (a[x][y]+f[y][i]<=g[i]&&a[x][y])
				bz[x][y]=1;
	}
	int ans=0;
	for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) if (bz[i][j]||bz[j][i])
		ans++;
	printf("%d\n",ans);
}