#include<cstdio>
using namespace std;
const int o=4e6+10;
int n,m,h[o],cnt=1,st[o],d[o],tp,ans,a[o],b[o];bool vis[o],del[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	int t;
	for(int&i=h[nw];i;i=e[i].p) if(!vis[i>>1])
		vis[(t=i)>>1]=1,dfs(e[i].v),st[++tp]=t>>1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,j,k;i<=m;a[i]=j,b[i++]=k)
		scanf("%d%d",&j,&k),ad(j,k),ad(k,j),++d[j],++d[k];
	for(int i=1;i<=n;++i) if(d[i]&1) ad(n+1,i),ad(i,n+1);
	dfs(1);
	for(int i=2;i<=tp;i+=2) if(st[i-1]<=m&&st[i+1]<=m) del[st[i]]=1;
	for(int i=1;i<=m;++i) ans+=!del[i];
	printf("%d\n",ans);
	for(int i=1;i<=m;++i) if(!del[i]) printf("%d %d\n",a[i],b[i]);
	return 0;
}