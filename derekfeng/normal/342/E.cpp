#include<bits/stdc++.h>
using namespace std;
struct node{
	int rt,dep;
	node(int rt,int dep):rt(rt),dep(dep){}
};
vector<node>dt[100004];
int tr[100004];
int n,q,L[100004];
vector<int>g[100004];
int N,sz[100004];
bool used[100004];
void init(int x,int fa){
	sz[x]=1;
	for(auto y:g[x])if(y!=fa&&!used[y])
		init(y,x),sz[x]+=sz[y];
}
int findrt(int x,int fa){
	int tmp=N-sz[x];
	for(auto y:g[x])if(y!=fa&&!used[y]){
		int z=findrt(y,x);
		if(z!=-1)return z;
		tmp=max(tmp,sz[y]);
	}
	return tmp<=N/2?x:-1;
}
int getDep(int x,int fa){
	int nL=0;
	for(auto y:g[x])if(y!=fa&&!used[y])
		nL=max(nL,getDep(y,x)+1);
	return nL;
}
void gettr(int x,int fa,int rt,int dep){
	dt[x].push_back(node(rt,dep));
	for(auto y:g[x])if(y!=fa&&!used[y])
		gettr(y,x,rt,dep+1);
}
void built(int x){
	init(x,0),N=sz[x],x=findrt(x,0);
	L[x]=0;
	dt[x].push_back(node(x,0));
	for(auto y:g[x])if(!used[y]){
		int nL=getDep(y,x)+1;
		L[x]=max(L[x],nL);
	}
	tr[x]=1e9;
	used[x]=1;
	int num=0;
	for(auto y:g[x])if(!used[y]){
		gettr(y,x,x,1);
		built(y);
	}
}
void upd(int x){
	for(int i=0;i<dt[x].size();i++){
		int rt=dt[x][i].rt,dep=dt[x][i].dep;
		tr[rt]=min(tr[rt],dep);
	}
}
int qry(int x){
	int res=1e9;
	for(int i=0;i<dt[x].size();i++){
		int rt=dt[x][i].rt,dep=dt[x][i].dep;
		res=min(res,dep+tr[rt]);
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	built(1);
	upd(1);
	while(q--){
		int op,x;scanf("%d%d",&op,&x);
		switch(op){
			case 1:upd(x);break;
			case 2:printf("%d\n",qry(x));
		}
	}
}