#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 505
using namespace std;

int T,n,m,i,j,k,a[maxn][maxn],b[maxn][maxn],p[maxn*maxn],q[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
		for(i=1;i<=m;i++) for(j=1;j<=n;j++) {
			scanf("%d",&b[i][j]);
			p[b[i][j]]=j;
		}
		for(i=1;i<=n;i++) q[p[a[i][1]]]=i;
		for(i=1;i<=n;i++,printf("\n")) for(j=1;j<=m;j++)
			printf("%d ",a[q[i]][j]);
	}
}