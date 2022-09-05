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
typedef pair<ll,ll> Pll;
typedef vector<ll> Vll;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
//const int N = ;
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
Vll a(4,0),b(4,0);ll c,d;//x-->xc+d
vector<Pll>res;
void move(ll &x, ll &y){
	if(x==y)return;
	res.pb(Pll(x,y));
	x=2*y-x;
}
vector<Pll> solve(Vll &a){
	res.clear();
	while(a[3]-a[0]>1){
	//	cerr<<a[3]-a[0]<<endl;
	//	rep(i,0,3)printf("%lld ",a[i]-a[0]);puts("");
		bool ok=0;
		rep(i,1,2)if(a[i]>=(3*a[0]+a[3])/4.0&&a[i]<=(a[0]+3*a[3])/4.0){
			ok=1;
			if(a[i]<=(a[0]+a[3])/2.0){
				rep(j,0,i-1)move(a[j],a[i]);
			}
			else{
				rep(j,i+1,3)move(a[j],a[i]);
			}
			break;
		}
		if(!ok){
			if(min(a[2]-a[0],a[3]-a[2])<min(a[1]-a[0],a[3]-a[1]))swap(a[1],a[2]);
			if(a[1]<=(a[0]+a[3])/2.0&&a[2]<=(a[0]+a[3])/2.0){
				move(a[1],a[0]);move(a[1],a[2]);
			}
			else if(a[1]<=(a[0]+a[3])/2.0&&a[2]>=(a[0]+a[3])/2.0){
				move(a[1],a[2]);move(a[1],a[3]);
			}
			else if(a[1]>=(a[0]+a[3])/2.0&&a[2]<=(a[0]+a[3])/2.0){
				move(a[1],a[2]);move(a[1],a[0]);
			}
			else if(a[1]>=(a[0]+a[3])/2.0&&a[2]>=(a[0]+a[3])/2.0){
				move(a[1],a[3]);move(a[1],a[2]);
			}
			else assert(0);
		}
		sort(ALL(a));
	}
	if(a[0]&1){
		assert(~a[3]&1);
		rep(i,0,3)if(a[i]&1)move(a[i],a[3]);
	}
	sort(ALL(a));assert(a[3]-a[0]==1);
	return res;
}
vector<Pll> rev(vector<Pll>a){
	res.clear();
	per(i,SZ(a)-1,0)res.pb(Pll(2*a[i].se-a[i].fi,a[i].se));
	return res;
}
vector<Pll> solve2(Vll &a, Vll &b){
	res.clear();
	ll delta=b[0]-a[0];rep(i,1,3)assert(b[i]-a[i]==delta);
	assert(~delta&1);
	while(a[3]-a[0]<=delta){
		move(a[2],a[0]);move(a[1],a[3]);
		sort(ALL(a));
	}
	while(a[3]-a[0]>=1){
		while(2*(a[3]-a[0])<=delta){
			delta-=2*(a[3]-a[0]);
			move(a[0],a[3]);move(a[1],a[3]);move(a[2],a[3]);
			move(a[3],a[0]);move(a[2],a[0]);move(a[1],a[0]);
			sort(ALL(a));
		}
		if(a[3]-a[0]==1)break;
		move(a[0],a[1]);move(a[3],a[2]);
		sort(ALL(a));
	}
	return res;
}
int main() {
	static ll aa[6],bb[6];
	rep(i,0,3)read(a[i]),aa[i]=a[i];
	rep(i,0,3)read(b[i]),bb[i]=b[i];
	sort(ALL(a));sort(ALL(b));
	if(a[0]==a[3]||b[0]==b[3]){
		rep(i,0,3)if(a[i]!=b[i]){puts("-1");return 0;}
		puts("0");return 0;
	}
	ll g=gcd(gcd(a[1]-a[0],a[2]-a[0]),a[3]-a[0]);
	ll G=gcd(gcd(b[1]-b[0],b[2]-b[0]),b[3]-b[0]);
	if(g!=G||(a[0]-b[0])%g){puts("-1");return 0;}
	c=g;d=(a[0]%g+g)%g;
	rep(i,0,3)a[i]=(a[i]-d)/g,b[i]=(b[i]-d)/g;
	
//	rep(i,0,3)printf("%lld ",a[i]-a[0]);puts("");
//	rep(i,0,3)printf("%lld ",b[i]-b[0]);puts("");
	
	int re=0;rep(i,0,3)re+=a[i]&1,re-=b[i]&1;
	if(re){puts("-1");return 0;}
	vector<Pll>A=solve(a);
	vector<Pll>B=rev(solve(b));
	vector<Pll>C;
	if(a[0]<=b[0])C=solve2(a,b);
	else{C=rev(solve2(b,a));}
	for(auto x:C)A.pb(x);
	for(auto x:B)A.pb(x);
	printf("%d\n",SZ(A));
	for(auto x:A)printf("%lld %lld\n",x.fi*c+d,x.se*c+d);
	for(auto x:A){
		ll a=x.fi*c+d,b=x.se*c+d;bool ok=0;
		assert(a!=b);
		rep(i,0,3)rep(j,0,3)if(aa[i]==a&&aa[j]==b&&!ok){
			ok=1;aa[i]=aa[j]*2-aa[i];
			break;
		}
		assert(ok);
	}
	sort(aa,aa+4);sort(bb,bb+4);
	rep(i,0,3)assert(aa[i]==bb[i]);
	return 0;
}