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
int siz[512];

int ask(vector<int> S,vector<int> T,int v){
	printf("%d\n",int(S.size()));
	for (int x: S) printf("%d ",x);
	puts("");
	printf("%d\n",int(T.size()));
	for (int x: T) printf("%d ",x);
	puts("");
	printf("%d\n",v);
	F;
	return read();
}

vector<int> W;
vector<int> e[512];
vector<int> G;

void solve(int x,int l,int r){
	if (!ask({1},vector<int>(W.begin()+l,W.begin()+r+1),x)) return;
	if (l==r) return G.pb(W[l]),void();
	int mid=l+r>>1;
	solve(x,l,mid); solve(x,mid+1,r);
}

void work(int x){
	if (siz[x]==1) return W.pb(x),void();
	G.clear(); solve(x,0,W.size()-1);
	for (int y: G) W.erase(find(all(W),y)),e[x].pb(y);
	W.pb(x);
}

void solve(){
	n=read();
	siz[1]=n;
	rep(i,2,n){
		vector<int> S(n-1);
		iota(all(S),2);
		siz[i]=ask({1},S,i);
	}
	static int p[512];
	iota(p+1,p+n+1,1);
	sort(p+1,p+n+1,[&](int x,int y){return siz[x]<siz[y];});
	rep(i,1,n) work(p[i]);
	puts("ANSWER");
	rep(i,1,n) forall(i,j) printf("%d %d\n",i,j);
	F;
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}