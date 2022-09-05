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

const int N = 276666;
int n,a,r,m,h[N];
ll calc(ll s, int a, int r, int m){
	ll x=0,y=0;
	rep(i,1,n)if(h[i]<=s)x+=s-h[i];else y+=h[i]-s;
	return x*m+(y-x)*r;
}
ll solve(int a, int r, int m){
	ll s=0;rep(i,1,n)s+=h[i];s/=n;
	ll L=0,R=s,res=calc(s,a,r,m);
	while(L<R){
		ll mid=(L+R)/2,t=calc(mid,a,r,m);
		ll q=calc(mid+1,a,r,m);
		umin(res,min(t,q));
		if(t<=q)R=mid;else L=mid+1;
	}
	if(L<=R)umin(res,calc(L,a,r,m));return res;
}
int main() {
	read(n);read(a);read(r);read(m);umin(m,a+r);
	rep(i,1,n)read(h[i]);sort(h+1,h+n+1);
	ll res=solve(a,r,m);
	rep(i,1,n)h[i]=1e9-h[i];umin(res,solve(r,a,m));
	cout<<res;
	return 0;
}