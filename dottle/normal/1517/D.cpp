#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<algorithm>
#include<queue>
using namespace std;

inline void MIN(int &a,const int &b) {if(b<a) a=b;}

const int N=505,K=21;

int f[K][N][N];
int a[N][N],b[N][N];
int n,m,k;

int main() {
	scanf("%d%d%d",&n,&m,&k);
	if(k&1) {
		for(int i=1 ; i<=n ; ++i,puts(""))
			for(int j=1 ; j<=m ; ++j)
				printf("-1 ");
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j)
			f[0][i][j]=0;
	for(int i=1 ; i<=n ; ++i)
		for(int j=2 ; j<=m ; ++j)
			scanf("%d",&a[i][j]);
	for(int i=2 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j)
			scanf("%d",&b[i][j]);
	k>>=1;
	for(int l=1 ; l<=k ; ++l)
		for(int i=1 ; i<=n ; ++i)
			for(int j=1 ; j<=m ; ++j) {
				if(i>1) MIN(f[l][i][j],f[l-1][i-1][j]+b[i][j]*2),MIN(f[l][i][j],b[i][j]*l*2);
				if(j>1) MIN(f[l][i][j],f[l-1][i][j-1]+a[i][j]*2),MIN(f[l][i][j],a[i][j]*l*2);
				if(i<n) MIN(f[l][i][j],f[l-1][i+1][j]+b[i+1][j]*2),MIN(f[l][i][j],b[i+1][j]*l*2);
				if(j<m) MIN(f[l][i][j],f[l-1][i][j+1]+a[i][j+1]*2),MIN(f[l][i][j],a[i][j+1]*l*2);
			}
	for(int i=1 ; i<=n ; ++i,puts(""))
		for(int j=1 ; j<=m ; ++j)
			printf("%d ",f[k][i][j]);
	return 0;
}