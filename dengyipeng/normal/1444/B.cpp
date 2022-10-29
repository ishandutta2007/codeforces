#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define maxn 300005
#define mo 998244353
using namespace std;

int n,i,j,k;
ll a[maxn],ans,C;

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n*2;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n*2);
	for(i=1;i<=n;i++) ans-=a[i],ans+=a[n+i];
	ans=(ans%mo+mo)%mo;
	C=1;for(i=1;i<=n;i++) C=C*(2*n-i+1)%mo*ksm(i,mo-2)%mo;
	printf("%lld",ans*C%mo);
}