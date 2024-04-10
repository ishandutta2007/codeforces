#include<cstdio>
#include<algorithm>
#include<assert.h>  //!!!
using namespace std;
typedef long long ll;
const int mod=998244353;
inline int upd(int x){return x+(x>>31&mod);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
int fac[4000100],ifac[4000100],inv[4000100];
void init(int x){
	fac[0]=1; for (int i=1;i<=x;i++) fac[i]=1LL*fac[i-1]*i%mod;
	ifac[x]=qpow(fac[x],mod-2); for (int i=x;i;i--) ifac[i-1]=1LL*ifac[i]*i%mod;
	inv[1]=1; for (int i=2;i<=x;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
inline int C(int n,int m){return 1LL*fac[n]*ifac[n-m]%mod*ifac[m]%mod;}  //without check

int n,m;
int main()
{
	scanf("%d%d",&n,&m); init(n+m+10);
	int res=1;
	for (int i=0;i<n;i++){
		int p=1LL*fac[n-i+m-1]*ifac[m-1]%mod*ifac[n+m-i]%mod*fac[m]%mod;
		//printf("p %d = %d\n",i,p);
		assert(p!=1);
		p=1LL*p*qpow(upd(1-p),mod-2)%mod;
		int t=(n-i+1)&1?mod-1:1;
		t=1LL*t*C(n,i)%mod*p%mod;
		res=upd(res+t-mod);
		//printf("t %d\n",t);
	}
	//printf("%d\n",res);
	res=1LL*res*(m+n+1)%mod*inv[m+1]%mod;
	printf("%d\n",res);
	return 0;
}