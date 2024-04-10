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
typedef vector<int> Vi;
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
ll l1,r1,l2,r2;
vector<Pll>dot;
inline ld getarea(ll l1, ll r1, ll l2, ll r2){
	static Pll a[666];int len=0;
	for(auto x:dot)if(x.fi<=r1&&x.se<=r2)a[++len]=mp(max(x.fi,l1),max(x.se,l2));
//	sort(a+1,a+len+1);
	ld res=0;
	int sz=0;a[0]=mp(l1,r2+1);
	rep(i,1,len)if(a[i].se<a[sz].se)
		res+=(ld)(a[i].fi-l1)*(a[sz].se-a[i].se),a[++sz]=a[i];
	res+=(ld)(r1-l1+1)*(a[sz].se-l2);
	return res;
}

/*ll X=5.166e17,Y=4.157762e17;
ll qry(ll x, ll y){
	if(x==X&&y==Y)return 0;
	if(x<X)return 1;
	if(y<Y)return 2;
	if(x>X||y>Y)return 3;
	assert(0);
}*/
int main() {
	/*ld x=1e18;
	ld y=x*x-(x-1)*(x-1);
	double z=y;
	printf("%lf\n",z);*/
	
	
	ll lim;read(lim);
	l1=l2=1;r1=r2=lim;
	while(1){
		ll lo=l1,hi=r1;ld tot=getarea(l1,r1,l2,r2);assert(tot>=0);
		while(lo<hi){
			ll mid=(lo+hi+1)>>1;
			if(getarea(mid,r1,l2,r2)>=2.0/3*tot)lo=mid;else hi=mid-1;
		}
		ll x=lo;
		lo=l2;hi=r2;
		while(lo<hi){
			ll mid=(lo+hi+1)>>1;
			if(getarea(l1,r1,mid,r2)>=2.0/3*tot)lo=mid;else hi=mid-1;
		}
		ll y=lo;printf("%lld %lld\n",x,y);fflush(stdout);
		int ans;
		read(ans);
	//	ans=qry(x,y);printf("ans=%d\n",ans);
		if(!ans)return 0;
		if(ans==1)l1=x+1;
		if(ans==2)l2=y+1;
		if(ans==3){dot.pb(mp(x,y));sort(ALL(dot));}
		/*if(!(getarea(l1,r1,l2,r2)<=(ld)2/3*tot+1)){
			printf("%d %lf\n",ans,(double)(getarea(l1,r1,l2,r2)/tot));
			printf("%d\n",ans);
			printf("%lf\n",(double)getarea(l1,r1,l2,r2));
			return 0;
		}*/
	//	assert(getarea(l1,r1,l2,r2)<=(ld)2/3*tot+1);
	}
	return 0;
}