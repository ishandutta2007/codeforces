#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

const ll Inf=1e12;
const int N=250005,M=N*36;

int xx[N],cx;
namespace seg{
	int lc[M],rc[M],c[M],sz;
	ll s[M];

	void ins(int &o,int l,int r,int x,int y){
		if(!o) o=++sz;
		if(l==r){
			c[o]+=y,s[o]+=(ll)y*xx[l];
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid) ins(lc[o],l,mid,x,y);
		else ins(rc[o],mid+1,r,x,y);
		c[o]=c[lc[o]]+c[rc[o]];
		s[o]=s[lc[o]]+s[rc[o]];
	}

	ll qry(int o,int l,int r,int K){
		if(K>c[o]) return Inf;
		if(K==c[o]) return s[o];
		if(l==r) return (ll)xx[l]*K;
		int mid=(l+r)>>1;
		if(K<=c[lc[o]]) return qry(lc[o],l,mid,K);
		return s[lc[o]]+qry(rc[o],mid+1,r,K-c[lc[o]]);
	}
}

vector<pair<pii,int> > tr[N];
vector<pii> e[N],sn[N];
set<int> key;
vi pt[N];

int fa[N],fv[N],mark[N],rt[N];
ll dp[N][2],ans[N];
int n,lim;

void dfs(int u,int fa){
	REP(k,SZ(e[u])){
		int v=e[u][k].fi;
		int w=e[u][k].se;
		if(v==fa) continue;
		int deg=min(SZ(e[u]),SZ(e[v]));
		tr[deg-1].pb(mp(mp(u,v),w));
		dfs(v,u);
	}
	pt[SZ(e[u])-1].pb(u);
}

void solve(int u){
	int sz=SZ(sn[u]),del=SZ(e[u])-lim;
	vector<ll> delta;
	ll base=0;
	REP(k,sz){
		int v=sn[u][k].fi;
		solve(v);
		base+=dp[v][1];
		delta.pb(dp[v][0]-dp[v][1]);
	}
	sort(delta.begin(),delta.end());
	rep(i,1,SZ(delta)-1){
		delta[i]+=delta[i-1];
	}
	dp[u][0]=dp[u][1]=Inf;
	rep(i,0,SZ(delta)){
		ll now=base+(i>=1?delta[i-1]:0);
		ll val=now+seg::qry(rt[u],1,cx,max(0,del-i));
		dp[u][1]=min(dp[u][1],val);
		val=now+fv[u]+seg::qry(rt[u],1,cx,max(0,del-i-1));
		dp[u][0]=min(dp[u][0],val);
	}
}

int main(){
	read(n);
	static int a[N],b[N],c[N];
	rep(i,1,n-1){
		read(a[i]),read(b[i]),read(c[i]);
		e[a[i]].pb(mp(b[i],c[i]));
		e[b[i]].pb(mp(a[i],c[i]));
		xx[++cx]=c[i];
	}
	sort(xx+1,xx+cx+1);
	cx=unique(xx+1,xx+cx+1)-xx-1;
	rep(i,1,n-1){
		int t=lower_bound(xx+1,xx+cx+1,c[i])-xx;
		seg::ins(rt[a[i]],1,cx,t,1);
		seg::ins(rt[b[i]],1,cx,t,1);
	}
	dfs(1,0);
	for(lim=n-1;lim>=0;lim--){
		REP(k,SZ(pt[lim])){
			int u=pt[lim][k];
			mark[u]=SZ(e[u]);
			key.insert(u);
		}
		REP(k,SZ(tr[lim])){
			int u=tr[lim][k].fi.fi;
			int v=tr[lim][k].fi.se;
			int w=tr[lim][k].se;
			fa[v]=u,fv[v]=w;
			sn[u].pb(mp(v,w));
			int t=lower_bound(xx+1,xx+cx+1,w)-xx;
			seg::ins(rt[u],1,cx,t,-1);
			seg::ins(rt[v],1,cx,t,-1);
		}
		for(set<int>::iterator it=key.begin();it!=key.end();it++){
			int u=*it;
			if(fa[u]) continue;
			solve(u);
			ans[lim]+=dp[u][1];
		}
	}
	rep(i,0,n-1){
		printf("%lld%c",ans[i]," \n"[i==n-1]);
	}
	return 0;
}