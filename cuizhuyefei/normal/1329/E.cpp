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

const int N = 466666;
ll n,m,k,a[N];
bool ck(ll l, ll r){
	ll mn=0,mx=0;
	rep(i,1,m){
		ll x=(a[i]+r-1)/r,y=a[i]/l;
		if(x>y)return 0;mn+=x;mx+=y;
	}
	return mn<=k&&k<=mx;
}
int main() {
int T;read(T);while(T--){
	read(n);read(m);read(k);
	rep(i,1,m)read(a[i]);a[m+1]=n;
	per(i,m+1,1)a[i]-=a[i-1];m++;k+=m;
	sort(a+1,a+m+1);
	ll res=1e18;
	ll lo=1,hi=1e15;
	while(lo<hi){
		ll mid=(lo+hi)/2;
		if(ck(1,mid))hi=mid;else lo=mid+1;
	}
	ll r=lo;
	lo=1,hi=1e15;
	while(lo<hi){
		ll mid=(lo+hi+1)/2;
		if(ck(mid,1e15))lo=mid;else hi=mid-1;
	}
	ll l=lo;
	assert(l<=r);
	static Pll s[N];int len=0;
	rep(i,1,m){
		ll x=(a[i]+r-1)/r,y=a[i]/l;
		if(x>y){
			x=(a[i]+l-1)/l;y=a[i]/r;
			s[++len]=mp(x>=1&&x<=a[i]?l-a[i]/x:1e18,y>=1&&y<=a[i]?(a[i]+y-1)/y-r:1e18);
		}
	}
	if(!len)res=r-l;
	else{
		sort(s+1,s+len+1);res=1e18;
		rep(i,1,len)assert(s[i].fi>0&&s[i].se>0);
		for(ll i=len,j=0;i>=0;i--){
			umin(res,j+s[i].fi+r-l);
			umax(j,s[i].se);
		}
	}
	printf("%lld\n",res);
}
	return 0;
}