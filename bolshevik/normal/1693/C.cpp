#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
const int o=2e5+10,inf=1e9;
int n,m,h[o],cnt,d[o],f[o];bool vis[o];priority_queue<pair<int,int> > q;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
int main(){
	scanf("%d%d",&n,&m);
	for(int u,v;m--;) scanf("%d%d",&u,&v),ad(v,u),++d[u];
	for(int i=1;i<=n;++i) f[i]=inf;
	for(q.push(make_pair(f[n]=0,n));!q.empty();){
		int t=q.top().second;
		q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=h[t];i;i=e[i].p) if((--d[e[i].v])+f[t]+1<f[e[i].v]) q.push(make_pair(-(f[e[i].v]=d[e[i].v]+f[t]+1),e[i].v));
	}
	printf("%d",f[1]);
	return 0;
}