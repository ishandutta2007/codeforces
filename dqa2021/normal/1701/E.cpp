#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
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
const short INF=2e4;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m;
char a[5010],b[5010];
short dp[5010][5010][3];

void chk(short &x,const short &y){
	if (y<x) x=y;
}

void solve(){
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	rep(i,0,n+2) rep(j,0,m+2){
		short *F=dp[i][j];
		F[0]=F[1]=F[2]=INF;
	}
	dp[0][0][0]=1;
	dp[0][0][1]=0;
	rep(i,0,n-1) rep(j,0,min(m,i)){
		const short *F=dp[i][j];
		short *G=dp[i+1][j],*H=dp[i+1][j+1];
		// match
		if (j<m&&a[i+1]==b[j+1]){
			chk(H[0],F[0]+1);
			chk(H[1],F[0]);
			chk(H[1],F[1]);
			chk(H[2],F[0]+1);
			chk(H[2],F[1]+1);
			chk(H[2],F[2]+1);
		}
		// unmatch
		{
			chk(G[0],F[0]+2);
			chk(G[2],F[0]+1);
			chk(G[2],F[1]+1);
			chk(G[2],F[2]+1);
		}
	}
//	rep(i,0,n) rep(j,0,m){
//		int *F=dp[i][j];
//		printf("%d %d: %d %d %d\n",i,j,F[0],F[1],F[2]);
//	}
	const short *F=dp[n][m];
	int w=min(F[0],min(F[1],F[2]));
	if (w>1e4) puts("-1");
	else printf("%d\n",w);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}