#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define mo 998244353
#define maxn 262145
using namespace std;

int n,m,i,j,k;
ll fct[maxn],invf[maxn],a[maxn],b[maxn];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

int lim,bt[maxn];
void dft(ll *a,int sig){
	for(int i=1;i<lim;i++) if (i<bt[i]) swap(a[i],a[bt[i]]);
	for(int mid=1;mid<lim;mid<<=1){
		ll gn=ksm(3,mo-1+sig*(mo-1)/(mid<<1));
		for(int j=0;j<lim;j+=mid<<1){
			ll g=1;
			for(int k=0;k<mid;k++,g=g*gn%mo){
				ll x=a[j+k],y=a[j+k+mid]*g;
				a[j+k]=(x+y)%mo,a[j+k+mid]=(x-y)%mo;
			}
		}
	}
	if (sig<0){
		ll inv=ksm(lim,mo-2);
		for(int i=0;i<lim;i++) a[i]=a[i]*inv%mo;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	fct[0]=1;for(i=1;i<maxn;i++) fct[i]=fct[i-1]*i%mo;
	invf[maxn-1]=ksm(fct[maxn-1],mo-2);
	for(i=maxn-2;i>=0;i--) invf[i]=invf[i+1]*(i+1)%mo;
	for(i=0;i<=m;i++) a[i]=ksm(i,m)*invf[i]%mo,b[i]=((i&1)?-1:1)*invf[i]%mo;
	lim=1; while (lim<=m*2) lim<<=1;
	for(i=1;i<lim;i++) bt[i]=(bt[i>>1]>>1)|((i&1)*(lim>>1));
	dft(a,1),dft(b,1);
	for(i=0;i<lim;i++) a[i]=a[i]*b[i]%mo;
	dft(a,-1);
	ll s=ksm(n+1,n),Inv=ksm(n+1,mo-2),ans=0;
	for(i=0;i<=m;i++) (ans+=s*a[i])%=mo,s=s*Inv%mo*(n-i)%mo;
	printf("%lld\n",(ans%mo+mo)%mo);
}