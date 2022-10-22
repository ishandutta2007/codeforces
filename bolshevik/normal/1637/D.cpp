#include<cstdio>
#include<iostream>
using namespace std;
const int o=110;const long long inf=1e18;
int T,n,a[o],b[o],f[o][o*o],sm;long long ans,s;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans)){
		scanf("%d",&n);ans=inf;s=sm=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),s+=(n-2ll)*a[i]*a[i],sm+=a[i];
		for(int i=1;i<=n;++i) scanf("%d",&b[i]),s+=(n-2ll)*b[i]*b[i],sm+=b[i];
		for(int i=1;i<=n;++i) for(int j=1;j<=n*100;++j) f[i][j]=0;
		f[0][0]=1;
		for(int i=1;i<=n;++i){
			for(int j=a[i];j<=n*100;++j) f[i][j]|=f[i-1][j-a[i]];
			for(int j=b[i];j<=n*100;++j) f[i][j]|=f[i-1][j-b[i]];
		}
		for(int i=0;i<=n*100;++i) if(f[n][i]) ans=min(ans,i*1ll*i+(sm-i)*1ll*(sm-i)+s);
	}
	return 0;
}