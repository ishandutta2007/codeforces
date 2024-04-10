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
mt19937 R(chrono::system_clock().now().time_since_epoch().count());
const int N = 666666,mo1=1e9+7,mo2=1e9+9,b1=19260817,b2=10007;
int n,m;ll c[N];Pii a[N];
int mi1[N],mi2[N];
map<Pii,ll>Map;
int main() {
	int T;read(T);while(T--){
		read(n);read(m);
		rep(i,1,n)read(c[i]),a[i]=mp(0,0);
		mi1[0]=mi2[0]=1;
		rep(i,1,n)mi1[i]=1ll*mi1[i-1]*b1%mo1,mi2[i]=1ll*mi2[i-1]*b2%mo2;
		rep(i,1,m){
			int x,y;read(x);read(y);
			a[y]=mp((a[y].fi+mi1[x])%mo1,(a[y].se+mi2[x])%mo2);
		}
		Map.clear();
		rep(i,1,n)if(a[i].fi||a[i].se)Map[a[i]]+=c[i];
		ll res=0;
		for(auto x:Map)res=gcd(res,x.se);printf("%lld\n",res);
	}
	return 0;
}