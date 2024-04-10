#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=20005;

namespace fl{
const int maxn=80005;

struct edg{
	int v,w,b;
};

vector<edg> adj[maxn];

void ae(int u,int v,int w){
	edg eu,ev;
	eu.v=v;eu.w=w;eu.b=adj[v].size();
	ev.v=u;ev.w=0;ev.b=adj[u].size();
	adj[u].push_back(eu);adj[v].push_back(ev);
}

int cur[maxn],dis[maxn];
int n;
bool bfs(int s,int t){
	for(int i=1;i<=n;i++)cur[i]=0,dis[i]=-1;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<(int)adj[u].size();i++){
			int v=adj[u][i].v;
			if(adj[u][i].w&&dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[t]!=-1;
}
int dfs(int u,int t,int lim){
	if(u==t||!lim)return lim;
	int cf=0;
	for(int&i=cur[u];i<(int)adj[u].size();i++){
		int v=adj[u][i].v,w=adj[u][i].w;
		if(w&&dis[v]==dis[u]+1){
			int f=dfs(v,t,min(lim,w));
			lim-=f;cf+=f;
			adj[u][i].w-=f;
			adj[v][adj[u][i].b].w+=f;
			if(!lim)break;
		}
	}
	return cf;
}
int mxfl(int s,int t){
	int ret=0;
	while(bfs(s,t))ret+=dfs(s,t,INT_MAX);
	return ret;
}

}
int n,m;
vector<pair<int,int> > adj[maxn];
int dep[maxn],fa[maxn],dfn[maxn],idx[maxn],top[maxn],sz[maxn],hvs[maxn],c1;
int fai[maxn];
void dfs1(int u){
	sz[u]=1;
	for(int i=0;i<(int)adj[u].size();i++){
		int v=adj[u][i].first;
		if(!sz[v]){
			fai[v]=adj[u][i].second;
			dep[v]=dep[u]+1;
			fa[v]=u;
			dfs1(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[hvs[u]])hvs[u]=v;
		}
	}
}
void dfs2(int u){
	dfn[u]=++c1;idx[c1]=u;
	if(hvs[u]){
		top[hvs[u]]=top[u];
		dfs2(hvs[u]);
	}
	for(int i=0;i<(int)adj[u].size();i++){
		int v=adj[u][i].first;
		if(v!=hvs[u]&&fa[v]==u){
			top[v]=v;
			dfs2(v);
		}
	}
}
int ps;
int ch[maxn*2][2];
int bt(int l,int r){
	if(l==r)return l;
	else{
		int rt=++ps;
		int m=(l+r)/2;
		ch[rt][0]=bt(l,m);
		ch[rt][1]=bt(m+1,r);
		fl::ae(rt,ch[rt][0],INT_MAX);
		fl::ae(rt,ch[rt][1],INT_MAX);
		return rt;
	}
}
int sp,rt;
void sae(int rt,int cl,int cr,int l,int r,int st){
	int cm=(cl+cr)/2;
	if(l==cl&&r==cr)fl::ae(st,rt,1);
	else if(r<=cm)sae(ch[rt][0],cl,cm,l,r,st);
	else if(l>cm)sae(ch[rt][1],cm+1,cr,l,r,st);
	else sae(ch[rt][0],cl,cm,l,cm,st),sae(ch[rt][1],cm+1,cr,cm+1,r,st);
}

void ate(int st,int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		fl::ae(st,dfn[u]+sp,1);
		u=fa[top[u]];
	}
	if(dfn[u]>dfn[v])swap(u,v);
	if(dfn[u]<dfn[v])sae(rt,1,n,dfn[u]+1,dfn[v],st);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adj[u].push_back(make_pair(v,i));adj[v].push_back(make_pair(u,i));
	}
	dep[1]=1;dfs1(1);
	top[1]=1;dfs2(1);
	//for(int i=1;i<=n;i++)cerr<<dfn[i]<<endl;
	ps=n;
	rt=bt(1,n);
	sp=ps;
	for(int i=1;i<=n;i++){
		++ps;
		fl::ae(ps,i,INT_MAX);
	}
	for(int i=1;i<=n;i++){
		if(top[i]!=i){
			fl::ae(sp+dfn[i],sp+dfn[fa[i]],INT_MAX);
		}
	}
	int s=ps+m+1,t=ps+m+2;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		++ps;
		fl::ae(s,ps,1);
		ate(ps,x,y);
	}
	for(int i=2;i<=n;i++)fl::ae(i,t,1);
	fl::n=t;
	printf("%d\n",fl::mxfl(s,t));
	vector<int> v[2];
	for(int i=1;i<=m;i++){
		int id=ps-m+i;
		if(fl::dis[id]==-1)v[0].push_back(i);
	}
	for(int i=2;i<=n;i++){
		if(fl::dis[i]!=-1)v[1].push_back(fai[idx[i]]);
	}
	for(int t=0;t<2;t++){
		printf("%d",(int)v[t].size());
		for(int i=0;i<(int)v[t].size();i++)printf(" %d",v[t][i]);
		printf("\n");
	}
	return 0;
}