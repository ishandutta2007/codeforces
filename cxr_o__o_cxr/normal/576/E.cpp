//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,fl=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')fl=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return fl==1?x:-x;
}
const int N=5e5+4;
int n,m,k,Q,uu[N],vv[N],ee[N],cc[N],col[N],nxt[N],pre[N];
vector<pair<int,int> >t[N<<2];
struct DSU{
	int fa[N],siz[N],dis[N],st[N],top;
	inline void clear(){
		for(int i=1;i<=n;i++){fa[i]=i;siz[i]=1;}
	}
	inline int find(int x,int &d){
		if(x==fa[x]){d=0;return x;}
		static int ret;
		ret=find(fa[x],d);
		d^=dis[x];
		return ret;
	}
	inline bool check(int u,int v){
		static int du,dv;
		u=find(u,du);v=find(v,dv);
		if(u==v&&du==dv)return 0;
		return 1;
	}
	inline bool merge(int u,int v){
		static int du,dv;
		u=find(u,du);v=find(v,dv);
		if(u==v)return 0;
		if(siz[u]<siz[v])u^=v^=u^=v;
		st[++top]=v;
		siz[u]+=siz[v];
		fa[v]=u;
		dis[v]=du^dv^1; 
		return 1;
	}
	inline void back(){
		static int v;
		v=st[top--];
		siz[fa[v]]-=siz[v];
		fa[v]=v;dis[v]=0;
	}
}dsu[52];
#define lc (p<<1)
#define rc (p<<1|1)
#define fi first
#define se second
void modify(int p,int l,int r,int ql,int qr,int e,int v){
	if(ql<=l&&r<=qr){
		t[p].push_back(make_pair(e,v));
		return;
	}
	int mid=l+r>>1;
	if(ql<=mid)modify(lc,l,mid,ql,qr,e,v);
	if(mid<qr)modify(rc,mid+1,r,ql,qr,e,v);
}
void solve(int p,int l,int r){
	for(auto &v:t[p]){
		v.fi=dsu[v.se].merge(uu[v.fi],vv[v.fi]);
	}
	if(l==r){
		/*if(l==4){
			int d;
			dsu[cc[l]].find(1,d);cerr<<d<<" ";
			dsu[cc[l]].find(2,d);cerr<<d<<" ";
			dsu[cc[l]].find(3,d);cerr<<d<<" check\n";
		}*/
		if(dsu[cc[l]].check(uu[ee[l]],vv[ee[l]])){
			puts("YES");
			col[ee[l]]=cc[l];
		}
		else puts("NO");
		if(l+1<=nxt[l]-1&&col[ee[l]])modify(1,1,Q,l+1,nxt[l]-1,ee[l],col[ee[l]]);
	}
	else{
		int mid=l+r>>1;
		solve(lc,l,mid);solve(rc,mid+1,r);
	}
	for(auto &v:t[p]){
		if(v.fi)dsu[v.se].back();
	}
}
int main(){
	n=read();m=read();k=read();Q=read();
	for(int i=1;i<=k;i++)dsu[i].clear();
	for(int i=1;i<=m;i++){uu[i]=read();vv[i]=read();}
	for(int i=1;i<=Q;i++){
		ee[i]=read();cc[i]=read();
		nxt[pre[ee[i]]]=i;pre[ee[i]]=i;nxt[i]=Q+1;
	}
	solve(1,1,Q);
	return (0-0);
}