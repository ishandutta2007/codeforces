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

//const int N = ;
ll f(ll x){
	ll mn=9,mx=0,y=x;
	while(y){ll z=y%10;y/=10;umax(mx,z);umin(mn,z);}
	return x+mn*mx;
}
int main() {
	ll t;read(t);while(t--){
		ll s,k;read(s);read(k);k--;
		while(k&&f(s)!=s)s=f(s),k--;
		printf("%lld\n",s);
	}
	/*ll x=487;
	rep(i,1,100){
		x=f(x);printf("%d:%lld\n",i,x);
	}*/
	return 0;
}