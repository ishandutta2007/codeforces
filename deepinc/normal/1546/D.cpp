#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
const int $=555555,mod=998244353;
int qp(int b,int t,int a=1){for(;t;t>>=1,b=1ll*b*b%mod)if(t&1)a=1ll*a*b%mod;return a;}
int n,ans,c,fac[$],inv[$]; char a[$];
int main(){
	for(int i=fac[0]=1;i<=100000;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[100000]=qp(fac[100000],mod-2);
	for(int i=99999;~i;--i)inv[i]=inv[i+1]*(i+1ll)%mod;
	int t,z,c0;cin>>t;while(t--){
		scanf("%d%s",&n,a+1); z=0;c0=-1;
		for(int i=1,cb=0;i<=n+1;++i)
			if(a[i]=='1')cb++;
			else z+=cb>>1,cb=0,c0++;
		printf("%lld\n",1ll*fac[z+c0]*inv[z]%mod*inv[c0]%mod);
	}
}