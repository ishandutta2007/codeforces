#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
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

typedef pair<pii,pii> node;

const int N=(1<<20)+5;
int cur[N],in[N],out[N],rev[N],owo[N],col[N],n,Q,x,y;
vector<pii> e[N];

namespace tree{
	int d[N],in[N],out[N];
	int mn[N][21],lg[N],clk,clk2;
	
	int Min(int x,int y){
		return d[x]<d[y]?x:y;
	}
	void dfs1(int u,int fa){
		d[u]=d[fa]+1;
		mn[in[u]=++clk][0]=u;
		::rev[::in[u]=++clk2]=u;
		for(auto v:e[u]){
			if(v.fi==fa) continue;
			cur[v.se]=v.fi;
			col[v.fi]=col[u]^owo[v.se];
			dfs1(v.fi,u);
			mn[++clk][0]=u;
		}
		out[u]=clk;
		::out[u]=clk2;
	}
	void init(){
		dfs1(1,0);
		lg[0]=-1;
		rep(i,1,clk){
			lg[i]=lg[i>>1]+1;
		}
		per(i,clk,1){
			for(int j=1;i+(1<<j)-1<=clk;j++){
				mn[i][j]=Min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int lca(int x,int y){
		x=in[x],y=in[y];
		if(x>y) swap(x,y);
		int t=lg[y-x+1];
		return Min(mn[x][t],mn[y-(1<<t)+1][t]);
	}
	int dist(int x,int y){
		if(!x||!y) return -1;
		return d[x]+d[y]-2*d[lca(x,y)];
	}
	void upd(pii &res,int x){
		int mx=dist(res.fi,res.se);
		int t1=dist(res.fi,x);
		int t2=dist(res.se,x);
		if(t1>=mx&&t1>=t2) res.se=x;
		else if(t2>=mx) res.fi=x;
	}
	pii merge(pii a,pii b){
		pii res=a;
		if(!res.fi) res=b;
		if(b.fi) upd(res,b.fi);
		if(b.se) upd(res,b.se);
		return res;
	}
}

namespace seg{
	#define lc (o<<1)
	#define rc (o<<1|1)
	#define mid ((l+r)>>1)

	node T[N<<2];
	int tag[N<<2];
	void up(int o){
		T[o].fi=tree::merge(T[lc].fi,T[rc].fi);
		T[o].se=tree::merge(T[lc].se,T[rc].se);
	}
	void app(int o){
		swap(T[o].fi,T[o].se);
		tag[o]^=1;
	}
	void down(int o){
		if(tag[o]){
			app(lc),app(rc);
			tag[o]=0;
		}
	}
	void upd(int o,int l,int r,int x,int y){
		if(l==x&&y==r){
			app(o);
			return;
		}
		down(o);
		if(x<=mid) upd(lc,l,mid,x,min(y,mid));
		if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y);
		up(o);
	}
	void build(int o,int l,int r){
		if(l==r){
			if(!col[rev[l]]){
				T[o].fi=mp(rev[l],rev[l]);
				T[o].se=mp(0,0);
			}
			else{
				T[o].se=mp(rev[l],rev[l]);
				T[o].fi=mp(0,0);
			}
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		up(o);
	}
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(x),read(y),read(owo[i]);
		e[x].pb(mp(y,i));
		e[y].pb(mp(x,i));
	}
	tree::init();
	seg::build(1,1,n);
	read(Q);
	while(Q--){
		read(x);
		seg::upd(1,1,n,in[cur[x]],out[cur[x]]);
		node ret=seg::T[1];
		int ans1=tree::dist(ret.fi.fi,ret.fi.se);
		int ans2=tree::dist(ret.se.fi,ret.se.se);
		printf("%d\n",max(ans1,ans2));
	}
	return 0;
}