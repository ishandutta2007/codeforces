#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x>=MOD?x-=MOD:0; }
inline bool gbit(int sta,int i){ return (sta>>i)&1; }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int a[23],s[23][1<<14|5],f[1<<14|5],g[1<<14|5],h[1<<14|5],lg[1<<14|5],bitcnt[1<<14|5];
int prob(int x,int y){ return fpow(a[x]+a[y],MOD-2,a[x]); }
struct II{
	II(){
		lg[0]=-1; bitcnt[0]=0;
		for(int i=1;i<1<<14;++i){
			lg[i]=lg[i>>1]+1;
			bitcnt[i]=bitcnt[i-(i&-i)]+1;
		}
	}
}__ii;
inline int lb(int x){ return x&-x; }
int ss(int sta1,int sta2){
	int ans=1;
	for(;sta1>0;sta1-=lb(sta1)){
		int x=lg[lb(sta1)];
		ans=1ll*ans*s[x][sta2]%MOD;
	}
	return ans;
}
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	for(int i=0;i<n;++i){
		s[i][0]=1;
		for(int sta=1;sta<1<<n;++sta){
			s[i][sta]=1ll*s[i][sta-lb(sta)]*prob(i,lg[lb(sta)])%MOD;
		}
	}
	for(int sta=1;sta<1<<n;++sta){
		for(int sta1=(sta-1)&sta;sta1>0;sta1=(sta1-1)&sta){
			g[sta]=(g[sta]+1ll*f[sta1]*(f[sta-sta1]+g[sta-sta1])%MOD*ss(sta-sta1,sta1))%MOD;
		}
		f[sta]=mo1(1+MOD-g[sta]);
	}
	h[0]=0;
	for(int sta=1;sta<1<<n;++sta){
		h[sta]=1ll*bitcnt[sta]*f[sta]%MOD;
		for(int sta1=(sta-1)&sta;sta1>0;sta1=(sta1-1)&sta){
			h[sta]=(h[sta]+1ll*h[sta-sta1]*ss(sta-sta1,sta1)%MOD*f[sta1])%MOD;
		}
	}
	printf("%d\n",h[(1<<n)-1]);
	return 0;
}