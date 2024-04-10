#include<bits/stdc++.h>
using namespace std;
const int N=5+4e5,MOD=998244353;
int inv[N],fac[N],ifac[N];
struct II{
	II(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__ii;
inline int comb(int n,int m){
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int sa[N],r[N];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i) scanf("%d",&sa[i]),r[sa[i]]=i;
	r[n]=-1;
	int cnt=1;
	for(int i=0;i+1<n;++i){
		if(r[sa[i]+1]<r[sa[i+1]+1]) ;
		else ++cnt;
	}
	int ans=0;
	for(int i=0;i<=n-cnt;++i)
		ans=(ans+1ll*comb(n-cnt,i)*comb(k,cnt+i))%MOD;
	printf("%d\n",ans);
	return 0;
}