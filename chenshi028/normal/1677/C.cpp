#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,ca[o],cb[o],h[o],cnt,len[o],tot;bool vis[o];long long ans;
struct Edge{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	vis[nw]=1;++len[tot];
	for(int i=h[nw];i;i=e[i].p) if(!vis[e[i].v]) dfs(e[i].v);
}
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=cnt=tot=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) h[i]=vis[i]=0;
		for(int i=1;i<=n;++i) scanf("%d",&ca[i]);
		for(int i=1;i<=n;++i) scanf("%d",&cb[i]),ad(ca[i],cb[i]),ad(cb[i],ca[i]);
		for(int i=1;i<=n;++i) if(!vis[i]){
			len[++tot]=0;dfs(i);
			if(len[tot]<2) --tot;
		}
		sort(len+1,len+tot+1);
		for(int i=1,j=n-1;i<=tot;++i,--j) for(ans+=j-len[i]/2+1,len[i]=len[i]/2*2;--len[i];) ans+=(j--);
	}
	return 0;
}