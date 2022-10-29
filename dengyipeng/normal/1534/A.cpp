#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 51
using namespace std;

int T,n,m,i,j,k,a[maxn][maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		char ch=getchar();
		for(i=1;i<=n;i++){
			while (ch!='.'&&ch!='R'&&ch!='W') ch=getchar();
			for(j=1;j<=m;j++) a[i][j]=(ch=='.')?-1:(ch=='R'),ch=getchar();
		}
		int bz=-1,tp=0;
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) if (a[i][j]>=0){
			if (bz<0) bz=a[i][j]^((i+j)&1);
			else if (bz!=(a[i][j]^((i+j)&1))) tp=1;
		}
		if (tp) printf("NO\n"); else {
			printf("YES\n");
			bz=max(bz,0);
			for(i=1;i<=n;i++,putchar('\n'))
				for(j=1;j<=m;j++) 
					putchar((bz^((i+j)&1))?'R':'W');
		}
	}
}