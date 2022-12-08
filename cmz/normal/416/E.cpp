#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+10;
const int INF=1e9;
int f[maxn][maxn],g[maxn][maxn],Ans[maxn][maxn],cur[maxn];
int n,m; 
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) f[i][j]=g[i][j]=INF;
	for (int i=1;i<=n;++i) f[i][i]=0;
	for (int i=1,x,y,z;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=f[y][x]=g[x][y]=g[y][x]=min(f[x][y],z);
	}
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j) cur[j]=0;
		
		for (int j=1;j<=n;++j)
			for (int k=1;k<=n;++k) if (f[i][k]+g[k][j]==f[i][j]) ++cur[j];
			
		for (int j=1;j<=n;++j)
			for (int k=1;k<=n;++k) if (f[i][k]+f[k][j]==f[i][j]) Ans[i][j]+=cur[k];
	}
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j) if (f[i][j]==INF) printf("0 "); else printf("%d ",Ans[i][j]);
	return 0;
}