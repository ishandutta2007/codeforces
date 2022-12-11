#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 5010
int n,m,k;long long sums[MAXN],f[MAXN][MAXN],pre[MAXN],ans=-1;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%I64d",&sums[i]),pre[i]=pre[i-1]+sums[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j){
			f[i][j]=f[i-1][j];
			if(i>=m)f[i][j]=max(f[i][j],f[i-m][j-1]+pre[i]-pre[i-m]);
		}
	/*for(int i=1;i<=k;++i){
		for(int j=1;j<=i*m;++j)f[i&1][j]=f[i&1^1][j];
		for(int j=i*m+1;j<=n;++j)
			f[i&1][j]=max(f[i&1][j-1],f[i&1^1][j-m]+pre[j]-pre[j-m]);
	}*/
	printf("%I64d\n",f[n][k]);
	return 0;
}