#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=150005;
namespace bit{
	int c[N];
	void upd(int x,int y){
		for(;x;x-=x&-x) c[x]+=y;
	}
	int qry(int x){
		int res=0;
		for(;x<N;x+=x&-x) res+=c[x];
		return res;
	}
}
namespace seg{
	struct node{ int s,lc,rc; } T[N*233]; int sz;
	void ins(int &o,int l,int r,int x,int y){
		if(!o) o=++sz;
		if(l==x&&y==r) return (void)(T[o].s++);
		if(x<=mid) ins(T[o].lc,l,mid,x,min(y,mid));
		if(mid<y) ins(T[o].rc,mid+1,r,max(mid+1,x),y);
	}
	int qry(int o,int l,int r,int x){
		if(!o||l==r) return T[o].s;
		if(x<=mid) return T[o].s+qry(T[o].lc,l,mid,x);
		return T[o].s+qry(T[o].rc,mid+1,r,x);
	}
	void merge(int &x,int y,int l,int r){
		if(!x||!y) { if(!x) x=y; return; }
		merge(T[x].lc,T[y].lc,l,mid);
		merge(T[x].rc,T[y].rc,mid+1,r);
		T[x].s+=T[y].s;
	}
}
int anc[N],in[N],out[N],cur[N];
int d[N],sz[N],sn[N],fa[N];
int x[N],y[N],z[N],rt[N];
vi e[N],id[N],q[N],pt[N];
map<int,int> owo[N];
map<pii,int> ex[N];
int n,m,K,clk;
ll ans;

void dfs1(int u){
	sz[u]=1;
	for(auto v:e[u]){
		if(v==fa[u]) continue;
		fa[v]=u,d[v]=d[u]+1;
		dfs1(v),sz[u]+=sz[v];
		if(sz[v]>sz[sn[u]]) sn[u]=v;
	}
}
void dfs2(int u,int top){
	anc[u]=top;
	cur[in[u]=++clk]=u;
	if(sn[u]) dfs2(sn[u],top);
	for(auto v:e[u])
		if(v!=fa[u]&&v!=sn[u]) dfs2(v,v);
	out[u]=clk;
}
int lca(int x,int y){
	for(;anc[x]^anc[y];x=fa[anc[x]])
		if(d[anc[x]]<d[anc[y]]) swap(x,y);
	return d[x]<d[y]?x:y;
}
int Kth(int x,int k){
	for(;d[x]-d[anc[x]]<k;x=fa[anc[x]])
		k-=d[x]-d[anc[x]]+1;
	return cur[in[x]-k];
}
int disK(int x,int y){
	int z=lca(x,y);
	int len=d[x]+d[y]-2*d[z];
	if(len<K) return -1;
	if(d[x]-d[z]>=K) return Kth(x,K);
	return Kth(y,len-K);
}
void insLine(int &rt,int x,int y){
	for(;anc[x]^anc[y];x=fa[anc[x]]){
		if(d[anc[x]]<d[anc[y]]) swap(x,y);
		seg::ins(rt,1,n,in[anc[x]],in[x]);
	}
	if(d[x]<d[y]) seg::ins(rt,1,n,in[x],in[y]);
	else seg::ins(rt,1,n,in[y],in[x]);
}

void solve(int u){
	for(auto k:id[u]){
		int v=(x[k]==u?y[k]:x[k]);
		int ret=disK(u,v);
		if(ret==-1) continue;
		if(z[k]!=u) ans+=seg::qry(rt[u],1,n,in[ret]);
		insLine(rt[u],u,v);
		if(d[u]-d[z[k]]>=K){
			ans+=owo[u][z[k]];
			if(v!=z[k]) ans-=ex[u][mp(z[k],Kth(v,d[v]-d[z[k]]-1))];
		}
		owo[u][z[k]]++;
		if(v!=z[k]) ex[u][mp(z[k],Kth(v,d[v]-d[z[k]]-1))]++;
	}
	pt[u].pb(u);
	for(auto v:e[u]){
		if(v==fa[u]) continue;
		solve(v);
		if(pt[v].size()>pt[u].size()){
			swap(pt[u],pt[v]),swap(rt[u],rt[v]);
			swap(owo[u],owo[v]),swap(ex[u],ex[v]);
		}
		for(auto t:pt[v]){
			for(auto k:id[t]){
				if(d[z[k]]>=d[u]) continue;
				int v=(x[k]==t?y[k]:x[k]),ret=disK(u,v);
//				printf("# %d  %d  %d  %d  %d  res=%d\n",u,t,k,v,ret,
//				ret==-1?0:seg::qry(rt[u],1,n,in[ret]));
				if(ret!=-1) ans+=seg::qry(rt[u],1,n,in[ret]);
				if(d[u]-d[z[k]]>=K){
					ans+=owo[u][z[k]];
//					printf("@ %d %d %d\n",u,k,owo[u][z[k]]);
					if(v!=z[k]) ans-=ex[u][mp(z[k],Kth(v,d[v]-d[z[k]]-1))];
				}
			}
			pt[u].pb(t);
		}
		pt[v].clear();
		for(auto t:owo[v]) owo[u][t.fi]+=t.se;
		for(auto t:ex[v]) ex[u][t.fi]+=t.se;
		seg::merge(rt[u],rt[v],1,n);
	}
}

int main(){
	read(n),read(m),read(K);
	rep(i,1,n-1){
		int a,b;
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	d[1]=1,dfs1(1),dfs2(1,1);
	rep(i,1,m){
		read(x[i]),read(y[i]);
		z[i]=lca(x[i],y[i]);
		id[x[i]].pb(i);
		id[y[i]].pb(i);
		q[d[z[i]]].pb(i);
	}
	per(i,n,1){
		for(auto k:q[i]){
			ans+=bit::qry(in[x[k]]);
			ans+=bit::qry(in[y[k]]);
			ans-=bit::qry(in[z[k]]);
			if(z[k]!=1) ans-=bit::qry(in[fa[z[k]]]);
		}
		for(auto k:q[i]){
			int aim=d[z[k]]+K;
			if(d[x[k]]>=aim){
				int t=Kth(x[k],d[x[k]]-aim);
				bit::upd(out[t],1),bit::upd(in[t]-1,-1);
			}
			if(d[y[k]]>=aim){
				int t=Kth(y[k],d[y[k]]-aim);
				bit::upd(out[t],1),bit::upd(in[t]-1,-1);
			}
		}
	}
	solve(1);
	cout<<ans/2<<endl;
	return 0;
}