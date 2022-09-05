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
const int N = 1233,mo=998244353;
int n,k,res,a[N],dp[N][N];
int main() {
	read(n);read(k);rep(i,1,n)read(a[i]);
	int mx=0;rep(i,1,n)umax(mx,a[i]);
	sort(a+1,a+n+1);
	rep(ans,1,mx/(k-1)){
		rep(i,0,k)rep(j,0,n)dp[i][j]=0;
		dp[0][0]=1;
		rep(j,1,k){
			for(int i=1,p=0,tot=dp[j-1][0];i<=n;i++){
				while(a[i]-a[p+1]>=ans)p++,tot=tot+dp[j-1][p]<mo?tot+dp[j-1][p]:tot+dp[j-1][p]-mo;
				dp[j][i]=tot;
			}
		}
		ll tot=0;rep(i,1,n)tot+=dp[k][i];
		res=(res+tot)%mo;
	//	cerr<<ans<<' '<<dp[k][n]<<endl;
	}
	printf("%d",res);
	return 0;
}