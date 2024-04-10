#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1010][1010],f[1010][1010];
int getf(int x,int y){
	if (f[x][y]==x) return x;
	f[x][y]=getf(f[x][y],y);
	return f[x][y];
}
int dfs(int x,int y){
	x=getf(x,y);
	//printf("%d %d\n",x,y);
	if (x==n) return y;
	if (a[x][y]==1){
		a[x][y]=2;
		f[x][y]=f[x+1][y];
		return dfs(x,y+1);
	}
	else if (a[x][y]==3){
		a[x][y]=2;
		f[x][y]=f[x+1][y];
		return dfs(x,y-1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<=n;i++)
	for (int j=1;j<=m;j++) f[i][j]=i;
	for (int i=0;i<n;i++) 
	for (int j=1;j<=m;j++){
		scanf("%d",&a[i][j]);
		if (a[i][j]==2) f[i][j]=i+1;
	}
	for (int i=0;i<k;i++){
		int o;
		scanf("%d",&o);
		printf("%d ",dfs(0,o));
	}
}