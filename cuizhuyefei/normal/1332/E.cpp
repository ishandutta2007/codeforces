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
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 1<<18|3, mo = 998244353, inv2 =(mo+1)/2;
const ll MOD=7LL*mo*mo;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, ll n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}

int main() {
	int n,m,l,r;read(n);read(m);read(l);read(r);
	if((n&1)&&(m&1))cout<<power(r-l+1,1ll*n*m);
	else{
		int dp[2]={0};dp[0]=1;
		int a[2][2]={0};
		a[0][0]=a[1][1]=(r-l+1)/2;
		a[0][1]=a[1][0]=r-l+1-(r-l+1)/2;
		ll t=1ll*n*m;
		while(t){
			if(t&1){
				ll f=(1ll*a[0][0]*dp[0]+1ll*a[0][1]*dp[1])%mo;
				ll g=(1ll*a[1][0]*dp[0]+1ll*a[1][1]*dp[1])%mo;
				dp[0]=f;dp[1]=g;
			}
			int b[2][2]={0};
			rep(i,0,1)rep(j,0,1)rep(k,0,1)
				b[i][k]=(b[i][k]+1ll*a[i][j]*a[j][k])%mo;
			memcpy(a,b,sizeof(b));
			t>>=1;
		}
		cout<<dp[0];
	}
	return 0;
}