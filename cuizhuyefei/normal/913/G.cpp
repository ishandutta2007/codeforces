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
//const int N = ;
ll a,mi10[66],mi2[66],f[66],phi[66];int n,m;
inline ll mul(ll a, ll n, ll mo){
	if(a<n)swap(a,n);ll res=0;assert(n>=0);
	while(n){
		if(n&1)res=res+a<mo?res+a:res+a-mo;
		a=a+a<mo?a+a:a+a-mo;n>>=1;
	}
	return res;
}
inline ll power(ll a, ll n, ll mo) {
	ll res=1;
	while (n) {
		if (n&1) res=mul(res,a,mo);
		a=mul(a,a,mo); n>>=1;
	}
	return res;
}
int getlen(ll x){
	int res=0;while(x)x/=10,res++;
	return res;
}
int main() {
	mi10[0]=1;rep(i,1,18)mi10[i]=10LL*mi10[i-1];
	rep(i,0,60)mi2[i]=1ll<<i;
	int T;read(T);while(T--){
		read(a);n=getlen(a);m=(n+2)/2;
		ll x=(a+1)*mi10[m];x-=x%mi2[n+m];if(x==(a+1)*mi10[m])x-=mi2[n+m];
		ll y=x>>n+m;if(y%5==0)y--;
	//	cerr<<"QwQ "<<y<<' '<<n+m<<endl;
		f[0]=1;
		static ll mi[66],phi[66];mi[0]=1;rep(i,1,n+m)mi[i]=mi[i-1]*5LL;
		phi[0]=1;rep(i,1,n+m)phi[i]=mi[i-1]*4;
		rep(i,0,n+m-1)rep(j,0,4)if(y%mi[i+1]==power(2,f[i]+phi[i]*j,mi[i+1])){
			f[i+1]=f[i]+phi[i]*j;break;
		}
		assert(power(2,f[n+m],mi[n+m])==y%mi[n+m]);
		printf("%lld\n",n+m+f[n+m]);
	}
	return 0;
}