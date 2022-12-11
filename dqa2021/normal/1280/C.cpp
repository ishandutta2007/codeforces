#include<bits/stdc++.h>
#define pb emplace_back
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
#define forall(x,y,w) for (const auto &[y,w]: e[x])

int n;
vector<P> e[200010];

int siz[200010];
void dfs0(int x,int f){
	siz[x]=1;
	forall(x,y,w) if (y^f) dfs0(y,x),siz[x]+=siz[y];
}

ll G,B;

ll sqr(int x){return 1LL*x*x;}

void dfs1(int x,int f){
	forall(x,y,w) if (y^f) dfs1(y,x),G+=siz[y]&1?w:0;
}
void dfs2(int x,int f){
	forall(x,y,w) if (y^f) dfs2(y,x),B+=min(siz[y],n-siz[y])*1LL*w;
}

void solve(){
	n=read()<<1;
	rep(i,1,n) e[i].clear();
	rep(i,2,n){
		int u=read(),v=read(),w=read();
		e[u].pb(v,w),e[v].pb(u,w);
	}
	dfs0(1,0);
	G=B=0;
	dfs1(1,0); dfs2(1,0);
	printf("%lld %lld\n",G,B);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}