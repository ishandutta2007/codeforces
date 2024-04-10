#include<cstdio>
#include<algorithm>
using namespace std;
const int o=310,MOD=1e9+7;
int n,a[o],b[o],cnt,s[o][o],f[o],g[o],h[o],ans;
int main(){
	scanf("%d",&n);
	for(int i=1,j=2;i<=n;++i)
		for(scanf("%d",&a[i]),j=2;j*j<=a[i];++j) for(;a[i]%(j*j)==0;a[i]/=(j*j));
	sort(a+1,a+n+1);
	for(int i=1;i<=n;) for(b[++cnt]=1,++i;i<=n&&a[i]==a[i-1];++b[cnt],++i);
	for(int i=s[0][0]=1;i<=n;++i) for(int j=1;j<=i;++j)
		s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1ll+j))%MOD;
	for(int i=f[0]=1;i<=cnt;++i){
		for(int j=0;j<=n;++j) g[j]=0;
		for(int j=b[i],k=1;j;--j,k=MOD-k) h[j]=s[b[i]][j]*1ll*k%MOD; 
		for(int j=1;j<=b[i];++j) for(int k=0;j+k<=n;++k)
			g[j+k]=(g[j+k]+h[j]*1ll*f[k])%MOD;
		for(int j=0;j<=n;++j) f[j]=g[j];
	}
	for(int i=1,j=1;i<=n;j=j*1ll*(++i)%MOD) ans=(ans+j*1ll*f[i])%MOD;
	printf("%d",ans);
	return 0;
}