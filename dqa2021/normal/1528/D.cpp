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

int n,m;
int a[360010],b[360010],c[360010];
vector<int> e[610];

int dis[610]; bool mrk[610];


int dp[610];

void work(int o){
	rep(i,0,n-1) dis[i]=2e9,mrk[i]=0;
	dis[o]=0;
	rep(_,1,n){
		int x=-1;
		rep(i,0,n-1) if (dis[i]!=2e9&&!mrk[i]&&(!~x||dis[i]<dis[x])) x=i;
		assert(~x);
		const int W=dis[x];
		mrk[x]=1;
		rep(i,0,n-1) dp[i]=2e9;
		for (const int &g: e[x]){
			int y=(b[g]+W)%n,c=::c[g];
			dp[y]=min(dp[y],c+W);
		}
		rep(i,1,n-1) dp[i]=min(dp[i],dp[i-1]+1);
		dp[0]=min(dp[0],dp[n-1]+1);
		rep(i,1,n-1) dp[i]=min(dp[i],dp[i-1]+1);
		rep(i,0,n-1) dis[i]=min(dis[i],dp[i]);
	}
	rep(i,0,n-1) printf("%d ",dis[i]);
	puts("");
}

void solve(){
	n=read(),m=read();
	rep(i,1,m) a[i]=read(),b[i]=read(),c[i]=read(),e[a[i]].pb(i);
	rep(i,0,n-1) work(i);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}