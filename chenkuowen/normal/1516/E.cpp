#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,N=405;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x>=MOD?x-=MOD:0; }
int comb[N][N],inv[N],fac[N],ifac[N];
struct II{
	II(){
		inv[1]=fac[0]=ifac[0]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
		for(int i=0;i<N;++i){
			comb[i][0]=1;
			for(int j=1;j<=i;++j)
				mo(comb[i][j]=comb[i-1][j-1]+comb[i-1][j]);
		}
	}
}__ii;
int comb1(int n,int m){
	if(n<m||n<0||m<0) return 0;
	if(n<N&&m<N) return comb[n][m];
	int ret=1;
	for(int i=1;i<=m;++i) ret=1ll*(n-i+1)*inv[i]%MOD*ret%MOD;
	return ret;
}
int f[N][N],ans[N];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	if(n==2){
		for(int i=1;i<=k;++i) printf("1 ");
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=min(n,k+k);++i)
		for(int t=1;t<=i;++t){
			for(int j=2;j<=i;++j)
				f[i][t]=(f[i][t]+1ll*f[i-j][t-1]*fac[i-1]%MOD*ifac[i-j])%MOD;
		//	if(f[i][t]>0) printf("[%d %d %d]",i,t,f[i][t]);
		}
	ans[0]=1;
	for(int j=1;j<=k;++j){
		ans[j]=0;
		for(int i=j;i<=min(n,j+j);++i){
		//	printf("[%d]",int(1ll*comb1(n,i)*f[i][i-j]%MOD));
			ans[j]=(ans[j]+1ll*comb1(n,i)*f[i][i-j])%MOD;
		}
//		printf("{%d}",ans[j]);
	}
	for(int j=1;j<=k;++j){
		int ret=0;
		for(int i=j;i>=0;i-=2) mo(ret+=ans[i]);
		printf("%d ",ret);
	}
	return 0;
}