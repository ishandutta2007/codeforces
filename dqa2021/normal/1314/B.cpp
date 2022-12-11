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
//typedef pair<int,int> P;
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
const int INF=1e9;

int n,m,lim;
bool e[1<<17];

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

int dp[1<<18][2][2];

void build(int x,int l,int r){
	if (r-l+1==2){
		auto F=dp[x];
		bool u=e[l],v=e[r];
		rep(a,0,1) rep(b,0,1) F[a][b]=-INF;
		F[u][v]=F[v][u]=u||v;
		return;
	}
	build(ls,l,mid); build(rs,mid+1,r);
	auto F=dp[x],G=dp[ls],H=dp[rs];
	rep(a,0,1) rep(b,0,1) F[a][b]=-INF;
	const auto chk=[&](int &x,const int &y){if (y>x) x=y;};
	rep(a,0,1) rep(b,0,1) rep(c,0,1) rep(d,0,1){
		if (G[a][b]==-INF||H[c][d]==-INF) continue;
		chk(F[a][max(max(b,d),c)],G[a][b]+H[c][d]+max(b,d)+max(max(b,d),c)+max(a,c));
		chk(F[c][max(max(b,d),a)],G[a][b]+H[c][d]+max(b,d)+max(max(b,d),a)+max(a,c));
	}
}

void solve(){
	n=read(),m=read(); lim=(1<<n)-1;
	while (m--) e[read()-1]=1;
	build(1,0,lim);
	int ans=-INF;
	rep(a,0,1) rep(b,0,1) ans=max(ans,dp[1][a][b]+max(a,b));
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}