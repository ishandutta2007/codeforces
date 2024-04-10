#include<cstdio>
using namespace std;
const int o=4e5+10,MOD=1e9+7;
int n,k,h[o],cnt,fa[o],f[o],fac[o],inv[o],u[o],v[o],s[o],ans;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline int C(int x,int y){return fac[x]*1ll*inv[y]%MOD*inv[x-y]%MOD;}
void dfs(int nw){
	s[nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa[nw]) fa[e[i].v]=nw,dfs(e[i].v),s[nw]+=s[e[i].v];
}
inline int sz(int u,int v){
	if(fa[u]==v) return s[u];
	return n-s[v];
}
inline int calc(int u,int v){return (C(sz(v,u),k)+MOD-(f[v]+MOD-C(sz(u,v),k))%MOD)*1ll*(n-sz(v,u))%MOD*sz(v,u)%MOD;}
int main(){
	scanf("%d%d",&n,&k);inv[1]=1;
	for(int i=1;i<n;++i) scanf("%d%d",&u[i],&v[i]),ad(u[i],v[i]),ad(v[i],u[i]);
	for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
	dfs(1);
	for(int i=1;i<n;++i) f[u[i]]=(f[u[i]]+C(sz(v[i],u[i]),k))%MOD,f[v[i]]=(f[v[i]]+C(sz(u[i],v[i]),k))%MOD;
	for(int i=1;i<n;++i) ans=(ans+(calc(u[i],v[i])+calc(v[i],u[i]))%MOD)%MOD;
	for(int i=1;i<=n;++i) ans=(ans+(C(n,k)+MOD-f[i])*1ll*n)%MOD;
	printf("%d",ans);
	return 0;
}