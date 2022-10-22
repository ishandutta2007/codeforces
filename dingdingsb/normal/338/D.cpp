#include<bits/stdc++.h>
#define Bye puts("NO"),exit(0)
using namespace std;
const int N=100000+10;
typedef long long ll;
int n;
ll xx,yy;
ll a[N],b[N],ans,M;
ll ksc(ll n,ll k,ll mod){
	ll ans=0;
	while(k){
		if(k&1)ans+=n,ans%=mod;
		k>>=1;
		n*=2;n%=mod;
	}return ans;
}
ll exgcd(ll a,ll b,ll&x,ll&y){
	if(!b){x=1,y=0;return a;}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-(a/b)*y;
	return d;
}
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll CRT(){
	ll x,y;
	ans=a[1];M=b[1];
	for(int i=2;i<=n;i++){
		ll B=((a[i]-ans)%b[i]+b[i])%b[i];
		ll GCD=exgcd(M,b[i],x,y);
		if(B%GCD)Bye;
		x=ksc(x,B/GCD,b[i]);
		ans+=M*x;
		M*=b[i]/GCD;
		ans=(ans+M)%M;
	}return (ans+M-1)%M+1;
}
signed main(){
	scanf("%lld%lld%d",&xx,&yy,&n);
	M=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		a[i]=-i+1;
		a[i]%=b[i];
		a[i]+=b[i];
		a[i]%=b[i];
		M*=b[i]/gcd(M,b[i]);
		if(M>xx)Bye;
	}
	ll i=M;ll j=CRT();
	if(j+n-1>yy)Bye;
	for(int l=1;l<=n;l++)
		if(gcd(i,j+l-1)!=b[l])Bye;
	puts("YES");
}