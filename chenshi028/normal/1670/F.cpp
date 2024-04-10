#include<cstdio>
#include<iostream>
using namespace std;
const int o=2010,MOD=1e9+7;
int n,f[61][o],c[o][o];long long l,r,z;
inline int calc(long long x){
	for(int i=0;i<61;++i) for(int j=0;j<=2*n;++j) f[i][j]=0;
	f[60][x>>59]=1;
	for(int i=59;i+1;--i) for(int j=0;j<=2*n;++j) for(int k=(z>>i)&1,v;k<=min(j,n);k+=2)
		v=min(2ll*n,2*(j-k)+(i?(x>>(i-1))&1:0)),f[i][v]=(f[i][v]+f[i+1][j]*1ll*c[n][k])%MOD;
	int res=0;
	for(int i=0;i<=2*n;++i) res=(res+f[0][i])%MOD;
	return res;
}
int main(){
	scanf("%d%lld%lld%lld",&n,&l,&r,&z);
	for(int i=c[0][0]=1;i<=n;++i) for(int j=c[i][0]=1;j<=i;++j) c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	printf("%d",(calc(r)+MOD-calc(l-1))%MOD);
	return 0;
}