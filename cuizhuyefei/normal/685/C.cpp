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
const int N = 266666;const ll inf = 3e18;
struct dot{
	ll x,y,z;
	dot(ll X=0,ll Y=0,ll Z=0){x=X;y=Y;z=Z;}
}f[N],Ans;ll ans;
int n;
void upd(Pll &a, Pll b){a=Pll(max(a.fi,b.fi),min(a.se,b.se));}
bool isnul(Pll a){return a.fi>a.se;}
void fit(Pll &a, int tp){if(a.fi+tp&1)a.fi++;if(a.se+tp&1)a.se--;}
bool ck(Pll a, Pll b, Pll c, Pll s, int tp){
	fit(a,tp);fit(b,tp);fit(c,tp);fit(s,tp);
//	cerr<<"OwO "<<s.fi<<' '<<s.se<<endl;
	if(isnul(s)||isnul(a)||isnul(b)||isnul(c))return 0;
//	cerr<<"OwO\n";
	Pll sum=Pll(a.fi+b.fi+c.fi,a.se+b.se+c.se);
	if(sum.se<s.fi||sum.fi>s.se)return 0;
//	cerr<<"OwO\n";
	ll X=a.fi,Y=b.fi,Z=c.fi;ll need=max(s.fi-sum.fi,0LL);
	if(a.se-a.fi<=need)need-=a.se-a.fi,X=a.se;else X+=need,need=0;
	if(b.se-b.fi<=need)need-=b.se-b.fi,Y=b.se;else Y+=need,need=0;
	if(c.se-c.fi<=need)need-=c.se-c.fi,Z=c.se;else Z+=need,need=0;
	ll S=X+Y+Z;
	Ans.x=(S-Z)/2;Ans.y=(S-Y)/2;Ans.z=(S-X)/2;
	return 1;
}
bool ck(ll d){
	Pll a(-inf,inf),b(-inf,inf),c(-inf,inf),s(-inf,inf);
	rep(i,1,n){
		ll x=f[i].x,y=f[i].y,z=f[i].z;
		upd(s,Pll(-d+x+y+z,d+x+y+z));
		upd(a,Pll(-d+x+y-z,d+x+y-z));
		upd(b,Pll(-d+x-y+z,d+x-y+z));
		upd(c,Pll(-d-x+y+z,d-x+y+z));
	}
	if(isnul(s)||isnul(a)||isnul(b)||isnul(c))return 0;
	if(ck(a,b,c,s,0))return 1;
	if(ck(a,b,c,s,1))return 1;
	return 0;
}
int main() {
	int T;read(T);while(T--){
		read(n);rep(i,1,n)read(f[i].x),read(f[i].y),read(f[i].z);
		ans=6e18;ll l=0,r=inf;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(ck(mid))ans=mid,r=mid-1;else l=mid+1;
		}
		printf("%lld %lld %lld\n",Ans.x,Ans.y,Ans.z);
	}
	return 0;
}