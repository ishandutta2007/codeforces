#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define gcd __gcd

int n,m; ll k;
int a[500010],b[500010];
int p[1000010],q[1000010];
ll s[500010];

void exgcd(ll a,ll b,ll &x,ll &y){
	if (b) exgcd(b,a%b,y,x),y-=a/b*x;
	else x=1,y=0;
}

void solve(){
	n=read(),m=read(),k=read();
	rep(i,1,n)a[i]=read(),p[a[i]]=i;
	rep(i,1,m)b[i]=read(),q[b[i]]=i;
	ll tot=0; int g=gcd(n,m); ll lcm=ll(n)/g*m;
	vector<ll> S;
	rep(i,1,n){
		tot+=m/g;
		if (q[a[i]]&&q[a[i]]%g==i%g){
			--tot;
			ll a=(-n%m+m)%m,b=m,c=((i-q[::a[i]])%m+m)%m,x,y,A=-n,B=m,C=i-q[::a[i]];
			a/=g,b/=g,c/=g;
			exgcd(a,b,x,y);
			x=(x+b)%b;
			x=x*c%b; y=(C-A*x)/B;
			//printf("test x %lld y %lld\n",x,y);
			if (y<0){
				ll t=(-y+a-1)/a;
				x+=b*t,y+=a*t;
			}
			s[i]=i+x*n;
			S.pb(s[i]);
			//printf("test %d: s %lld x %lld y %lld\n",i,s[i],x,y);
		}
	}
	ll ans=(k-1)/tot*lcm;
	k-=(k-1)/tot*tot;
	//printf("k' %lld ans' %lld\n",k,ans);
	//sort(all(S));
	ll l=1,r=lcm,mid;
	while (l<r){
		mid=l+r>>1;
		ll t=mid;
		for (ll x: S) if (x<=mid) --t;
		if (t>=k) r=mid;
		else l=mid+1;
	}
	ans+=l;
	printf("%lld\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}