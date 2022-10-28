#include<cstdio>
#define g f[x][y]
short f[1001][1001][10][10],log[1001];
short min(short x,short y){return x<y?x:y;}
short max(short x,short y){return x>y?x:y;}
int main(){
	int n,m,t,x1,y1,x2,y2,N;scanf("%d%d",&n,&m);N=n>m?n:m;
	for(int x=0;x<n;x++)for(int y=0;y<m;y++)scanf("%d",&t),**f[x][y]=t;
	for(int i=2;i<=N;i++)log[i]=log[i/2]+1;
	for(int x=n;x--;)for(int y=m;y--;){
		if(**g)**g=1+min(min(**f[x][y+1],**f[x+1][y]),**f[x+1][y+1]);
		for(int i=0;i<=log[n];i++)for(int j=0;j<=log[m];j++)g[i][j]=j?max(g[i][j-1],y+(1<<j-1)<m?f[x][y+(1<<j-1)][i][j-1]:0):i?max(g[i-1][j],x+(1<<i-1)<n?f[x+(1<<i-1)][y][i-1][j]:0):g[i][j];
	}
	for(scanf("%d",&t);t--;){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);x1--;y1--;
		int L=0,R=min(x2-x1,y2-y1)+1,M,i,j;
		while(R-L>1)M=L+R>>1,i=log[x2-x1-M+1],j=log[y2-y1-M+1],max(max(f[x1][y1][i][j],f[x1][y2-M+1-(1<<j)][i][j]),max(f[x2-M+1-(1<<i)][y1][i][j],f[x2-M+1-(1<<i)][y2-M+1-(1<<j)][i][j]))<M?R=M:L=M;
		printf("%d\n",L);
	}
}