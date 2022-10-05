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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=500005;
struct node{
	int v[2][2];
	node(int _a=0,int _b=0,int _c=0,int _d=0){
		v[0][0]=_a,v[0][1]=_b;
		v[1][0]=_c,v[1][1]=_d;
	}
	friend node trans(node x){
		return node(x.v[1][0],x.v[0][0]+x.v[1][1],
					x.v[0][0],x.v[0][1]);
	}
	friend node operator + (node x,node y){
		node res;
		rep(a,0,1)rep(b,0,1)
			rep(c,0,1-a)rep(d,0,1-b)
				res.v[a+c][b+d]+=x.v[a][b]*y.v[c][d];
		return res;
	}
	friend void print(node x){
		printf("%d %d %d %d\n",x.v[0][0],x.v[0][1],x.v[1][0],x.v[1][1]);
	}
}f[N],g[N];
int sz[N],n,a,b;
vi e[N];

void dfs(int u,int fa){
	f[u].v[0][0]=1,sz[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u),sz[u]+=sz[v];
		f[u]=f[u]+trans(f[v]);
	}
}

void dfs2(int u,int fa){
	if(fa&&e[u].size()==1) return;
	vector<node> pre,suf;
	vi sn;
	for(auto v:e[u]){
		if(v==fa) continue;
		sn.pb(v);
	}
	int sz=sn.size();
	pre.resize(sz);
	suf.resize(sz);
	pre[0]=trans(f[sn[0]]);
	suf[sz-1]=trans(f[sn[sz-1]]);
	for(int i=1;i<sz;i++) pre[i]=pre[i-1]+trans(f[sn[i]]);
	for(int i=sz-2;i>=0;i--) suf[i]=suf[i+1]+trans(f[sn[i]]);
	node owo=(u!=1?trans(g[u]):g[u]);
	for(int i=0;i<sz;i++){
		g[sn[i]]=owo;
		if(i) g[sn[i]]=g[sn[i]]+pre[i-1];
		if(i<sz-1) g[sn[i]]=g[sn[i]]+suf[i+1];
	}
	for(auto v:sn) dfs2(v,u);
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	dfs(1,0);
	g[1].v[0][0]=1;
	dfs2(1,0);
	ll ans=0;
	rep(u,2,n){
		if(f[u].v[1][0]&&g[u].v[1][0]) ans+=(ll)sz[u]*(n-sz[u]);
		else ans+=(ll)(f[u].v[0][0]+f[u].v[1][1])
					 *(g[u].v[0][0]+g[u].v[1][1]);
	}
	cout<<ans<<endl;
	return 0;
}