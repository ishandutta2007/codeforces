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
const int N = 1234;
int n,d,mo,dp[N],f[N][N][11],inv[N];//,fac[N],ifac[N];
int power(int a, int n){
	int res=1;
	while(n){if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;}
	return res;
}
//inline int C(int n, int m){return 1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo;}
inline int calc(int tot, int c, int now){return tot==0?(c==0):now;}
//inline int calc(int tot, int c){return tot==0?(c==0):C(tot+c-1,c);}
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
int main() {
	read(n);read(d);read(mo);int mx=N-1;
	if(n==1){puts("1");return 0;}
	//fac[0]=1;rep(i,1,mx)fac[i]=1LL*fac[i-1]*i%mo;
	//ifac[mx]=power(fac[mx],mo-2);per(i,mx-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	inv[1]=1;rep(i,2,N-1)inv[i]=1LL*(mo-mo/i)*inv[mo%i]%mo;
	f[0][0][0]=1;
	rep(i,1,n){
		dp[i]=f[i-1][i-1][d-1];if(i==1)dp[i]=1;
	//	printf("%d:%d\n",i,dp[i]);
		rep(j,0,n)rep(k,0,d)if(f[i-1][j][k])for(int c=0,now=1;k+c<=d&&j+i*c<=n;c++){
			add(f[i][j+i*c][k+c],1LL*f[i-1][j][k]*calc(dp[i],c,now)%mo);
			now=1LL*now*(dp[i]+c)%mo*inv[c+1]%mo;
		}
	}
	printf("%d",((n%2==0?1LL*(dp[n/2]+1)*dp[n/2]/2%mo:0)+f[(n-1)/2][n-1][d])%mo);
	return 0;
}