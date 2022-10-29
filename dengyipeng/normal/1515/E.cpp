#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 405
#define ll long long 
using namespace std;

int n,mo,i,j,k;
ll f[maxn][maxn],fct[maxn],invf[maxn];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

int main(){
	//freopen("ceshi.in","r",stdin);
	scanf("%d%d",&n,&mo);
	fct[0]=1;for(i=1;i<=n;i++) fct[i]=fct[i-1]*i%mo;
	invf[n]=ksm(fct[n],mo-2);
	for(i=n-1;i>=0;i--) invf[i]=invf[i+1]*(i+1)%mo;
	f[0][0]=1;
	for(i=0;i<n;i++) for(j=0;j<=i;j++) if (f[i][j]){
		ll mul=1;
		for(k=1;i+k<=n;k++) 
			(f[i+k+1][j+k]+=f[i][j]*mul%mo*invf[k])%=mo,mul=mul*2%mo;
	}
	ll ans=0;
	for(i=1;i<=n;i++) (ans+=f[n+1][i]*fct[i])%=mo;
	printf("%lld\n",(ans%mo+mo)%mo);
}