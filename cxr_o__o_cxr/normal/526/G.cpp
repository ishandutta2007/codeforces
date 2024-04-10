//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4,inf=0x3f3f3f3f;
struct edge{
	int v,w,nxt;
}e[N<<1];
int first[N],cnt;
inline void add(int u,int v,int w){
	e[++cnt]=(edge){v,w,first[u]};first[u]=cnt;
}
int n,Q,sumw,leaf,d[N],deg[N];
queue<int>q;
inline int findfar(int st){
	memset(d,0x3f,sizeof(d));
	d[st]=0;
	q.push(st);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=first[x],v;i;i=e[i].nxt){
			v=e[i].v;
			if(d[v]!=inf)continue;
			d[v]=d[x]+e[i].w;
			q.push(v);
		}
	}
	st=1;
	for(int i=2;i<=n;i++)if(d[i]>d[st])st=i;
	return st;
}
struct tree{
	int rt,dep[N],d[N],mxd[N],fa[N][20],son[N],tmp[N],top[N],ans[N],dfn[N];
	void dfs(int x){
		dep[x]=dep[fa[x][0]]+1;
		for(int i=1;(1ll<<i)<=dep[x];i++)
			fa[x][i]=fa[fa[x][i-1]][i-1];
		for(int i=first[x],v;i;i=e[i].nxt){
			v=e[i].v;
			if(v==fa[x][0])continue;
			fa[v][0]=x;
			mxd[v]=d[v]=d[x]+e[i].w;
			dfs(v);
			if(mxd[v]>mxd[x]){mxd[x]=mxd[v];son[x]=v;}
		}
		for(int i=first[x],v;i;i=e[i].nxt){
			v=e[i].v;
			if(v==fa[x][0]||v==son[x])continue;
			tmp[++tmp[0]]=v;
		}
	}
	inline void prepare(){
		dfs(rt);
		tmp[++tmp[0]]=rt;
		sort(tmp+1,tmp+tmp[0]+1,[&](int x,int y){
			return mxd[x]-d[fa[x][0]]>mxd[y]-d[fa[y][0]];
		});
		for(int i=1,p;i<=tmp[0];i++){
			ans[i]=ans[i-1]+mxd[tmp[i]]-d[fa[tmp[i]][0]];
			p=tmp[i];
			while(p){
				top[p]=tmp[i];dfn[p]=i;
				p=son[p];
			}
		}
//		for(int i=1;i<=n;i++)cerr<<dfn[i]<<" ";cerr<<"\n";
	}
	inline int query(int x,int y){
		if(dfn[x]<=y)return ans[y];
		int u=x,ret;
		for(int i=19;i>=0;i--)
			if(dfn[fa[u][i]]>y)u=fa[u][i];
		ret=ans[y]-mxd[fa[u][0]]+d[fa[u][0]]+mxd[x]-d[fa[u][0]];
		u=x;
		for(int i=19;i>=0;i--)
			if(dfn[fa[u][i]]>=y)u=fa[u][i];
		ret=max(ret,ans[y-1]+mxd[x]-d[fa[u][0]]);
		return ret;
	}
}t[2];
int main(){
	n=read();Q=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read();v=read();w=read();
		add(u,v,w);add(v,u,w);
		sumw+=w;
		deg[u]++;deg[v]++;
	}
	for(int i=1;i<=n;i++)if(deg[i]==1)leaf++;
	t[0].rt=findfar(1);t[1].rt=findfar(t[0].rt);
//	cerr<<t[0].rt<<" "<<t[1].rt<<"\n";
	t[0].prepare();t[1].prepare();
	for(int x,y,las=0;Q--;){
		x=(read()+las-1)%n+1;y=(read()+las-1)%n+1;
//		cerr<<x<<" "<<y<<" query\n";
		las=(2*y>=leaf)?sumw:max(t[0].query(x,(y<<1)-1),t[1].query(x,(y<<1)-1));
		cout<<las<<"\n";
	}
	return (0-0);
}