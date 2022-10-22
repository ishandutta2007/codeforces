#include<cstdio>
#include<iostream>
using namespace std;
const int o=2010,MOD=998244353;
inline int fix(int x){return x+(x>>31&MOD);}
int n,K,b[o],f[2][o][o],cur,ans,L,R;
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=f[0][0][0]=1;i<=n;++i,cur^=1){
		R=min(i,b[i]+K);
		for(int j=0;j<=n;++j) f[!cur][L][j]=0;
		for(int j=L+1;j<=R;++j) for(int k=0;k<=i-j;++k){
			f[!cur][j][k]=f[!cur][j-1][k+1]*(k+1ll)%MOD;
			if(j-1<=b[i-1]+K) f[!cur][j][k]=fix(f[!cur][j][k]+f[cur][j-1][k]-MOD);
		}
		L=max(L,b[i]-K);R=min(R,min(b[i-1]+K,i-1));
		for(int j=L;j<=R;++j) for(int k=0;k<=i-j;++k){
			if(k<i-j) f[!cur][j][k]=(f[!cur][j][k]+f[cur][j][k]*1ll*(j+k))%MOD;
			if(k) f[!cur][j][k]=fix(f[!cur][j][k]+f[cur][j][k-1]-MOD);
		}
	}
	R=min(n,b[n]+K);
	for(int i=L;i<=R;++i) for(int j=0,s=1;j<=n-i;++j)
		ans=(ans+f[cur][i][j]*1ll*s)%MOD,s=s*1ll*(n-i-j)%MOD;
	printf("%d",ans);
	return 0;
}