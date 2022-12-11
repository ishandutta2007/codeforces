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

const int mod=998244353;
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

char s[1010];
int c[2010];
vector<P> e[2010];
inline void adde(int x,int y,int w){
	e[x].pb(y,w); e[y].pb(x,w);
}

bool vis[2010];
bool dfs(int x,int col){
	vis[x]=1; c[x]=col;
	forall(x,o){
		int y,w; tie(y,w)=o;
		if (!vis[y]){
			if (!dfs(y,col^w)) return 0;
		}
		else if ((col^w)!=c[y]) return 0;
	}
	return 1;
}

int work(int n,int m){
	const int lim=n+m+1;
	const int E=n+m+1;
	rep(i,1,lim) c[i]=-1,e[i].clear(),vis[i]=0;
	adde(n+1,E,1);
	rep(i,1,n){
		if (i>m){
			if (s[i]=='1') adde(i,E,1);
			else if (s[i]=='0') adde(i,E,0);
		}
		else{
			if (s[i]=='1') adde(i,i+n,1);
			else if (s[i]=='0') adde(i,i+n,0);
		}
	}
	rep(i,1,n) adde(i,n-i+1,0);
	rep(i,1,m) adde(n+i,n+m-i+1,0);
	int z=-1;
	rep(i,1,lim) if (!vis[i])
		if (!dfs(i,0)) return 0;
		else ++z;
	return qpow(2,z);
}
int n;

void solve(){
	scanf("%s",s+1); n=strlen(s+1);
	reverse(s+1,s+n+1);
	int z=0;
	rep(t,1,n-1) add(z,work(n,t));
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}