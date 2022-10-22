#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10;

bool be;


int n,m;
struct Edge{
	int to,nxt;
} e[N];
int head[N],ecnt;
void AddEdge(int u,int v){
	e[++ecnt]=(Edge){v,head[u]};
	head[u]=ecnt;
}
#define erep(u,i) for(reg int i=head[u];i;i=e[i].nxt)

int fa[N],dep[N],top[N],sz[N],son[N],L[N],R[N],dfn,id[N];

namespace pt30{
	int mk[N];
	void dfs_mark(int u) {
		if(!mk[u]) return (void)(mk[u]=1);
		erep(u,i) {
			int v=e[i].to;
			dfs_mark(v);
		}
	}
	void dfs_clear(int u) {
		mk[u]=0;
		erep(u,i) {
			int v=e[i].to;
			dfs_clear(v);
		}
	}
	void Solve(){
		rep(i,1,m) {
			int opt=rd();
			if(opt==1) dfs_mark(rd());
			else if(opt==2) dfs_clear(rd());
			else puts(mk[rd()]?"Yes":"No");
		}
	}
}

int opt[N<<1],optx[N<<1];

void dfs1(int u){
	sz[u]=1;
	erep(u,i) {
		int v=e[i].to;
		dfs1(v);
		if(sz[v]>sz[son[u]]) son[u]=v;
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int t){
	id[L[u]=++dfn]=u;
	top[u]=t;
	if(son[u]) dfs2(son[u],t);
	erep(u,i) {
		int v=e[i].to;
		if(v==son[u]) continue;
		dfs2(v,v);
	}
	R[u]=dfn;
}



struct Node{
	int s,ma;
	Node operator + (const Node x){ return (Node){s+x.s,max(ma+x.s,x.ma)}; }
} tr[N<<2];
int t[N<<2];
void Down(int p){
	if(!t[p]) return;
	t[p<<1]=1,t[p<<1|1]=1;
	tr[p<<1].s=0,tr[p<<1].ma=0;
	tr[p<<1|1].s=0,tr[p<<1|1].ma=0;
	t[p]=0;
}

void Upd(int p,int l,int r,int x,int y) {
	if(l==r) {
		tr[p]=(Node){y,y+dep[id[l]]};
		return;
	}
	Down(p);
	int mid=(l+r)>>1;
	x<=mid?Upd(p<<1,l,mid,x,y):Upd(p<<1|1,mid+1,r,x,y);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
void Set(int p,int l,int r,int ql,int qr) {
	if(ql==l&&qr==r) {
		t[p]=1;
		tr[p].ma=tr[p].s=0;
		return;
	}
	Down(p);
	int mid=(l+r)>>1;
	if(qr<=mid) Set(p<<1,l,mid,ql,qr);
	else if(ql>mid) Set(p<<1|1,mid+1,r,ql,qr);
	else Set(p<<1,l,mid,ql,mid),Set(p<<1|1,mid+1,r,mid+1,qr);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}

Node Que(int p,int l,int r,int ql,int qr) {
	if(ql==l&&qr==r) return tr[p];
	int mid=(l+r)>>1;
	Down(p);
	if(qr<=mid) return Que(p<<1,l,mid,ql,qr);		
	if(ql>mid) return Que(p<<1|1,mid+1,r,ql,qr);
	return Que(p<<1,l,mid,ql,mid)+Que(p<<1|1,mid+1,r,mid+1,qr);
}

int Quemax(int x){
	Node res=(Node){0,0};
	while(x) res=Que(1,1,n,L[top[x]],L[x])+res,x=fa[top[x]];
	return res.ma;
}


bool ed;

int main(){
//	printf("%.2lf\n",(&ed-&be)/1024.0/1024.0);
	//freopen("plague.in","r",stdin),freopen("plague.out","w",stdout);
	n=rd(),m=rd();
	rep(i,2,n) AddEdge(fa[i]=rd(),i),dep[i]=dep[fa[i]]+1;
    rep(i,1,m) opt[i]=rd(),optx[i]=rd();
	dfs1(1),dfs2(1,1);
	rep(i,1,m) {
		if(opt[i]==1) {
			int t=Que(1,1,n,L[optx[i]],L[optx[i]]).s;
			Upd(1,1,n,L[optx[i]],t+1);
		} else if(opt[i]==3) {
//			cout<<"#"<<Quemax(optx[i])<<endl;
			puts(Quemax(optx[i])>=dep[optx[i]]+1?"black":"white");
		}
	 	else if(opt[i]==2) {
			int x=optx[i];
			Set(1,1,n,L[x],R[x]);
			int t=Quemax(x);
//			cout<<"#"<<t<<endl;
			if(t>=dep[x]+1) Upd(1,1,n,L[x],dep[x]-t);
		}
	}
	fclose(stdin),fclose(stdout);
	return 0;
}