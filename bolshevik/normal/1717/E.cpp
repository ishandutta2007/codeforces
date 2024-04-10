#include<cstdio>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int o=1e5+10,MOD=1e9+7;
int n,ans,phi[o];
int main(){
	scanf("%d",&n);
	for(int i=1,j;i<=n;++i) for(phi[i]+=i,j=i*2;j<=n;j+=i) phi[j]-=phi[i];
	for(int i=1;i<=n;++i) for(int j=2;i*j<=n;++j) ans=(ans+(n-i*j)*1ll*i/gcd(n-i*j,i)%MOD*phi[j])%MOD;
	printf("%d",ans);
	return 0;
}