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

//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
int d[210][210],C[210][210],pw[210];
void init(int x){
	rep(i,0,x){
		C[i][0]=1;
		rep(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	rep(i,0,x) pw[i]=qpow(2,mod-1-i);
	rep(u,1,x) rep(v,1,x){
		rep(w,0,v-1){
			add(d[u][v],1LL*C[u+w-1][u-1]*pw[u+w]%mod);
		}
//		printf("d %d %d = %d\n",u,v,d[u][v]);
	}
}

int n;
vector<int> e[210];
int dep[210]; int W;

vector<int> dfs(int x,int f,int dp){
	vector<int> S; dep[x]=dp;
	forall(x,y) if (y^f){
		auto T=dfs(y,x,dp+1);
		for (int u: S)
			for (int v: T)
				if (u>v) add(W,d[dep[u]-dep[x]][dep[v]-dep[x]]);
				else add(W,d[dep[v]-dep[x]][dep[u]-dep[x]]);
		S.insert(S.end(),all(T));
	}
	for (int u: S) if (x>u) add(W,1);
	S.pb(x);
	return S;
}

int work(int x){
	W=0; dfs(x,0,1);
//	printf("work %d = %d\n",x,W);
	return W;
}

void solve(){
	n=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	init(n+3);
	int z=0;
	rep(i,1,n) add(z,work(i));
	z=1LL*z*qpow(n,mod-2)%mod;
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}