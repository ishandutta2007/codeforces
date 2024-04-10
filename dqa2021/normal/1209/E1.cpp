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

int n,m;
int b[16][2010];
int a[16][16];
int dp[2][1<<12];
int H[1<<12];

void solve(){
	n=read(),m=read();
	rep(i,1,n) rep(j,1,m) b[i][j]=read();
	vector<P> S;
	rep(j,1,m){
		int mx=0;
		rep(i,1,n) mx=max(mx,b[i][j]);
		S.emplace_back(mx,j);
	}
	sort(all(S));
	rep(j,1,min(n,m)){
		const int x=S[S.size()-j].se;
//		printf("x %d\n",x);
		rep(i,1,n) a[i][j]=b[i][x];
	}
	m=min(n,m);
	const int lim=(1<<n)-1;
	auto F=dp[0],G=dp[1];
	memset(F,-0x3f,sizeof dp[1]);
	F[0]=0;
	rep(i,1,m){
		swap(F,G);
		memcpy(F,G,sizeof dp[1]);
		rep(e,0,n-1){
			static int c[16];
			rep(j,1,n) c[j]=a[(j+e-1)%n+1][i];
			memcpy(H,G,sizeof H);
			rep(msk,0,lim){
				F[msk]=max(F[msk],H[msk]);
				rep(j,1,n) if (msk>>j-1&1^1){
					int nxt=msk|1<<j-1;
					H[nxt]=max(H[nxt],H[msk]+c[j]);
				}
			}
		}
	}
	printf("%d\n",F[lim]);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}