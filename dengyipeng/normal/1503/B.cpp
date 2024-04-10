#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 105
using namespace std;

int n,i,j,k,a[maxn][maxn];
int d1[maxn*maxn],d2[maxn*maxn];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if ((i+j)&1) d1[++d1[0]]=(i-1)*n+j-1;
		else d2[++d2[0]]=(i-1)*n+j-1;
	while (d1[0]||d2[0]){
		scanf("%d",&k);
		if (d1[0]&&d2[0]){
			if (k!=1) printf("1 %d %d\n",d1[d1[0]]/n+1,d1[d1[0]]%n+1),d1[0]--;
			else printf("2 %d %d\n",d2[d2[0]]/n+1,d2[d2[0]]%n+1),d2[0]--;
		} else 
		if (d1[0]){
			if (k!=1) printf("1 %d %d\n",d1[d1[0]]/n+1,d1[d1[0]]%n+1),d1[0]--;
			else printf("3 %d %d\n",d1[d1[0]]/n+1,d1[d1[0]]%n+1),d1[0]--;
		} else {
			if (k!=2) printf("2 %d %d\n",d2[d2[0]]/n+1,d2[d2[0]]%n+1),d2[0]--;
			else printf("3 %d %d\n",d2[d2[0]]/n+1,d2[d2[0]]%n+1),d2[0]--;
		}
		fflush(stdout);
	}
}