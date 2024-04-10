#include<cstdio>
using namespace std;
const int o=260,MOD=998244353;
int n,k,f[o][o],C[o][o],pw[o][o*o];
int main(){
	scanf("%d%d",&n,&k);--n;
	for(int i=1;i<=k;++i)
		for(int j=pw[i][0]=1;j<=n*n;++j) pw[i][j]=pw[i][j-1]*1ll*i%MOD;
	for(int i=C[0][0]=1;i<=n;++i)
		for(int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	for(int i=f[0][0]=1;i<=k;++i) for(int j=0;j<=n;++j) for(int $=0;j+$<=n;++$)
		f[i][j+$]=(f[i][j+$]+f[i-1][j]*1ll*C[n-j][$]%MOD*pw[k-i+1][(($+j)*($+j-1)-j*(j-1))/2])%MOD;
	printf("%d",f[k][n]);
	return 0;
}