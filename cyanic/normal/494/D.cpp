#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

namespace{
	const int mod=1e9+7;
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
}

const int N=200005;
int f[N][3],g[N][3],fa[N][20],d[N],D[N],in[N],out[N];
int n,a,b,c,x,y,clk,Q;
vector<pii> e[N];

int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	per(j,18,0){
		if(d[fa[x][j]]>=d[y]) x=fa[x][j];
	}
	if(x==y) return x;
	per(j,18,0){
		if(fa[x][j]!=fa[y][j]){
			x=fa[x][j],y=fa[y][j];
		}
	}
	return fa[x][0];
}
void dfs(int u,int pa){
	in[u]=++clk;
	fa[u][0]=pa;
	rep(j,1,18){
		fa[u][j]=fa[fa[u][j-1]][j-1];
	}
	for(auto v:e[u]){
		if(v.fi==pa) continue;
		d[v.fi]=d[u]+1;
		D[v.fi]=fix(D[u]+v.se);
		dfs(v.fi,u);
	}
	out[u]=clk;
}

void app(int &f0,int &f1,int &f2,int g[3],int w){
	add(f0,g[0]);
	add(f1,g[1]);
	add(f1,mul(g[0],w));
	add(f2,g[2]);
	add(f2,mul(g[1],2*w));
	add(f2,mul(g[0],mul(w,w)));
}

void dfs1(int u,int fa){
	f[u][0]=1;
	for(auto t:e[u]){
		int v=t.fi,w=t.se;
		if(v==fa) continue;
		dfs1(v,u);
		app(f[u][0],f[u][1],f[u][2],f[v],w);
	}
}

void dfs2(int u,int fa){
	vi pre[3],suf[3];
	vector<pii> sn;
	for(auto v:e[u]){
		if(v.fi==fa) continue;
		sn.pb(v);
	}
	int sz=sn.size();
	REP(i,3){
		pre[i].resize(sz);
		suf[i].resize(sz);
	}
	for(int i=0;i<sz;i++){
		int v=sn[i].fi,w=sn[i].se;
		if(i) REP(k,3) pre[k][i]=pre[k][i-1];
		app(pre[0][i],pre[1][i],pre[2][i],f[v],w);
	}
	for(int i=sz-1;i>=0;i--){
		int v=sn[i].fi,w=sn[i].se;
		if(i+1<sz) REP(k,3) suf[k][i]=suf[k][i+1];
		app(suf[0][i],suf[1][i],suf[2][i],f[v],w);
	}
	REP(i,sz){
		int v=sn[i].fi,w=sn[i].se;
		int g0=g[u][0]+1,g1=g[u][1],g2=g[u][2];
		if(i){
			add(g0,pre[0][i-1]);
			add(g1,pre[1][i-1]);
			add(g2,pre[2][i-1]);
		}
		if(i+1<sz){
			add(g0,suf[0][i+1]);
			add(g1,suf[1][i+1]);
			add(g2,suf[2][i+1]);
		}
		g[v][0]=g0;
		g[v][1]=(g1+(ll)g0*w)%mod;
		g[v][2]=(g2+(ll)2*g1*w+(ll)g0*w%mod*w)%mod;
		dfs2(v,u);
	}
//	printf("# %d    %d   %d  %d\n",u,g[u][0],g[u][1],g[u][2]);
}

int Case1(int x,int y){		//x  y 
	int d=((ll)D[x]-D[y]+mod)%mod;
	int ans=fix(f[x][2]+g[x][2]);
	add(ans,mod-mul(2,g[y][2]));
	add(ans,mod-mul(4,mul(g[y][1],d)));
	add(ans,mod-mul(2,mul(g[y][0],mul(d,d))));
	return ans;
}

int Case2(int x,int y){
	int d=((ll)D[x]+D[y]+2ll*mod-2ll*D[lca(x,y)])%mod;
	int ans=fix(f[x][2]+g[x][2]);
	add(ans,mod-mul(2,f[y][2]));
	add(ans,mod-mul(4,mul(f[y][1],d)));
	add(ans,mod-mul(2,mul(f[y][0],mul(d,d))));
	return (mod-ans)%mod;
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b),read(c);
		e[a].pb(mp(b,c)),e[b].pb(mp(a,c));
	}
	dfs(1,0);
	dfs1(1,0);
	dfs2(1,0);
	read(Q);
	while(Q--){
		read(x),read(y);
		if(in[y]<=in[x]&&out[x]<=out[y]){
			printf("%d\n",Case1(x,y));
		}
		else{
			printf("%d\n",Case2(x,y));
		}
	}

	return 0;
}