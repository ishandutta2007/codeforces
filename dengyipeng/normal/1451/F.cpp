#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 105
using namespace std;

int T,n,m,i,j,k,a[maxn][maxn],v[maxn*2];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
		memset(v,0,sizeof(v));
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) v[i+j-1]^=a[i][j];
		int tp=0;
		for(i=1;i<=n+m-1;i++) tp|=v[i];
		if (!tp) printf("Jeel\n"); else printf("Ashish\n");
	}
}