#include<bits/stdc++.h>
#define pb emplace_back
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

const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const auto &y: e[x])

int n,m;
vector<P> e[100010];
bool mrk[100010];
vector<P> S;

int getedge(int u,int v){
	forall(u,o) if (o.fi==v) return o.se;
	assert(0); return -1;
}

struct B{
	int b[5]; bool ban;
	B(){memset(b,0,sizeof b);ban=0;}
	bool ins(int x){
		per(i,0,4) if (x>>i&1){
			if (b[i]){
				x^=b[i]; continue;
			}
			b[i]=x;
			per(j,0,i-1) if (b[i]>>j&1) b[i]^=b[j];
			rep(j,i+1,4) if (b[j]>>i&1) b[j]^=b[i];
			return 1;
		}
		ban=1;
		return 0;
	}
}lb[100010];

B operator+(B x,const B &y){
	rep(i,0,4) if (y.b[i]) x.ins(y.b[i]);
	x.ban|=y.ban;
	return x;
}

bool check(B x,const B &y,B &z){
	if (y.ban) return 0;
	rep(i,0,4) if (y.b[i]&&!x.ins(y.b[i])) return 0;
	z=x;
	return 1;
}

int d[100010]; bool vis[100010];

void dfs0(int x,int fa,int ban,int dis,B &lb){
	d[x]=dis; vis[x]=1;
	forall(x,o){
		int y,c; tie(y,c)=o;
		if (y==fa||y==ban) continue;
		if (!vis[y]) dfs0(y,x,ban,dis^c,lb);
		else{
			if (x>y) continue;
			lb.ins(d[x]^d[y]^c);
//			printf("test ins %d ^ %d ^ %d = %d\n",d[x],d[y],c,d[x]^d[y]^c);
		}
	}
}

int id[1<<15|10],dfn[1<<15|10]; int tot;

int encode(const B &x){
	return x.b[4]|x.b[3]<<5|x.b[2]<<9|x.b[1]<<12|x.b[0]<<14;
}
B decode(int x){
	B z;
	z.b[4]=x&31;
	z.b[3]=x>>5&15;
	z.b[2]=x>>9&7;
	z.b[1]=x>>12&3;
	z.b[0]=x>>14&1;
	return z;
}

int H(int x){
	if (!id[x]) id[x]=++tot,dfn[tot]=x;
	return id[x];
}

int lk[100010];

void solve(){
	n=read(),m=read();
	rep(i,1,m){
		int u=read(),v=read(),c=read();
		if (u>v) swap(u,v);
		e[u].pb(v,c),e[v].pb(u,c);
	}
	forall(1,u){
		int p=-1,y=u.fi;
		forall(y,o){
			if (mrk[o.fi]){
				p=o.fi; break;
			}
		}
		mrk[y]=1; lk[y]=p;
		if (~p) lk[p]=y;
//		S.emplace_back(y,p);
	}
	forall(1,u) if (lk[u.fi]<u.fi) S.emplace_back(u.fi,lk[u.fi]);
//	for (auto o: S) printf("test %d %d\n",o.fi,o.se); 
	for (auto o: S){
		dfs0(o.fi,1,o.se,0,lb[o.fi]);
		if (~o.se) dfs0(o.se,1,o.fi,0,lb[o.se]);
	}
	static int dp[2][1<<15|10];
	auto F=dp[0],G=dp[1];
	F[H(0)]=1;
	for (auto o: S){
		int u,v; tie(u,v)=o;
		if (!~v){
			swap(F,G);
			memset(F+1,0,tot<<2);
			rep(i,1,tot){
				int msk=dfn[i];
				add(F[i],G[i]);
				B z;
//				printf("test ban? %d: %d\n",u,lb[u].ban);
				if (check(decode(msk),lb[u],z))
					add(F[H(encode(z))],G[i]);
			}
		}
		else{
			swap(F,G);
			memset(F+1,0,tot<<2);
			int E=getedge(u,v)^getedge(u,1)^getedge(v,1);
			rep(i,1,tot){
				int msk=dfn[i];
				add(F[i],G[i]);
				B z,w=decode(msk),s;
//				if (check(w,lb[u],z))
//					add(F[H(encode(z))],G[i]);
				if (check(w,s=lb[u]+lb[v],z))
					add(F[H(encode(z))],2*G[i]%mod);
				s.ins(E);
				if (check(w,s,z))
					add(F[H(encode(z))],G[i]);
			}
		}
//		rep(i,1,tot){
//			printf("dp ");
//			int x=dfn[i];
//			B z=decode(x);
//			per(j,0,4){
//				rep(k,0,j) printf("%d",z.b[j]>>k&1);
//				printf(" ");
//			}
//			printf(" = %d\n",F[i]);
//		}
	}
	int z=0;
	rep(i,1,tot) add(z,F[i]);
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}