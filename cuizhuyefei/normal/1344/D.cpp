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

const int N = 666666;
int n,a[N],x[N];ll k;
ll calc(int i, ll x){return a[i]-3*x*x+3*x-1;}
ll calc(ll lim){
	ll res=0;
	rep(i,1,n){
		int l=0,r=a[i];
		while(l<r){
			int mid=(l+r+1)/2;
			if(calc(i,mid)>=lim)l=mid;else r=mid-1;
		}
		res+=l;x[i]=l;
	}
	return res;
}
int main() {
	read(n);read(k);
	rep(i,1,n)read(a[i]);
	ll l=-4e18,r=4e9;
	while(l<r){
		ll mid=(l+r)/2;
		if(l+1==r)mid=l;
		if(calc(mid)<=k)r=mid;else l=mid+1;
	}
	ll need=k-calc(l);
	rep(i,1,n)if(need&&x[i]+1<=a[i]&&calc(i,x[i]+1)==l-1)x[i]++,need--;
	rep(i,1,n)printf("%d ",x[i]);
	return 0;
}