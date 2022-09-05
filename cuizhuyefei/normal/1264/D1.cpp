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
const int N = 1e6+100, mo = 998244353, inv2 =(mo+1)/2;
const ll MOD=7LL*mo*mo;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}

int dp[N],fac[N],ifac[N],res,n,qz[N],hz[N],wen[N];char s[N];
void iniC(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);
	per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
}
inline int C(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo:0;}
int qry(int x){return x>=0?dp[x]:dp[0];}
int main() {
	iniC(N-1);scanf("%s",s+1);n=strlen(s+1);
	int tot=0;rep(i,1,n)tot+=s[i]=='?';
	rep(i,0,tot)dp[i]=C(tot,i);
	per(i,tot-1,0)add(dp[i],dp[i+1]);
	rep(i,1,n)qz[i]=qz[i-1]+(s[i]=='('),wen[i]=wen[i-1]+(s[i]=='?');
	per(i,n,1)hz[i]=hz[i+1]+(s[i]==')');
	
	rep(i,1,n)if(s[i]=='('){
		add(res,qry(qz[i]-hz[i+1]+wen[i]));
	}
	
	tot--;memset(dp,0,sizeof(dp));
	rep(i,0,tot)dp[i]=C(tot,i);
	per(i,tot-1,0)add(dp[i],dp[i+1]);
	
	rep(i,1,n)if(s[i]=='?'){
		add(res,qry(qz[i]+1-hz[i+1]+wen[i]-1));
	}
	
	cout<<res;
	return 0;
}