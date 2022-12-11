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
int c[100010];
vector<P> e[100010];

//bool inq[100010];
int dis[100010];
int p[100010];

int ch[600010][10],w[600010];
int gnd[20][600010];
int ctot=1;


int ans[100010];
vector<int> g[600010];

int getmin(int x,int y){
	int a(x),b(y);
	if (!~x) return y;
	if (x==y) return x;
	per(j,0,19) if (gnd[j][x]^gnd[j][y])
		x=gnd[j][x],y=gnd[j][y];
	return w[x]<w[y]?a:b;
}

int ins(int x,int w){
//	printf("INS %d %d: ",x,w);
	static int d[8]; int top=0;
	while (w) d[++top]=w%10,w/=10;
	reverse(d+1,d+top+1);
	rep(i,1,top){
		int c=d[i];
		if (!ch[x][c]){
			ch[x][c]=++ctot,::w[ctot]=c;
			gnd[0][ctot]=x;
			rep(j,1,19) gnd[j][ctot]=gnd[j-1][gnd[j-1][ctot]];
		}
		x=ch[x][c];
	}
//	printf("%d\n",x);
	return x;
}

void dfs(int x,int V){
	for (int o: g[x]) ans[o]=V;
	rep(j,0,9) if (ch[x][j]) dfs(ch[x][j],(10LL*V+j)%mod);
}

void solve(){
	n=read(),m=read();
	rep(i,1,m) c[i]=c[i/10]+1;
	rep(_,1,m){
		int u=read(),v=read();
		e[u].pb(v,_),e[v].pb(u,_);
	}
	priority_queue<P,vector<P>,greater<P> > que;
	rep(i,1,n) dis[i]=1e9;
	dis[1]=0; que.emplace(0,1);
	while (que.size()){
		int x,w; tie(w,x)=que.top();
		que.pop();
		if (w^dis[x]) continue;
		p[++*p]=x;
		forall(x,o){
			int y,d; tie(y,d)=o;
			if (dis[x]+c[d]<dis[y]){
				dis[y]=dis[x]+c[d];
				que.emplace(dis[y],y);
			}
		}
	}
	
	static int f[100010];
	
	f[1]=1;
	rep(_,2,n){
		const int &x=p[_];
		f[x]=-1;
		forall(x,o){
			int y,d; tie(y,d)=o;
			if (dis[y]+c[d]==dis[x]){
//				printf("test %d - %d -> %d\n",y,d,x);
				f[x]=getmin(f[x],ins(f[y],d));
			}
		}
//		printf("f %d = %d\n",x,f[x]);
		g[f[x]].pb(x);
	}
	
	dfs(1,0);
	rep(i,2,n) printf("%d\n",ans[i]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}