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
const int N = 2066,mo=998244353;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
int n,k,ans;
inline bool isgg(Vi a){
	static int b[N];b[SZ(a)]=0;int res=0;
	per(i,SZ(a)-1,0)b[i]=b[i+1]+a[i],res+=b[i]*(b[i]+1);
	return res>n*2;
}
bool ck(Vi a){
	if(isgg(a))return 0;
	rep(t,1,k-3){
		Vi b;
		per(i,SZ(a)-1,0)rep(j,1,a[i])b.pb(i+1);
		a=b;
		if(isgg(a))return 0;
	}
	return 1;
}
void dfs(Vi a, int mx){
//	if(!ck(a))return;
	if(SZ(a))ans++;
	rep(i,1,mx){
		a.pb(i);if(!ck(a))break;dfs(a,i);a.pop_back();
	}
}
int main() {
	read(n);read(k);
	if(k==1){
		static int dp[N];dp[0]=1;
		rep(i,1,n)rep(j,0,n-i)add(dp[j+i],dp[j]);
		int res=0;rep(i,1,n)add(res,dp[i]);
		cout<<res;return 0;
	}
	if(k==2){
		static int dp[N][N];dp[0][0]=1;
		per(i,n,1)rep(j,0,n/i)rep(k,0,n-i*(j+1))add(dp[j+1][k+i*(j+1)],dp[j][k]);
		int res=0;rep(i,1,n)rep(j,1,n)add(res,dp[i][j]);
		cout<<res;return 0;
	}
	dfs({},64);cout<<ans;
	return 0;
}