#include<cstdio>
using namespace std;
const int o=210;
int n,d,m;long long c[o][o],f[o][o],g[o][o],ans;
int main(){
	scanf("%d%d%d",&n,&d,&m);
	for(int i=c[0][0]=1;i<=n;++i) for(int j=c[i][0]=1;j<=i;++j)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%m;
	for(int i=1;i<=n;++i){
		if(i==1) f[i][0]=g[1][0]=1;
		else for(int j=1;j<i;++j) for(int k=1;k<i;++k)
			f[i][j]=(f[i][j]+f[i-k][j-1]*c[i-2][k-1]%m*g[k][d-1])%m;
		for(int j=1;j<=n;++j) g[i][j]=(g[i][j-1]+f[i][j])%m;
	}
	for(int i=0;i<n;++i) for(int j=0;j<=d;++j) if(j^1)
		for(int k=0;j+k<=d;++k) ans=(ans+f[i+1][j]*f[n-i][k])%m;
	printf("%lld",ans*2%m*n%m*(n-1)%m);
	return 0;
}