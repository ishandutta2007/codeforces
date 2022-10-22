#include<bits/stdc++.h>
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5e5+5;
const int M=2.5e7+5;
int n,m,k,q;
inline int id(int co,int i){
	return (co-1)*n+i;
}
int fa[M],sz[M];
bool w[M];
stack<int> stk;
vector<pii> e[N*3];
void chg(int p,int l,int r,int cl,int cr,pii c){
	if(l>r) return; 
	if(l==cl&&r==cr){
		e[p].push_back(c);
		return;
	}
	int mid=cl+cr>>1;
	if(r<=mid) chg(ls(p),l,r,cl,mid,c);
	else if(l>mid) chg(rs(p),l,r,mid+1,cr,c);
	else{
		chg(ls(p),l,mid,cl,mid,c);
		chg(rs(p),mid+1,r,mid+1,cr,c);
	}
}
int getrt(int u){
	if(fa[u]==u) return u;
	return getrt(fa[u]);
}
int getw(int u){
	if(fa[u]==u) return 0;
	return getw(fa[u])^w[u];
}
inline bool merge(int u,int v){
	bool f=getw(u)^getw(v)^1;
	u=getrt(u);v=getrt(v);
	if(u==v) return f^1;
	if(sz[v]<sz[u]) swap(u,v);
	stk.push(u);
	fa[u]=v;
	w[u]=f;
	sz[v]+=sz[u];
	return 1;
}
inline void reset(){
	int u=stk.top();stk.pop();
	sz[fa[u]]-=sz[u];w[u]=0;fa[u]=u;
}
int u[N],v[N],x[N],co[N],nxt[N],pos[N];
void dfs(int p,int cl,int cr){
	int csz=stk.size();
	for(int i=0;i<e[p].size();i++){
		pii c=e[p][i];merge(c.first,c.second);
	}
	if(cl==cr){
		int U=id(co[cl],u[x[cl]]),V=id(co[cl],v[x[cl]]);
		bool val=merge(U,V);
		if(val){
			puts("YES");
			pos[x[cl]]=co[cl];
			chg(1,cl+1,nxt[cl]-1,1,q,{U,V});
		}
		else{
			puts("NO");
			if(pos[x[cl]]){
				U=id(pos[x[cl]],u[x[cl]]),V=id(pos[x[cl]],v[x[cl]]);
				val=merge(U,V);
				chg(1,cl+1,nxt[cl]-1,1,q,{U,V});				
			}
		}
	}
	else{
		int mid=cl+cr>>1;
		dfs(ls(p),cl,mid);
		dfs(rs(p),mid+1,cr);		
	}
	while(stk.size()>csz)
		reset();
}
int main(){
	int i,j;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	for(i=1;i<=q;i++) scanf("%d%d",&x[i],&co[i]);
	for(i=1;i<M;i++) fa[i]=i,sz[i]=1;
	for(i=1;i<=m;i++) pos[i]=q+1;
	for(i=q;i;i--){
		nxt[i]=pos[x[i]];
		pos[x[i]]=i;
	}
	for(i=1;i<=m;i++) pos[i]=0;
	dfs(1,1,q);
	return 0;
}