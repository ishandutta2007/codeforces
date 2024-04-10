#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=998244353;
const int MAX_N=5+1e3;
typedef long long ll;
ll f[MAX_N],c[MAX_N][MAX_N],a[MAX_N],s[MAX_N];
void get_c(int n){
	memset(c,0,sizeof(c));
	for(int j=0;j<=n;++j) c[0][j]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			c[i][j]=c[i][j-1]+c[i-1][j-1];
			if(c[i][j]>=MOD) c[i][j]-=MOD;
		}
	}
}
int main(){
	int n; scanf("%d",&n),get_c(n);
	for(int i=1;i<=n;++i) scanf("%I64d",&a[i]);
	f[0]=1,s[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=0;
		for(int j=1;j<i;++j)
			if(a[j]>0&&a[j]<=i-j)
				f[i]=(f[i]+s[j-1]*c[a[j]-1][i-j-1])%MOD;
		s[i]=(s[i-1]+f[i])%MOD;
	}
	ll ans=0;
	for(int i=1;i<=n;++i) ans=(ans+f[i])%MOD;
	printf("%I64d",ans);
	return 0;
}