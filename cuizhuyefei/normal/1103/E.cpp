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
const int N = 202000;
const ll mo = 1LL<<58;
struct node{
	ll a[5];node(){memset(a,0,sizeof(a));}
	inline void operator +=(const node &x){
		rep(i,0,4)a[i]+=x.a[i];
	}
}a[N],w[11];

inline node operator *(const node&a, const node&b){
	node c;
	rep(i,0,4)if(a.a[i])rep(j,0,4)c.a[i+j<5?i+j:i+j-5]+=a.a[i]*b.a[j]*(i+j>=5?-1:1);
	return c;
}
inline void fwt(node *a, int n, int tp){
	for(int j=10;j<=n;j*=10)
		for(int k=0;k<n;k+=j){
			//a[k+i+j/10*(0..9)]
			rep(i,0,j/10-1){
				node b[10],c[10];
				rep(p,0,9)b[p]=a[k+i+j/10*p];
				rep(x,0,9)rep(y,0,9)c[x]+=w[(x*y*tp%10+10)%10]*b[y];
				rep(p,0,9)a[k+i+j/10*p]=c[p];
			}
		}
}
inline node power(node a, int n){
	node res;res.a[0]=1;
	while(n){
		if(n&1)res=res*a;
		a=a*a;n>>=1;
	}
	return res;
}
void exgcd(ll a, ll b, ll &x, ll &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);y-=a/b*x;
}
ll inv(ll a){ll x,y;exgcd(a,mo,x,y);return x>=0?x:x+mo;}
int main() {
	rep(i,0,9){
		if(i<=4)w[i].a[i]=1;else w[i].a[i-5]=-1;
	}
	/*rep(i,0,9)rep(j,0,9){
		node x;
		rep(k,0,9)x+=w[(1000-i*k)%10]*w[j*k%10];
		rep(k,0,4)printf("%d %d %d:%lld\n",i,j,k,x.a[k]);
	}*/
	int n;read(n);int mx=0;
	rep(i,1,n){
		int x;read(x);a[x].a[0]++;umax(mx,x);
	}
	int m;for(m=1;m<=mx;m*=10);
	fwt(a,m,1);
	/*rep(i,0,n-1){
		rep(j,0,4)printf("%lld ",a[i].a[j]);puts("");
	}
	return 0;*/
	/*rep(i,0,m-1){
		rep(j,0,4)printf("%lld ",a[i].a[j]);puts("");
	}
	puts("");*/
	rep(i,0,m-1)a[i]=power(a[i],n);
	fwt(a,m,-1);
	ll mi5=1,mi2=1;for(int i=10;i<=m;i*=10)mi5*=5,mi2*=2;
	ll inv5=inv(mi5);
	rep(i,0,n-1){
		/*rep(j,0,4){
		//	a[i].a[j]=a[i].a[j]*inv(mi5);
		//	assert(a[i].a[j]%mi2==0);a[i].a[j]/=mi2;
		}*/
		//rep(j,0,4)printf("%lld ",a[i].a[j]);puts("");
		ll x=a[i].a[0]+a[i].a[1];//printf("%lld\n",(x%mo+mo)%mo);
		x=x*inv5;assert(x%mi2==0);x/=mi2;printf("%lld\n",(x%mo+mo)%mo);
		
	}
	return 0;
}