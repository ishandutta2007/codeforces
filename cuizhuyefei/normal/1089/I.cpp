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
const int N = 566;
int n,f[N],g[N],C[N][N],ans[N],fac[N],dp[3][N],poly[N][N],mo;
int main() {
	int T;read(T);n=400;read(mo);
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	rep(i,0,n){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	f[1]=1;dp[1][1]=1;
	rep(i,2,n){
		rep(j,0,2)rep(k,0,i-1)if(dp[j][k])
			dp[j+1<=2?j+1:2][i]=(dp[j+1<=2?j+1:2][i]+1LL*dp[j][k]*(f[i-k]+g[i-k]))%mo;
		f[i]=dp[2][i];g[i]=((fac[i]-2LL*f[i])%mo+mo)%mo;
		dp[1][i]=(f[i]+g[i])%mo;
	//	cerr<<f[i]<<' '<<g[i]<<endl;
	}
	poly[0][0]=1;
	rep(t,1,n){
		rep(i,0,n)rep(j,1,n-i)
			poly[t][i+j]=(poly[t][i+j]+1LL*poly[t-1][i]*fac[j])%mo;
	}
	rep(i,1,n){
		ans[i]=g[i];
		rep(j,4,i-1)ans[i]=(ans[i]-1LL*ans[j]*poly[j][i])%mo;
		ans[i]=(ans[i]+mo)%mo;
	}
	ans[1]=1;ans[2]=2;
	while(T--){
		int x;read(x);printf("%d\n",ans[x]);
	}
	return 0;
}