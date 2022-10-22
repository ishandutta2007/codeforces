#include<cstdio>
using namespace std;
const int o=5e5+10;
int T,n,m,h[o],cnt,lk[o],t,g,ans0,ans1,ans2;bool vis[o][2],vis_[o],f[o][2],f_[o];long long ans;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
#define rep for(int i=h[u];i;i=e[i].p) if(e[i].v>u+1&&lk[e[i].v-2]-lk[u]==e[i].v-u-2)
void Dfs(int u,int j){
	if(vis[u][j]) return;
	vis[u][j]=1;
	rep Dfs(e[i].v-1,!j),f[u][j]|=f[e[i].v-1][!j];
}
void dfs(int u,int j){
	if(vis[u][j]) return;
	vis[u][j]=1;
	if(lk[n]-lk[u]==n-u&&!j) ++g;
	rep dfs(e[i].v-1,!j);
}
inline void clr(){for(int i=0;i<=n;++i) f[i][0]=f[i][1]=vis[i][0]=vis[i][1]=0;}
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=cnt=0){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;++i) h[i]=lk[i]=0;
		for(int u,v;m--;){
			scanf("%d%d",&u,&v);ad(u,v);
			if(u+1==v) lk[u]=1;
		}
		for(int i=2;i<=n;++i) ad(0,i);
		for(int i=1;i<n;++i) ad(i,n+1);
		for(int i=lk[0]=lk[n]=1;i<=n;++i) lk[i]+=lk[i-1];
		if(lk[n]==n+1){ans=n*(n-1ll)/2;continue;}
		for(t=0;lk[t]==t+1;++t);
		g=0;clr();dfs(t,0);ans0=g;
		for(int i=0;i<=n;++i) vis_[i]=vis[i][0];
		g=0;clr();dfs(t,1);ans1=g;
		for(int i=ans2=0;i<=n;++i) if(vis_[i]&&vis[i][0]&&lk[n]-lk[i]==n-i) ++ans2; 
		clr();f[t][0]=1;
		for(int i=0;i<=t;++i) Dfs(i,0),ans+=ans0*f[i][0];
		for(int i=0;i<=t;++i) f_[i]=f[i][0];
		clr();f[t][1]=1;
		for(int i=0;i<=t;++i) Dfs(i,0),ans+=ans1*f[i][0];
		for(int i=0;i<=t;++i) ans-=ans2*(f_[i]&&f[i][0]);
		ans-=(lk[n]-lk[t]==n-t);
	}
	return 0;
}