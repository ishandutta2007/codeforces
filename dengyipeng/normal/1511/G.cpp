#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define maxp 20
using namespace std;

int n,m,q,i,j,k,f[maxn][maxp],g[maxn][maxp];

int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++) scanf("%d",&k),g[k][0]^=1;
	for(j=1;j<maxp;j++) for(i=1;i<=n-(1<<j)+1;i++) {
		g[i][j]=g[i][j-1]^g[i+(1<<j-1)][j-1];
		f[i][j]=f[i][j-1]^f[i+(1<<j-1)][j-1]^(g[i+(1<<j-1)][j-1]<<j-1);
	}
	scanf("%d",&q);
	while (q--){
		int L,R,x,s=0; 
		scanf("%d%d",&L,&R);
		x=L;
		for(i=maxp-1;i>=0;i--) if (x+(1<<i)<=R+1){
			if (g[x][i]) s^=x-L;
			s^=f[x][i],x+=1<<i;
		}
		if (s) printf("A"); else printf("B");
	}
}