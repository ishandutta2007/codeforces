#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7,N=5+1e5;
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int ifac[N],fac[N],inv[N];
struct II{
	II(){
		inv[1]=fac[0]=ifac[0]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__ii;
int main(){
	int n,c0=0,c1=0,c2=0; scanf("%d",&n);
	vector<int> a(n); ll sum=0;
	for(int i=0;i<n;++i) scanf("%d",&a[i]),sum+=a[i];
	if(sum%n!=0){
		printf("0");
		return 0;
	}
	map<int,int> g0,g1;
	for(int i=0;i<n;++i){
		if(a[i]==sum/n) ++c2;
		else if(a[i]<sum/n) ++c1,g1[a[i]]++;
		else ++c0,g0[a[i]]++;
	}
	int k0=fac[c0],k1=fac[c1];
	for(auto d:g0) k0=1ll*k0*ifac[d.second]%MOD;
	for(auto d:g1) k1=1ll*k1*ifac[d.second]%MOD;
	if(c0==0&&c1==0){
		printf("1");
		return 0;
	}
	int k;
	if(c0==1||c1==1)
		k=1ll*k0*k1%MOD*fac[c0+c1]%MOD*ifac[c0]%MOD*ifac[c1]%MOD;
	else
		k=2ll*k0*k1%MOD;
	k=1ll*fac[c0+c1+c2]*ifac[c2]%MOD*ifac[c0+c1]%MOD*k%MOD;
	printf("%d\n",k);
}