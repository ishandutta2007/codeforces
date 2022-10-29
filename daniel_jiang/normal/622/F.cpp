// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5,mod=1e9+7;
ll n,k,y[N],fac[N]={1},inv[N]={1};
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
ll pw(ll x,ll y){
	ll sum=1;
	while(y){
		if(y&1) sum=(sum*x)%mod;x=(x*x)%mod;y>>=1;
	}
	return sum;
}
ll Inv(ll x){return pw(x,mod-2);}
ll lagrange(ll n,ll k){
	if(n<=k+2) return y[n];
	ll pre=1,sum=0;
	for(ll i=1;i<=k+2;i++) pre=pre*(n-i)%mod;
	for(ll i=1;i<=k+2;i++) sum=(sum+y[i]*pre%mod*Inv(n-i)%mod*Inv(fac[i-1]*inv[k+2-i]%mod)+mod)%mod;
	return (sum+mod)%mod;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(k);
	for(ll i=1;i<=k+2;i++) y[i]=(y[i-1]+pw(i,k))%mod;
	for(ll i=1;i<=k+2;i++) fac[i]=fac[i-1]*i%mod,inv[i]=-inv[i-1]*i%mod;
	wr(lagrange(n,k));puts("");
	return 0;
}