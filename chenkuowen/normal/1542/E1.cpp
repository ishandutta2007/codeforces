#include<bits/stdc++.h>
using namespace std;
unsigned MOD,comb[505][505],fac[505];
inline unsigned mo1(unsigned x){ return x>=MOD?x-MOD:x;}
inline void mo(unsigned& x){x>=MOD?x-=MOD:0; }
void init(){
	for(int i=0;i<=500;++i){
		if(i==0) fac[i]=1;
		else fac[i]=1llu*fac[i-1]*i%MOD;
		comb[i][0]=1;
		for(int j=1;j<=i;++j)
		mo(comb[i][j]=comb[i-1][j-1]+comb[i-1][j]);
	}
}

inline unsigned fpow(unsigned x,unsigned n,unsigned ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
unsigned f[505*505],g[505*505],f1[505*505],g1[505*505],h[505];
int main(){
	int n; scanf("%d%d",&n,&MOD); 
	init();
	unsigned ans=0;
	f[0]=1; int top=n*(n-1)/2;
	for(int j=0;j<=top;++j) g[j]=mo1((j==0?0:g[j-1])+f[j]);
	for(int i=1;i<n;++i){
		memset(f1,0,4*(top+1));
		memset(g1,0,4*(top+1));
		for(int j=0;j<=top;++j){
			f1[j]=mo1(g[j]+MOD-(j-i>=0?g[j-i]:0));
			g1[j]=mo1((j==0?0:g1[j-1])+f1[j]);
		}				
		memcpy(f,f1,4*(top+1));
		memcpy(g,g1,4*(top+1));
		for(int j=1;j<=n;++j){
			h[j]=0;
			for(int t=j+1;t<=top;++t)
				h[j]=(h[j]+1llu*f[t]*g[t-j-1])%MOD;
		}
		unsigned key=1llu*comb[n][i+1]*fac[n-i-1]%MOD;
		for(int j=0;j<=i;++j)
			for(int k=j+1;k<=i;++k)
				mo(ans+=1llu*h[k-j]*key%MOD);
	}
	printf("%u\n",ans);
	return 0;
}