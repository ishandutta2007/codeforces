#include<bits/stdc++.h>
using namespace std;

const int N=610;
int n,m,q;
struct edge{
	int x,y,c;
}s[N*N];
int f[N][N],g[N][N];

int main(){
	scanf("%d %d",&n,&m);
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&s[i].x,&s[i].y,&s[i].c);
		f[s[i].x][s[i].y]=f[s[i].y][s[i].x]=s[i].c;
	}
	int x,y,c;
	scanf("%d",&q);
	for(int i=1;i<=q;i++) scanf("%d %d %d",&x,&y,&c),g[x][y]=g[y][x]=c;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				g[i][k]=max(g[i][k],g[i][j]-f[k][j]);
				g[k][j]=max(g[k][j],g[i][j]-f[i][k]);
			}
	int ans=0;
	for(int i=1;i<=m;i++)
		if(s[i].c<=g[s[i].x][s[i].y]) ans++;
	printf("%d",ans);
}