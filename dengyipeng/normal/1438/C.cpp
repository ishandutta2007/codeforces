#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 105
using namespace std;

const int fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int T,n,m,i,j,k,a[maxn][maxn],tot,b[maxn][maxn],bz[maxn][maxn],d[maxn*maxn][2],t,w;
struct arr{int i,j;} p[maxn*maxn];
int cmp(arr x,arr y){return a[x.i][x.j]<a[y.i][y.j];}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
		memcpy(b,a,sizeof(b));
		tot=0;for(i=1;i<=n;i++) for(j=1;j<=m;j++) tot++,p[tot].i=i,p[tot].j=j;
		sort(p+1,p+1+tot,cmp);
		memset(bz,0,sizeof(bz));
		for(int now=1;now<=tot;now++) if (!bz[p[now].i][p[now].j]){
			t=0,w=1,d[1][0]=p[now].i,d[1][1]=p[now].j;
			bz[d[1][0]][d[1][1]]=1;
			while (t<w){
				t++; int x=d[t][0],y=d[t][1];
				for(k=0;k<4;k++){
					int xx=x+fx[k][0],yy=y+fx[k][1];
					if (xx>=1&&xx<=n&&yy>=1&&yy<=m) {
						if (!bz[xx][yy]){
							if (a[xx][yy]==a[x][y]||a[xx][yy]==a[x][y]-1){
								if (a[xx][yy]==a[x][y]) a[xx][yy]++;
								bz[xx][yy]=1;
								w++,d[w][0]=xx,d[w][1]=yy;
							}
						}
					}
				}
			}
		}
//		for(i=1;i<=n;i++) for(j=1;j<=n;j++) if (b[i][j]-a[i][j]>1)
//			printf("!");
		for(i=1;i<=n;i++,printf("\n")) for(j=1;j<=m;j++) printf("%d ",a[i][j]);
	}
}