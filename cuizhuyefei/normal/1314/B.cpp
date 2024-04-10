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
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1<<17|3,inf=0x3f3f3f3f;
int n,m,a[N],dp[N<<2][2][2];
void dfs(int k, int l, int r){
	rep(i,0,1)rep(j,0,1)dp[k][i][j]=-inf;
	if(l+1==r){
		dp[k][a[l]][a[r]]=dp[k][a[r]][a[l]]=a[l]|a[r];return;
	}
	int mid=(l+r)>>1;dfs(k<<1,l,mid);dfs(k<<1|1,mid+1,r);
	rep(a,0,1)rep(b,0,1)rep(c,0,1)rep(d,0,1)
		umax(dp[k][a][c|b|d],dp[k<<1][a][b]+dp[k<<1|1][c][d]+(a|c)+(b|d)+(c|b|d)),
		umax(dp[k][c][a|b|d],dp[k<<1][a][b]+dp[k<<1|1][c][d]+(a|c)+(b|d)+(a|b|d));
//	rep(i,0,1)rep(j,0,1)if(dp[k][i][j]>=0)printf("%d %d %d %d:%d\n",l,r,i,j,dp[k][i][j]);
}
int main() {
	read(n);read(m);rep(i,1,m){int x;read(x);a[x]=1;}
	dfs(1,1,1<<n);
	int res=0;rep(i,0,1)rep(j,0,1)umax(res,dp[1][i][j]+(i|j));
	cout<<res;
	return 0;
}