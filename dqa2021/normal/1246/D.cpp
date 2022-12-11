#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
typedef priority_queue<P,vector<P>,greater<P> > Q;

int n;
int p[100010];
vector<int> e[100010];

struct C{
	int o,u,v;
	C(int O,int U,int V){o=O,u=U,v=V;}
}; vector<C> G;

Q q[100010];

void merge(Q &x,Q &y){
	if (x.size()<y.size()) swap(x,y);
	while (y.size()) x.push(y.top()),y.pop();
}

int gnd[17][100010],dep[100010];
int lift(int x,int d){
	d=dep[x]-d;
	rep(i,0,16) if (d>>i&1) x=gnd[i][x];
	return x;
}

void dfs0(int x,int d){
	gnd[0][x]=p[x]; dep[x]=d;
	for (int j=1;j<17&&gnd[j-1][x];++j)
		gnd[j][x]=gnd[j-1][gnd[j-1][x]];
	forall(x,y) dfs0(y,d+1);
}

void dfs(int x,int d){
	if (e[x].empty()) return q[x].push(P(d,x)),void();
	set<int> S;
	forall(x,y){
		dfs(y,d+1);
		S.insert(y);
		merge(q[x],q[y]);
	}
	const int lim=e[x].size()-1;
	if (!lim) return;
	vector<P> T;
	{
	rep(_,1,lim) T.pb(q[x].top()),q[x].pop();
	//for (const auto &w: T) q[x].push(w);
	}
	S.erase(lift(T[0].se,d+1));
	rep(_,0,lim-1){
		const auto &w=T[_];
		const int u=lift(w.se,d+1);
		assert(!S.count(u));
		if (_<lim-1){
			const int v=lift(T[_+1].se,d+1);
			if (S.count(v)){
				S.erase(v);
				G.emplace_back(v,w.se,x);
				continue;
			}
		}
		const int v=*S.begin();
		S.erase(v);
		G.emplace_back(v,w.se,x);
	}
}

void solve(){
	n=read();
	rep(i,2,n) p[i]=read()+1,e[p[i]].pb(i);
	dfs0(1,1);
	//puts("test");
	dfs(1,1);
	//puts("test");
	//printf("p: ");
	//rep(i,1,n) printf("%d ",p[i]);
	//puts("\n========");
	reverse(all(G));
	for (const auto &w: G) p[w.o]=w.u;
	reverse(all(G));
	//printf("p: ");
	//rep(i,1,n) printf("%d ",p[i]);
	//puts("\n========");
	
	//static int q[100010];
	const function<void(int)> work=[&](int x){
		static bool vis[100010];
		if (vis[x]) return;
		if (p[x]) work(p[x]);
		vis[x]=1; printf("%d ",x-1);  // !!!
		//static int cnt=0;
		//q[x]=++cnt;
	};
	rep(i,1,n) work(i);
	puts("");
	
	//puts("test");
	
	vector<int> H;
	for (const auto &w: G){
		//printf("move %d from %d to %d\n",w.o,w.u,w.v);
		assert(p[w.o]==w.u);
		while (p[w.o]!=w.v) H.pb(/*q[w.o]*/w.o),p[w.o]=p[p[w.o]];
	}
	/*printf("p: ");
	rep(i,1,n) printf("%d ",p[i]);
	puts("\n========");*/
	printf("%d\n",int(H.size()));
	for (int x: H) printf("%d ",x-1);  // !!!
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}