#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 106,inf=0x3f3f3f3f;
int n,dp[N][2][N][N],p[N];
int main() {
	read(n);rep(i,1,n)read(p[i]);
	int c0=0,c1=0;
	rep(i,1,n)if(i&1)c1++;else c0++;
	rep(i,1,n)if(p[i]){if(p[i]&1)c1--;else c0--;}
	memset(dp,inf,sizeof(dp));
	dp[0][0][c0][c1]=0;
	rep(i,0,n-1)rep(j,0,1)rep(x,0,c0)rep(y,0,c1)if(dp[i][j][x][y]<inf){
		if(p[i+1]){
			umin(dp[i+1][p[i+1]&1][x][y],dp[i][j][x][y]+((i&&(p[i+1]&1)!=j)));
		}
		else{
			if(x)umin(dp[i+1][0][x-1][y],dp[i][j][x][y]+((i&&0!=j)));
			if(y)umin(dp[i+1][1][x][y-1],dp[i][j][x][y]+((i&&1!=j)));
		}
	}
	int res=inf;rep(i,0,1)umin(res,dp[n][i][0][0]);cout<<res;
	return 0;
}