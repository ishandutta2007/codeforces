#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define int LL
#define db double
#define INF 2147483647
#define LLINF 9223372036854775807
#define LL long long
using namespace std;
int inline read(){
    int num=0,neg=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
    while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
    return num*neg;
}
const int maxn=200010,mod=998244353;
int n,k,fac[maxn],facinv[maxn],inv[maxn],ans;
int C(int n,int m){
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;x=1ll*x*x%mod;y>>=1;
	}return ans;
}
signed main()
{
	n=read();k=read();
	if(k>=n){cout<<0;return 0;}
	fac[0]=fac[1]=facinv[0]=facinv[1]=inv[1]=1;
	for(int i=2;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		facinv[i]=1ll*facinv[i-1]*inv[i]%mod;
	}if(k==0){cout<<fac[n];return 0;}
	for(int j=0;j<=n-k;j++){
		if(j&1)ans=(ans-1ll*C(n-k,j)*ksm(n-k-j,n)%mod+mod)%mod;
		else ans=(ans+1ll*C(n-k,j)*ksm(n-k-j,n)%mod)%mod;
	}ans=1ll*ans*C(n,k)%mod;cout<<1ll*ans*2%mod;return 0;
}