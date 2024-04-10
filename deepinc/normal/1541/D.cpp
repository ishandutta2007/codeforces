#include<bits/stdc++.h>
using namespace std;
vector<int>e[222];
const long long mod=1e9+7,i2=5e8+4;
int qp(int b,int t,int a=1){for(;t;t>>=1,b=1ll*b*b%mod)if(t&1)a=1ll*a*b%mod;return a;}
int n,ans,f[222],sz[222],d[222],p[222][222],s[222][222];
void dfs(int p,int fa){
	sz[p]=1; d[p]=d[fa]+1; f[p]=fa;
	for(int i=0;i<e[p].size();++i) if(e[p][i]^fa) dfs(e[p][i],p),sz[p]+=sz[e[p][i]];
}
int main(){
	scanf("%d",&n);
	p[0][0]=1;
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)
		p[i+1][j]=(p[i+1][j]+p[i][j]*i2)%mod,
		p[i][j+1]=(p[i][j+1]+p[i][j]*i2)%mod;
	for(int i=0;s[i][0]=p[i][0],i<=n;++i)for(int j=1;j<=n;++j)
		s[i][j]=(s[i][j-1]+p[i][j])%mod;
	for(int i=1,a,b;i<n;++i)scanf("%d%d",&a,&b),e[a].push_back(b),e[b].push_back(a);
	for(int i=1;i<=n;++i){
		dfs(i,0);
		for(int j=i+1,p;p=j,j<=n;++j){
			ans=(ans+sz[j])%mod;
			while(p!=i)ans=(ans+(sz[f[p]]-sz[p])*i2%mod*s[d[j]-d[f[p]]-1][d[f[p]]-2])%mod,p=f[p];
		}
	}printf("%lld",ans*1ll*qp(n,mod-2)%mod);
}