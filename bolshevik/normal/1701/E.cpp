#include<cstdio>
#include<iostream>
using namespace std;
const int o=5010,MOD=998244353;
int Tc,n,m,f[o],g[o],pw[o],ans;char s[o],t[o];
struct Hash{
	int h[o];
	inline void build(char*str,int len){for(int i=1;i<=len;++i) h[i]=(h[i-1]*27ll+str[i]-96)%MOD;}
	inline int hsh(int l,int r){return (h[r]+(MOD-pw[r-l+1])*1ll*h[l-1])%MOD;}
}S,T;
int main(){
	for(scanf("%d",&Tc);Tc--;printf("%d\n",ans<o?ans:-1)){
		scanf("%d%d%s%s",&n,&m,s+1,t+1);g[n+1]=m+1;ans=o;
		for(int i=1;i<=n;++i) f[i]=f[i-1]+(f[i-1]<m&&s[i]==t[f[i-1]+1]);
		for(int i=n;i;--i) g[i]=g[i+1]-(g[i+1]>1&&s[i]==t[g[i+1]-1]);
		for(int i=pw[0]=1;i<=n;++i) pw[i]=pw[i-1]*27ll%MOD;
		S.build(s,n);T.build(t,m);
		for(int i=0;i<=n;++i) for(int j=i,k=g[i+1];j+1;--j){
			if(j<i) for(--k;k+i-j-1<=m&&S.hsh(j+1,i)-T.hsh(k,k+i-j-1);++k);
			if(k+i-j-1>m) break;
			if(f[j]>=k-1) ans=min(ans,n-i+j*2-(k-1)+!!j);
		}
	}
	return 0;
}