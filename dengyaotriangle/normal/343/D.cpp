#include<bits/stdc++.h>

using namespace std;

const int maxn=500005;

struct node{
	int v,l,r,lt;
	node* c[2]; 
};

node pool[maxn*4];
int n,q,ps;
int dep[maxn],top[maxn],dfn[maxn],hvs[maxn],fa[maxn],sze[maxn],otn[maxn],c0;
vector<int> adj[maxn];
node* rt;

node* nwnode(int l,int r){
	node* nw=pool+ps++;
	nw->l=l;nw->r=r;nw->v=0;nw->lt=-1;nw->c[0]=nw->c[1]=NULL;
	return nw;
}

void pd(node* rt){
	if(rt->lt!=-1){
		if(rt->l!=rt->r ){
			rt->c[0]->lt=rt->c[1]->lt=rt->lt; 
		}else{
			rt->v=rt->lt;
		}
		rt->lt=-1;
	}
}

node* bt(int l,int r){
	node* nw=nwnode(l,r );
	if(l!=r){
		nw->c[0]=bt(l,(l+r)/2);
		nw->c[1]=bt((l+r)/2+1,r);
	} 
	return nw;
}

void cg(node* rt,int l,int r,int v){
	int cl=rt->l,cr=rt->r,cm=(cl+cr)/2;
	if(l==cl&&r==cr){
		rt->lt=v;
		pd(rt);
		return ;	
	} 
	pd(rt); 
	if(r<=cm) cg(rt->c[0],l,r,v);
	else if(l>cm) cg(rt->c[1],l,r,v);
	else {
		cg(rt->c[0],l,cm,v);
		cg(rt->c[1],cm+1,r,v);
	}
}

int qry(node* rt,int i){
	int cl=rt->l,cr=rt->r,cm=(cl+cr)/2;
	pd(rt);
	if(cl==cr) return rt->v;
	else if(i<=cm) return qry(rt->c[0],i);
	else return qry(rt->c[1],i);
}
int dfs1(int u){
	int hs=0,hi=0;
	sze[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(dep[v]==0){
			dep[v]=dep[u]+1;
			fa[v]=u;
			int cs=dfs1(v);
			if(cs>hs){
				hs=cs;
				hi=v;
			}
			sze[u]+=cs;
		}
	}
	hvs[u]=hi;
	return sze[u];
}

void dfs2(int u){
	dfn[u]=++c0;
	if(hvs[u]){
		top[hvs[u]]=top[u];
		dfs2(hvs[u]);
	}
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(dep[v]==dep[u]+1&&v!=hvs[u]){
			top[v]=v;
			dfs2(v);
		}
	}
	otn[u]=c0;
}

int qru(int u){
	return qry(rt,dfn[u]);
}
void cgt(int x){
	cg(rt,dfn[x],otn[x],1);
}
void cgc(int x){
	while(top[x]!=1){
		cg(rt,dfn[top[x]],dfn[x],0);
		x=fa[top[x]];
	}
	cg(rt,1,dfn[x],0); 
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dep[1]=1;
	dfs1(1);
	top[1]=1;
	dfs2(1);
	cin>>q;
	rt=bt(1,n);
	while(q--){
		int o,x;
		scanf("%d%d",&o,&x);
		if(o==1){
			cgt(x);
		}else if(o==2){
			cgc(x);
		}else{
			printf("%d\n",qru(x));
		}
	} 
	return 0;
}