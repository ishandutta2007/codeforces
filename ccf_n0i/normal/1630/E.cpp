#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
const int mod=998244353;
int pw(int x,int y){int z=1;while(y){if(y&1)z=1ll*z*x%mod;x=1ll*x*x%mod;y>>=1;}return z;}
int n,fac[1333333],inv[1333333],fiv[1333333];
int c[1333333],s[1333333];
vector<int> v;
int cans,cway;
void calc(int x,int coef){
	int ans,way=fac[n/x],wi,i;
	rep0(i,v.size()){
		way=1ll*way*fiv[v[i]/x]%mod;
	}
	ans=way;
	wi=pw(way,mod-2);
	rep0(i,v.size())if(v[i]/x>1){
		ans=(ans+1ll*(mod-way)*(v[i]/x)%mod*(v[i]/x-1)%mod*inv[n/x]%mod*inv[n/x-1])%mod;
	}
	cans=(cans+1ll*n*ans%mod*coef)%mod;
	cway=(cway+1ll*way*coef)%mod;
}
void solve(){
	v.clear();
	scanf("%d",&n);
	int i,g=n;
	rep(i,n) c[i]=s[i]=0;
	rep(i,n){
		int x;scanf("%d",&x);
		c[x]++;
	}
	rep(i,n) if(c[i]){
		g=__gcd(g,c[i]);
		v.push_back(c[i]);
	}
	if(v.size()==1){
		puts("1");
		return;
	}
	rep(i,n) s[n/__gcd(i,n)]++;
	cans=cway=0;
	rep(i,n) if(g%i==0){
		calc(i,s[i]);
	}
	cans=1ll*cans*pw(cway,mod-2)%mod;
	printf("%d\n",cans);
}
int main(){
	int i;
	fac[0]=fac[1]=inv[1]=fiv[0]=fiv[1]=1;
	for(i=2;i<=1222222;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fiv[i]=1ll*fiv[i-1]*inv[i]%mod;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}