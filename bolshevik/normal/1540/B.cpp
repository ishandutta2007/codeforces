#include<cstdio>
#include<iostream>
using namespace std;
const int o=1010,MOD=1e9+7;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int n,h[o],cnt,st[o][15],dfn[o],ed[o],d[o],lg[o],f[o][o],ans;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa){
	st[dfn[nw]=++cnt][0]=d[nw]=d[fa]+1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) st[++cnt][0]=d[nw],dfs(e[i].v,nw);
	ed[nw]=cnt;
}
inline int ask(int l,int r){int t=lg[r-l+1];return min(st[l][t],st[r-(1<<t)+1][t]);}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	for(int i=1;i<=n;++i) f[0][i]=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) f[i][j]=(f[i-1][j]+f[i][j-1])%MOD*(MOD+1ll)/2%MOD;
	for(int i=1,coef=qp(n,MOD-2);i<=n;++i){
		cnt=0;dfs(i,0);lg[0]=-1;
		for(int j=1;j<=cnt;++j) lg[j]=lg[j>>1]+1;
		for(int j=1;j<15;++j) for(int k=1;k+(1<<(j-1))<=cnt;++k) st[k][j]=min(st[k][j-1],st[k+(1<<(j-1))][j-1]);
		for(int j=1;j<n;++j) for(int k=j+1,t;k<=n;++k)
			t=ask(min(dfn[j],dfn[k]),max(ed[j],ed[k])),ans=(ans+f[d[k]-t][d[j]-t]*1ll*coef)%MOD;
	}
	printf("%d",ans);
	return 0;
}