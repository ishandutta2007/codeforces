#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define mod 998244353
using namespace std;
char s[N];
ll fac[N],_fac[N];
ll C(int x,int y){
	if(x<y)return 0;
	return fac[x]*_fac[y]%mod*_fac[x-y]%mod;
}
ll ksm(ll x,int y){
	ll t=1;
	while(y){
		if(y&1)t=t*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return t;
}
int main(){
	int T,n,i,a,b;
	fac[0]=1;
	for(i=1;i<N;++i)fac[i]=fac[i-1]*i%mod;
	for(i=0;i<N;++i)_fac[i]=ksm(fac[i],mod-2);
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		a=b=0;
		for(i=1;i<=n;++i){
			if(s[i]=='0')++a;
			else if(s[i+1]=='1'){
				++b;
				++i;
			}
		}
		printf("%lld\n",C(a+b,b));
	}
	return 0;
}