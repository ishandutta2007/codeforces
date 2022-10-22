#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,st[99],tp;char e[99][99];long long f[20][1<<18],g[20][1<<18],h[20][1<<18],ans[1<<18];
unsigned long long hsh;map<unsigned long long,long long> mp;
inline void FWT(long long*a,int len){
	for(int md=1;md<len;md<<=1) for(int i=0;i<len;i+=md<<1) for(int j=0;j<md;++j) a[i+j+md]+=a[i+j];
}
inline void IFWT(long long*a,int len){
	for(int md=1;md<len;md<<=1) for(int i=0;i<len;i+=md<<1) for(int j=0;j<md;++j) a[i+j]-=a[i+j+md];
}
void dfs(int nw,int bg,int dep,unsigned long long hsh){
	if(nw>=n){
		long long res=0;
		for(int i=0;i<(1<<n);++i) res+=h[dep][i]*((__builtin_popcount(((1<<n)-1)^i)&1)?-1:1);
		mp[hsh]+=res;
		return;
	}
	for(int i=bg;i<=n-nw;++i){
		for(int j=0;j<(1<<n);++j) h[dep+1][j]=h[dep][j]*g[i][j];
		dfs(nw+i,i,dep+1,hsh*19911225+i);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%s",e[i]);
	for(int i=0;i<n;++i) f[i][1<<i]=1;
	for(int i=1;i<(1<<n);++i) for(int j=0;j<n;++j) if(f[j][i])
		for(int k=0;k<n;++k) if(e[j][k]=='1'&&!((i>>k)&1)) f[k][i|(1<<k)]+=f[j][i];
	for(int i=0;i<(1<<n);++i) for(int j=0;j<n;++j) if(f[j][i]) g[__builtin_popcount(i)][i]+=f[j][i];
	for(int i=0;i<=n;++i) FWT(g[i],1<<n);
	for(int i=0;i<(1<<n);++i) h[0][i]=1;
	dfs(0,1,0,0);
	for(int i=0;i<(1<<(n-1));ans[i++]=mp[hsh]){
		hsh=tp=0;
		for(int j=0,t=1;j<n;++j) if((i>>j)&1) ++t;else st[++tp]=t,t=1;
		sort(st+1,st+tp+1);
		for(int j=1;j<=tp;++j) hsh=hsh*19911225+st[j];
	}
	IFWT(ans,1<<(n-1));
	for(int i=0;i<(1<<(n-1));++i) printf("%lld ",ans[i]);
	return 0;
}