#include<bits/stdc++.h>

using namespace std;

const int maxn=500005;

struct node{
	long long mi,tg;
	int l,r;
	node* c[2];
};

node pool[maxn<<2];
int ps;
long long dis[maxn];

node* nwnode(int l,int r){
	node* nw=pool+ps++;
	nw->l=l;nw->r=r;nw->mi=0x3f3fff3fff3fff;nw->tg=0;nw->c[0]=nw->c[1]=NULL;
	return nw; 
}

void pd(node* rt){
	if(rt){
		if(rt->tg){
			rt->mi+=rt->tg;
			if(rt->l!=rt->r){
				rt->c[0]->tg+=rt->tg;
				rt->c[1]->tg+=rt->tg;
			}
			rt->tg=0;
		}
	}
}
void pu(node* rt){
	if(rt->l!=rt->r){
		rt->mi=min(rt->c[0]->mi,rt->c[1]->mi);
	}
}

node* bt(int l,int r){
	node* nw=nwnode(l,r);
	if(l!=r){
		nw->c[0]=bt(l,(l+r)>>1);
		nw->c[1]=bt(((l+r)>>1)+1,r);
		pu(nw);
	}else{
		nw->mi=dis[l];
	}
	return nw;
}

void chg(node* rt,int l,int r,long long v){
	int cl=rt->l,cr=rt->r,cm=(cl+cr)>>1;
	pd(rt);
	if(cl==l&&cr==r){
		rt->tg+=v;
		pd(rt);
	}else if(r<=cm)chg(rt->c[0],l,r,v);
	else if(l>cm)chg(rt->c[1],l,r,v);
	else{chg(rt->c[0],l,cm,v);chg(rt->c[1],cm+1,r,v);}
	pd(rt->c[0]);pd(rt->c[1]);pu(rt);
}

long long qry(node* rt,int l,int r){
	int cl=rt->l,cr=rt->r,cm=(cl+cr)>>1;
	pd(rt);
	if(cl==l&&cr==r)return rt->mi;
	else if(r<=cm)return qry(rt->c[0],l,r);
	else if(l>cm)return qry(rt->c[1],l,r);
	else return min(qry(rt->c[0],l,cm),qry(rt->c[1],cm+1,r));
}

struct qrs{
	int i,x,l,r;
};
int n,q;
long long ans[maxn];
vector<qrs> qv[maxn];
vector<pair<int,int> > adj[maxn];
int dfx[maxn];
void dfs1(int u,long long d){
	if(adj[u].size()!=0){
		dis[u]=0x3f3fff3fff3fff;
	}else{
		dis[u]=d;
	}
	dfx[u]=u;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first,w=adj[u][i].second;
		dfs1(v,d+w);
		dfx[u]=max(dfx[u],dfx[v]);
	}
}

node* rt;
void dfs2(int u){
	for(int i=0;i<qv[u].size();i++){
		ans[qv[u][i].i]=qry(rt,qv[u][i].l,qv[u][i].r);
	}
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first,w=adj[u][i].second;
		int cl=v,cr=dfx[v];
		if(cl!=1)chg(rt,1,cl-1,w);
		if(cr!=n)chg(rt,cr+1,n,w);
		chg(rt,cl,cr,-w);
		dfs2(v);
		if(cl!=1)chg(rt,1,cl-1,-w);
		if(cr!=n)chg(rt,cr+1,n,-w);
		chg(rt,cl,cr,w);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int p,w;cin>>p>>w;
		adj[p].push_back(make_pair(i,w));
	}
	dfs1(1,0);
	rt=bt(1,n);
	for(int i=1;i<=q;i++){
		qrs nw;
		cin>>nw.x>>nw.l>>nw.r;nw.i=i;
		qv[nw.x].push_back(nw);
	}
	dfs2(1);
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}