#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxm 11
#define maxn 1005
using namespace std;
 
int n,i,j,k,m,x,y;
int bz[maxm],d[maxn];
int V(int k,int v){return (k&1)?(v==y):(v==(x^y));}
 
int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d%d%d",&n,&x,&y);
	m=1;while ((1<<m)<=n) m++;
	for(i=0;i<m;i++){
		putchar('?'),k=0;
		for(j=1;j<=n;j++) if (j>>i&1) k++;
		printf(" %d ",k);
		for(j=1;j<=n;j++) if (j>>i&1) printf("%d ",j);
		printf("\n");
		fflush(stdout);
		int v; scanf("%d",&v);
		bz[i]=V(k,v);
	}
	for(i=0;i<m;i++) if (bz[i]){
		k=0;
		for(j=1;j<=n;j++) if (j>>i&1) k++;
		if (k<=n-k){
			for(j=1;j<=n;j++) if (j>>i&1) 	
				d[++d[0]]=j;
		} else {
			for(j=1;j<=n;j++) if (j>>i&1^1)
				d[++d[0]]=j;
		}
		break;
	}
	while (d[0]>1){
		k=d[0]/2;
		printf("? %d ",k);
		for(i=1;i<=k;i++) printf("%d ",d[i]);
		printf("\n");
		fflush(stdout);
		int v; scanf("%d",&v);
		if (V(k,v)) d[0]=k; else{
			for(i=1;i<=d[0]-k;i++) 
				d[i]=d[i+k];
			d[0]-=k;
		}
	}
	int xi=d[1],yi=xi;
	for(i=0;i<m;i++) yi^=bz[i]<<i;
	if (xi>yi) swap(xi,yi);
	printf("! %d %d\n",xi,yi);
	fflush(stdout);
}