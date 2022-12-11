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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
const int INF=1e7;

int n;

set<int> st;

map<P,int> Bl,Wh; int btot,wtot;
P b[2000010],w[2000010];

int f[2000010];
vector<int> g[2000010];
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
void merge(vector<int> &S,vector<int> &T){
	if (T.size()>S.size()) swap(S,T);
	S.insert(S.end(),all(T));
	vector<int>().swap(T);
}
void upd(const vector<int> &);
bool merge(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return 0;
	if (x>y) swap(x,y);
//	debug("merge %d %d\n",x,y);
	f[y]=x;
	if (x==1) upd(g[y]);
	merge(g[x],g[y]);
	return 1;
}

int insB(int x,int y){
	Bl.emplace(P{x,y},++btot);
	b[btot]={x,y};
	return btot;
}
int insW(int x,int y){
	Wh.emplace(P{x,y},++wtot);
	w[wtot]={x,y}; g[wtot]={wtot};
//	debug("W %d: %d %d\n",wtot,x,y);
	return wtot;
}
int B(int x,int y){
	auto it=Bl.find({x,y});
	return it==Bl.end()?0:it->se;
}
int W(int x,int y){
	auto it=Wh.find({x,y});
	return it==Wh.end()?0:it->se;
}

bool vis[150010]; int cnt;

void dfs0(int o){
	if (!o) return;
	if (vis[o]) return;
	vis[o]=1; ++cnt;
	int x,y; tie(x,y)=b[o];
	for (int dx: {-1,0,1})
		for (int dy: {-1,0,1})
			if (dx||dy)
				dfs0(B(x+dx,y+dy));
}

bool del[150010];

void _chk(int o){
	int x,y; tie(x,y)=w[o];
	for (int dx: {-1,0,1})
		for (int dy: {-1,0,1})
			if (abs(dx)+abs(dy)==1){
				int v=W(x+dx,y+dy);
				if (v) merge(o,v);
			}
}

bool is_valid(int o){
	int x,y; tie(x,y)=b[o];
	static int e[8];
	static const int dx[]={1,1,0,-1,-1,-1,0,1};
	static const int dy[]={0,1,1,1,0,-1,-1,-1};
	rep(_,0,7){
		int t=W(x+dx[_],y+dy[_]);
		if (t) e[_]=find(t);
		else e[_]=0;
	}
	int q=0;
	rep(i,0,7) if (i&1^1) q+=e[i]==1;
	if (!q){
//		debug("  invalid %d: no 4-ajacent 1\n",o);
		return 0;
	}
	rep(a,0,7) if (a&1^1&&e[a]) rep(b,a+2,7) if (b&1^1&&e[b]==e[a]){
		int s=0,t=0;
		rep(i,a+1,b-1) s+=e[i]==0;
		rep(i,b+1,a-1+8) t+=e[i&7]==0;
		if (s&&t){
//			debug("  invalid %d: is key\n",o);
			return 0;
		}
	}
//	debug("  valid %d\n",o);
	return 1;
}

void check(int o){
	if (!o) return;
	if (del[o]) return;
	if (is_valid(o)) st.insert(o);
	else st.erase(o);
}

void upd(int o){
//	debug("  upd %d\n",o);
	int x,y; tie(x,y)=w[o];
	for (int dx: {-1,0,1})
		for (int dy: {-1,0,1})
			if (dx||dy)
				check(B(x+dx,y+dy));
}

void upd(const vector<int> &S){
	for (const int &o: S) upd(o);
}


void solve(){
	n=read(); read();
	rep(i,1,n){
		int x=read(),y=read();
		insB(x,y);
	}
	dfs0(Bl.begin()->se);
	if (cnt!=n) return puts("NO"),void();
	for (const auto &o: Bl){
		int x,y; tie(x,y)=b[o.se];
		for (int dx: {-1,0,1})
			for (int dy: {-1,0,1})
				if (dx||dy)
					if (!B(x+dx,y+dy)&&!W(x+dx,y+dy))
						insW(x+dx,y+dy);
	}
	upd(1);
	for (const auto &o: Wh) _chk(o.se);
	rep(i,1,n) check(i);
	vector<int> S;
	while ((int)S.size()<n){
		assert(st.size());
		int u=*st.rbegin();
//		debug("### get %d\n",u);
		st.erase(u);
		S.pb(u); del[u]=1;
		insW(b[u].fi,b[u].se);
		_chk(wtot);
	}
	puts("YES");
	reverse(all(S));
	for (int x: S) printf("%d ",x);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}