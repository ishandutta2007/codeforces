#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 505
#define maxk 12
using namespace std;

const int fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,c,i,j,k,a[maxn][maxn],b[maxn][maxn],f[2][maxn][maxn];

int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(i=1;i<=n;i++) for(j=1;j<m;j++) scanf("%d",&a[i][j]);
	for(i=1;i<n;i++) for(j=1;j<=m;j++) scanf("%d",&b[i][j]);
	if (c&1){
		for(i=1;i<=n;i++,printf("\n")) for(j=1;j<=m;j++) printf("-1 ");
		return 0;
	}
	c/=2;
	for(int t=1;t<=c;t++){
		int p=t&1,q=t&1^1;
		memset(f[p],127,sizeof(f[p]));
		for(i=1;i<=n;i++) for(j=1;j<=m;j++)
			for(k=0;k<4;k++){
				int x=i+fx[k][0],y=j+fx[k][1];
				if (x>=1&&x<=n&&y>=1&&y<=m)
					f[p][i][j]=min(f[p][i][j],f[q][x][y]+((k<2)?b[i-(k==1)][j]:a[i][j-(k==3)]));
			}
	}
	for(i=1;i<=n;i++,printf("\n")) for(j=1;j<=m;j++) 
		printf("%d ",f[c&1][i][j]*2);
}