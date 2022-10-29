#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
#define maxn 105
using namespace std;

int T,n,m,i,j,k,b[maxn][maxn],v[maxn][maxn],bz[maxn][maxn],now[maxn];
struct arr{int x,i,j;} a[maxn*maxn];
int cmp(arr a,arr b){return a.x<b.x;}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		int tot=0;
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) {
			scanf("%d",&b[i][j]);
			tot++,a[tot].x=b[i][j],a[tot].i=i,a[tot].j=j;
		}
		sort(a+1,a+1+tot,cmp);
		for(i=1;i<=m;i++) for(j=1;j<=n;j++) v[i][j]=0,bz[j][i]=0;
		for(k=1;k<=m;k++){
			v[k][a[k].i]=a[k].j;
			bz[a[k].i][a[k].j]=1;
		}
		for(i=1;i<=n;i++) now[i]=1;
		for(k=1;k<=m;k++){
			for(i=1;i<=n;i++) if (!v[k][i]){
				while (bz[i][now[i]]) now[i]++;
				v[k][i]=now[i],bz[i][now[i]]=1;
			}
		}
		for(i=1;i<=n;i++,printf("\n"))
			for(j=1;j<=m;j++) printf("%d ",b[i][v[j][i]]);
	}
}