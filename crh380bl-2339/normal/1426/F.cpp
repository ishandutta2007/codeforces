#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
char s[200005];
int s1[200005],s2[200005],a1[200005],a2[200005];
long long qpow(long long x,int y){
	if(y<=0)return 1LL;
	long long t=1LL;
	while(y){
		if(y&1)t=t*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return t;
}
int main(){
	int n,i;
	long long ans=0;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;++i){
		s1[i]=s1[i-1]+(s[i]=='a');
		a1[i]=a1[i-1]+(s[i]=='?');
	}
	for(i=n;i>=1;--i){
		s2[i]=s2[i+1]+(s[i]=='c');
		a2[i]=a2[i+1]+(s[i]=='?');
	}
	for(i=2;i<n;++i){
		if(s[i]=='?'||s[i]=='b'){
			ans=(ans+1LL*s1[i-1]*s2[i+1]%MOD*qpow(3LL,a1[i-1]+a2[i+1]))%MOD;
			ans=(ans+1LL*s1[i-1]*a2[i+1]%MOD*qpow(3LL,a1[i-1]+a2[i+1]-1))%MOD;
			ans=(ans+1LL*s2[i+1]*a1[i-1]%MOD*qpow(3LL,a1[i-1]+a2[i+1]-1))%MOD;
			ans=(ans+1LL*a1[i-1]*a2[i+1]%MOD*qpow(3LL,a1[i-1]+a2[i+1]-2))%MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}