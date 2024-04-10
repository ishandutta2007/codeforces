#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 105
#define ll long long 
#define mo 1000000007
using namespace std;


int n,m,i,j,k,x,y,tp;
int a[maxn][maxn][maxn],b[maxn][maxn],tk[maxn][maxn];
int A[maxn],B[maxn],C[maxn];
ll f[maxn][maxn][maxn][4],g[maxn][maxn][2],ans[maxn];

void Find(int X,int Y){
	int i,j,k=0;
	for(int t=1;t<tk[X][Y];t++) if (a[X][Y][t]==X&&a[X][Y][t+1]==Y) k++;
	if (k==1) for(int t=1;t<tk[X][Y];t++) if (a[X][Y][t]==X&&a[X][Y][t+1]==Y){
		A[0]=0; for(i=t;i>=1;i--) A[++A[0]]=a[X][Y][i];
		int bz=1;
		for(i=1;i<A[0];i++){
			x=A[i+1],y=A[i]; if (!b[x][y]) {bz=0;break;}
			for(j=tk[x][y];j>=1;j--){
				A[++A[0]]=a[x][y][j];
				if (A[0]>2*n+1) {bz=0;break;}
			} if (!bz) break;
		}
		if (!bz) continue;
		B[0]=0; for(i=t+1;i<=tk[X][Y];i++) B[++B[0]]=a[X][Y][i];
		for(i=1;i<B[0];i++){
			x=B[i],y=B[i+1]; if (!b[x][y]) {bz=0;break;}
			for(j=1;j<=tk[x][y];j++) {
				B[++B[0]]=a[x][y][j];
				if (B[0]>2*n+1) {bz=0;break;}
			} if (!bz) break;
		}
		if (!bz||A[0]+B[0]>2*n+1) continue;
//		if (!tp) {
//			tp=1,printf("%d\n",A[0]+B[0]);
//			for(i=A[0];i>=1;i--) printf("%d ",A[i]);
//			for(i=1;i<=B[0];i++) printf("%d ",B[i]);
//			printf("\n");
//		}
		f[A[A[0]]][B[B[0]]][A[0]+B[0]-1][0]++;
		g[A[0]+B[0]-1][B[B[0]]][1]++;
	}
	if (!tk[X][Y]) f[X][Y][1][3]++; else {
		if (a[X][Y][tk[X][Y]]==X){
			A[0]=0; for(i=tk[X][Y];i>=1;i--) A[++A[0]]=a[X][Y][i];
			int bz=1;
			for(i=1;i<A[0];i++){
				x=A[i+1],y=A[i]; if (!b[x][y]) {bz=0;break;}
				for(j=tk[x][y];j>=1;j--){
					A[++A[0]]=a[x][y][j];
					if (A[0]>2*n) {bz=0;break;}
				} if (!bz) break;
			}
			if (bz) 
				f[A[A[0]]][Y][A[0]][1]++,g[A[0]][Y][0]++;
		}
		if (a[X][Y][1]==Y){
			A[0]=0; for(i=1;i<=tk[X][Y];i++) A[++A[0]]=a[X][Y][i];
			int bz=1;
			for(i=1;i<A[0];i++){
				x=A[i],y=A[i+1]; if (!b[x][y]) {bz=0;break;}
				for(j=1;j<=tk[x][y];j++){
					A[++A[0]]=a[x][y][j];
					if (A[0]>2*n){bz=0;break;}
				} if (!bz) break;
			}
			if (bz) f[X][A[A[0]]][A[0]][2]++;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y),b[x][y]=1;
		scanf("%d",&tk[x][y]);
		for(j=1;j<=tk[x][y];j++) scanf("%d",&a[x][y][j]);
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if (b[i][j]) 
		Find(i,j);
//	if (!tp) printf("0\n\n");
	for(i=1;i<=2*n;i++) for(x=1;x<=n;x++) for(j=0;j<2;j++) if (g[i][x][j]){
		for(k=1;i+k<=2*n;k++) for(y=1;y<=n;y++){
			if (!j&&f[x][y][k][0]) 
				(g[i+k][y][1]+=g[i][x][j]*f[x][y][k][0])%=mo;
			if (!j&&f[x][y][k][1]) 
				(g[i+k][y][0]+=g[i][x][j]*f[x][y][k][1])%=mo;
			if (j&&f[x][y][k][2])  
				(g[i+k][y][1]+=g[i][x][j]*f[x][y][k][2])%=mo;
			if (j&&f[x][y][k][3])  
				(g[i+k][y][0]+=g[i][x][j]*f[x][y][k][3])%=mo;
		}
		if (j) ans[i]+=g[i][x][j];
	}
	for(i=1;i<=2*n;i++) printf("%lld\n",ans[i]%mo);
}