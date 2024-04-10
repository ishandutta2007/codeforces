#include<cstdio>
#include<utility>
#include<queue>
#include<iostream>
using namespace std;
const int inf=1e9;
int n,m,a,b,h[80],cnt,tot,fa[80],s[80],bl[80],d[80][1<<17],ans[80];bool vis[80][1<<17];
priority_queue<pair<int,pair<int,int> > > q;
struct Edge{int v,p,w;}e[999];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(a>b) swap(a,b);
	for(int i=1;i<=n;++i) s[fa[i]=i]=1,ans[i]=inf;
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		ad(u,v,w);ad(v,u,w);
		if(w==a) if((u=fr(u))^(v=fr(v))) s[fa[u]=v]+=s[u];
	}
	for(int i=1;i<=n;++i) if(s[fr(i)]>3){
		if(!bl[fr(i)]) bl[fr(i)]=(1<<(tot++));
		bl[i]=bl[fr(i)];
	}
	for(int i=1;i<=n;++i) for(int j=0;j<(1<<tot);++j) d[i][j]=inf;
	for(q.push(make_pair(d[1][bl[1]]=0,make_pair(1,bl[1])));!q.empty();){
		int t=q.top().second.first,S=q.top().second.second;
		q.pop();
		if(vis[t][S]) continue;
		vis[t][S]=1;ans[t]=min(ans[t],d[t][S]);
		for(int i=h[t];i;i=e[i].p)
			if(d[t][S]+e[i].w<d[e[i].v][bl[e[i].v]|S]&&(e[i].w==a||(!(S&bl[e[i].v])&&fr(t)-fr(e[i].v))))
				q.push(make_pair(-(d[e[i].v][bl[e[i].v]|S]=d[t][S]+e[i].w),make_pair(e[i].v,bl[e[i].v]|S)));
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}