#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 400005
#define ll long long 
#define mo 1000000007
using namespace std;

int T,n,m,i,j,k;
ll fct[maxn],invf[maxn];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}
ll C(int n,int m){return fct[n]*invf[m]%mo*invf[n-m]%mo;}

int main(){
	fct[0]=1;for(i=1;i<maxn;i++) fct[i]=fct[i-1]*i%mo;
	invf[maxn-1]=ksm(fct[maxn-1],mo-2);
	for(i=maxn-2;i>=0;i--) invf[i]=invf[i+1]*(i+1)%mo;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		ll ans=0;
		for(i=1;i<=n;i++) if (n+m-1>=i*m)
			ans+=C(n+m-1-i*(m-1),i)*fct[n-i]%mo*fct[i]%mo;
		else break;
		ans=ans%mo*invf[n]%mo+1;
		printf("%lld\n",ans%mo);
	}
}