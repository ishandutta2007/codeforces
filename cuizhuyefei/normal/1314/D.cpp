#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 83,inf=0x3f3f3f3f;
int n,k,a[N][N],res=2e9,c[N],dp[12][N];
int main() {
	read(n);read(k);
	rep(i,1,n)rep(j,1,n)read(a[i][j]);
	rep(i,1,n)a[i][i]=1e9;
	while(1.0*clock()/CLOCKS_PER_SEC<2.5){
		rep(i,2,n)c[i]=R()%2;
		memset(dp,inf,sizeof(dp));dp[0][1]=0;
		rep(t,1,k)rep(i,1,n)if((c[i]^t)&1)rep(j,1,n)umin(dp[t][j],dp[t-1][i]+a[i][j]);
		umin(res,dp[k][1]);
	}
	cout<<res;
	return 0;
}