#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 505
using namespace std;

int T,n,m,i,j,k,a[maxn][maxn],b[maxn][maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n+2;i++) for(j=1;j<=m+2;j++) a[i][j]=b[i][j]=0;
		char ch=getchar();
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) {
			while (ch!='.'&&ch!='X') ch=getchar();
			a[i][j]=ch=='X',b[i][j]=a[i][j],ch=getchar();
		}
		int t=(m%3==0);
		for(i=t+1;i<=m;i+=3) for(j=1;j<=n;j++) b[j][i]=1;
		for(i=t+1;i<=m;i+=3) {
			for(j=1;j<=n;j++) {
				if (b[j][i+1]||b[j][i+2]) {
					b[j][i+1]=b[j][i+2]=1;
					break;
				}
			}
			if (j>n) b[1][i+1]=b[1][i+2]=1;
		}
		for(i=1;i<=n;i++,printf("\n")) for(j=1;j<=m;j++) putchar(b[i][j]?'X':'.');
	}
}