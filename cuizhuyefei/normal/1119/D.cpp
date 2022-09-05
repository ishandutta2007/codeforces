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
typedef pair<ll,ll> Pll;
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
const int N = 402000;const ll inf = 4e18;
int n,q;ll a[N],ans[N];int len;Pll s[N];
bool cmp(Pll x,Pll y){return x.se!=y.se?x.se<y.se:x.fi<y.fi;}
int main() {
	read(n);rep(i,1,n)read(a[i]);sort(a+1,a+n+1);a[n+1]=inf;
	read(q);rep(i,1,q){ll l,r;read(l);read(r);s[++len]=Pll(i,r-l+1);}
	rep(i,1,n)s[++len]=Pll(-i,a[i+1]-a[i]);
	sort(s+1,s+len+1,cmp);
	ll k=n,b=0;
	rep(i,1,len)
		if(s[i].fi<0)k--,b+=s[i].se;
		else ans[s[i].fi]=k*s[i].se+b;
	
	rep(i,1,q)printf("%lld ",ans[i]);
	return 0;
}