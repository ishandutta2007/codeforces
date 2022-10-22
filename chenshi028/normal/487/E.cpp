#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
#include<set>
using namespace std;
const int o=5e5+10,inf=1e9;
int n,m,q,h[o],w[o],s[o],fa[o],hs[o],dfn[o],low[o],nfd[o],tp[o],d[o],bccn,cnt,val[o*4];
char c;stack<int> S;vector<int> E[o];multiset<int> se[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void tarjan(int nw){
	dfn[nw]=low[nw]=++cnt;S.push(nw);
	for(int i=h[nw];i;i=e[i].p)
		if(!dfn[e[i].v]){
			tarjan(e[i].v);low[nw]=min(low[nw],low[e[i].v]);
			if(low[e[i].v]>=dfn[nw]){
				for(++bccn;S.top()^e[i].v;S.pop()) E[bccn].push_back(S.top()),E[S.top()].push_back(bccn);
				E[bccn].push_back(e[i].v);E[e[i].v].push_back(bccn);S.pop();
				E[bccn].push_back(nw);E[nw].push_back(bccn);
			}
		}
		else low[nw]=min(low[nw],dfn[e[i].v]);
}
void dfs(int nw){
	s[nw]=1;
	for(int i=0,j,sz=E[nw].size();i<sz;++i) if(E[nw][i]^fa[nw]){
		fa[j=E[nw][i]]=nw;d[j]=d[nw]+1;dfs(j);s[nw]+=s[j];hs[nw]=(s[hs[nw]]>s[j]?hs[nw]:j);
		if(nw>n) se[nw].insert(w[j]);
	}
	if(nw>n) w[nw]=(se[nw].empty()?inf:*se[nw].begin());
}
void Dfs(int nw,int ld){
	nfd[dfn[nw]=++cnt]=nw;tp[nw]=ld;
	if(hs[nw]) Dfs(hs[nw],ld);
	for(int i=0,j=E[nw].size();i<j;++i)
		if(E[nw][i]-hs[nw]&&E[nw][i]-fa[nw]) Dfs(E[nw][i],E[nw][i]);
}
void build(int id,int l,int r){
	if(l==r){val[id]=w[nfd[l]];return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	val[id]=min(val[id<<1],val[(id<<1)|1]);
}
void modify(int id,int pos,int vl,int l=1,int r=bccn){
	if(l==r){val[id]=vl;return;}
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,vl,l,md);
	else modify((id<<1)|1,pos,vl,md+1,r);
	val[id]=min(val[id<<1],val[(id<<1)|1]);
}
int query(int id,int ql,int qr,int l=1,int r=bccn){
	if(ql<=l&&r<=qr) return val[id];
	int md=l+r>>1;
	return min((ql<=md?query(id<<1,ql,qr,l,md):inf),(md<qr?query((id<<1)|1,ql,qr,md+1,r):inf));
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i) scanf("%d",&w[i]);
	for(int i,j;m--;) scanf("%d%d",&i,&j),ad(i,j),ad(j,i);
	cnt=0;bccn=n;tarjan(1);
	dfs(d[1]=1);cnt=0;Dfs(1,1);
	build(1,1,bccn); 
	for(int x,y,ans;q--;){
		for(c=getchar();c<'A'||c>'Z';c=getchar());
		scanf("%d%d",&x,&y);
		if(c=='C')
			if(x>1)
				se[fa[x]].erase(se[fa[x]].find(w[x])),se[fa[x]].insert(w[x]=y),
				modify(1,dfn[fa[x]],w[fa[x]]=*se[fa[x]].begin()),modify(1,dfn[x],w[x]);
			else modify(1,dfn[1],w[1]=y);
		else{
			for(ans=inf;tp[x]^tp[y];)
				if(d[tp[x]]>d[tp[y]]) ans=min(ans,query(1,dfn[tp[x]],dfn[x])),x=fa[tp[x]];
				else ans=min(ans,query(1,dfn[tp[y]],dfn[y])),y=fa[tp[y]];
			if(d[x]>d[y]) swap(x,y);
			ans=min(ans,query(1,dfn[x],dfn[y]));
			if(x>n) ans=min(ans,w[fa[x]]);
			printf("%d\n",ans);
		}
	}
	return 0;
}