#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int o=1e6;
int n,k,h[o],cnt,nol,a[o];long long ans=-1e18;bool lf[o];priority_queue<int> q[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw,int fa){
	lf[a[nw]=nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) lf[nw]=0,Dfs(e[i].v,nw);
	if(lf[nw]) ++nol;
}
void dfs(int nw,int fa){
	if(lf[nw]){q[nw].push(1);return;}
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa){
		dfs(e[i].v,nw);
		if(q[a[nw]].size()<q[a[e[i].v]].size()) swap(a[nw],a[e[i].v]);
		for(;!q[a[e[i].v]].empty();q[a[e[i].v]].pop()) q[a[nw]].push(q[a[e[i].v]].top());
	}
	int delt=q[a[nw]].top()+1;
	q[a[nw]].pop();q[a[nw]].push(delt);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	Dfs(1,0);dfs(1,0);
	for(int r=0,j=n,b;r<=k;++r){
		b=min(n/2,j);ans=max(ans,(r-b)*1ll*(n-r-b));
		if(!q[a[1]].empty()) j-=q[a[1]].top(),q[a[1]].pop();
	}
	printf("%lld",ans);
	return 0;
}