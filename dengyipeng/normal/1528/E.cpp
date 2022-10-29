#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 1000005
#define ll long long 
#define mo 998244353
using namespace std;

int n,i,j,k;
ll f[maxn];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}
const ll inv2=ksm(2,mo-2),inv6=ksm(6,mo-2);
ll F(int n){
	ll v=f[n-1]+1;
	return (v*(v-1)%mo*(v-2)%mo*inv6+v*(v-1)+v)%mo;
}
ll G(int n){
	ll v=f[n-1];
	return (v*(v-1)%mo*inv2+v)%mo;
}

int main(){
	scanf("%d",&n),f[0]=1;
	for(i=1;i<=n;i++) 
		f[i]=((f[i-1]+1)*f[i-1]%mo*inv2+(f[i-1]+1))%mo;
	ll ans=((F(n)-F(n-1))*2-1)%mo;
	for(i=1;i<=n-2;i++)
		ans+=(G(i)-G(i-1))*(f[n-i-1]-f[n-i-2]-1)%mo;
	printf("%lld\n",(ans%mo+mo)%mo);
}