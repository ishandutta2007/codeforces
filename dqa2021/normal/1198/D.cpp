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

int n;
char mp[64][64];
int s[64][64];
int dp[64][64][64][64];
int getsum(int x,int y,int a,int b){
	return s[a][b]-s[x-1][b]-s[a][y-1]+s[x-1][y-1];
}

void solve(){
	n=read();
	rep(i,1,n) scanf("%s",mp[i]+1);
	rep(i,1,n) rep(j,1,n){
		s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(mp[i][j]=='#');
	}
	per(i,1,n) per(j,1,n) rep(a,i,n) rep(b,j,n){
		int &V=dp[i][j][a][b]; V=max(a-i+1,b-j+1);
		if (a-i>b-j){
			rep(k,i,a) if (!getsum(k,j,k,b))
				V=min(V,dp[i][j][k-1][b]+dp[k+1][j][a][b]);
		}
		else{
			rep(k,j,b) if (!getsum(i,k,a,k))
				V=min(V,dp[i][j][a][k-1]+dp[i][k+1][a][b]);
		}
//		printf("dp %d %d %d %d = %d\n",i,j,a,b,V);
	}
	printf("%d\n",dp[1][1][n][n]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}