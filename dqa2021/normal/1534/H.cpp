#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
#define F fflush(stdout)

int n;
vector<int> e[100010];

int f[100010],g[100010];  // subtree; global

int W;
inline int ask(int x){
	assert(W--);
	printf("? %d\n",x); F;
	return read();
}

void dfs1(int x,int fa){
	static int p[100010];
	if (fa&&e[x].size()==1) return f[x]=1,void();
	if (fa){
		forall(x,y) if (y^fa) dfs1(y,x);
		int m=0;
		forall(x,y) if (y^fa) p[++m]=y;
		sort(p+1,p+m+1,[&](int x,int y){return f[x]>f[y];});
		f[x]=m;
		rep(i,1,m) f[x]=max(f[x],f[p[i]]+i-1);
		return;
	}
	forall(x,y) dfs1(y,x);
	int m=0;
	forall(x,y) p[++m]=y;
	sort(p+1,p+m+1,[&](int x,int y){return f[x]>f[y];});
	f[x]=m;
	rep(i,2,m) f[x]=max(f[x],f[p[1]]+f[p[i]]+i-2);
}

void dfs2(int x,int fa,int h){
	static int p[100010],w[100010],q[100010];
	static int pre[100010],suf[100010];
	if (fa){
		int m=0; p[++m]=fa,w[fa]=h;
		forall(x,y) if (y^fa) p[++m]=y,w[y]=f[y];
		sort(p+1,p+m+1,[&](int x,int y){return w[x]>w[y];});
		rep(i,1,m) q[p[i]]=i;
		g[x]=m;
		rep(i,2,m) g[x]=max(g[x],w[p[1]]+w[p[i]]+i-2);
		pre[0]=suf[m+1]=0;
		rep(i,1,m) pre[i]=max(pre[i-1],w[p[i]]+i-1);
		per(i,1,m) suf[i]=max(suf[i+1],w[p[i]]+i-2);
		vector<int> S;
		forall(x,y) if (y^fa){
			if (e[x].size()==1) S.pb(1);
			else{
				int o=q[y]; S.pb(max(pre[o-1],suf[o+1]));
			}
		}
		reverse(all(S));
		forall(x,y) if (y^fa) dfs2(y,x,S.back()),S.pop_back();
		return;
	}
	g[x]=f[x];
	int m=0;
	forall(x,y) p[++m]=y;
	sort(p+1,p+m+1,[&](int x,int y){return f[x]>f[y];});
	rep(i,1,m) q[p[i]]=i;
	pre[0]=suf[m+1]=0;
	rep(i,1,m) pre[i]=max(pre[i-1],f[p[i]]+i-1);
	per(i,1,m) suf[i]=max(suf[i+1],f[p[i]]+i-2);
	vector<int> S;
	forall(x,y){
		if (e[x].size()==1) S.pb(1);
		else{
			int o=q[y]; S.pb(max(pre[o-1],suf[o+1]));
		}
	}
	reverse(all(S));
	forall(x,y) dfs2(y,x,S.back()),S.pop_back();
}

int dep[100010];

void dfs0(int x,int f,int d){
	dep[x]=d;
	forall(x,y) if (y^f) dfs0(y,x,d+1);
}

int dfs3(int x,int fa){  // z: me / ancestor / answer
	if (fa&&e[x].size()==1) return ask(x);
	if (fa){
		vector<int> S;
		forall(x,y) if (y^fa) S.pb(y);
		sort(all(S),[&](int x,int y){return f[x]>f[y];});
		for (int y: S){
			int z=dfs3(y,x);
			if (dep[z]>dep[x]) return z;
			if (dep[z]<dep[x]) return z;
		}
		return x;
	}
	int A=-1,B=-1;
	vector<int> S;
	forall(x,y) S.pb(y);
	sort(all(S),[&](int x,int y){return f[x]>f[y];});
	for (int y: S){
		int z=dfs3(y,x);
		if (z!=x){
			if (~A){
				B=z; break;
			}
			else A=z;
		}
	}
	if (!~A) A=x;
	if (!~B) B=x;
	printf("! %d %d\n",A,B); F;
	return 0;
}

void solve(){
	n=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	if (n==1){
		puts("0"); F;
		read();
		puts("! 1 1"); F;
		return;
	}
	dfs1(1,0); dfs2(1,0,-1);
	printf("%d\n",W=*max_element(g+1,g+n+1)); F;
	int rt=read();
	dfs0(rt,0,1); dfs1(rt,0); dfs3(rt,0);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}