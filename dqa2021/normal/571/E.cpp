#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef __int128 lll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
const ll INF=1e18;
typedef vector<ll> V;
typedef pair<V,V> P;

int n;

vector<ll> getdiv(ll x){
	V z;
	for (ll i=2;i*i<=x;++i)
		if (x%i==0){
			z.pb(i);
			while (x%i==0) x/=i;
		}
	if (x^1) z.pb(x);
	return z;
}

vector<ll> getdiv(ll x,const V &S){
	V T;
	for (const ll &d: S){
		int tot=0;
		while (x%d==0) x/=d,++tot;
		T.pb(tot);
	}
	return T;
}

V merge(V x,V y){
	x.insert(x.end(),y.begin(),y.end());
	sort(x.begin(),x.end());
	x.resize(unique(all(x))-x.begin());
	return x;
}

ll a[4][4],b[4];

ll c[4],d;

void ins(ll x,ll y,ll z){
	c[1]=x,c[2]=y,d=z;
	rep(e,1,2){
		if (!c[e]) continue;
		if (!a[e][e]){
			rep(i,1,2) a[e][i]=c[i]; b[e]=d;
			return;
		}
		if (c[e]<0){
			rep(i,1,2) c[i]=-c[i]; d=-d;
		}
		while (c[e]){
			const ll t=a[e][e]/c[e];
			rep(i,1,2) a[e][i]-=c[i]*t; b[e]-=d*t;
			rep(i,1,2) swap(c[i],a[e][i]); swap(b[e],d);
		}
	}
	if (d) puts("-1"),exit(0);
}

void exgcd(ll a,ll b,ll &g,ll &x,ll &y){
	if (b) exgcd(b,a%b,g,y,x),y-=a/b*x;
	else g=a,x=1,y=0;
}

P merge(P x,P y){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	rep(i,0,x.fi.size()-1) ins(x.se[i],-y.se[i],-x.fi[i]+y.fi[i]);
	int tot=0;
	rep(i,1,2) tot+=a[i][i]!=0;
	if (!tot) return x;
	if (tot==2){
		if (b[2]%a[2][2]) puts("-1"),exit(0);
		ll v=b[2]/a[2][2];
		if (v<0) puts("-1"),exit(0);
		b[1]-=v*a[1][2]; a[1][2]=0;
		if (b[1]%a[1][1]) puts("-1"),exit(0);
		ll u=b[1]/a[1][1];
		if (u<0) puts("-1"),exit(0);
		P z;
		rep(i,0,x.fi.size()-1) z.fi.pb(x.fi[i]+x.se[i]*u),z.se.pb(0);
		return z;
	}
	ll A,B,C;
	if (a[1][1]) A=a[1][1],B=a[1][2],C=b[1];
	else A=a[2][1],B=a[2][2],C=b[2];
	if (!A) swap(A,B),swap(x,y);
	if (!B){
		if (C%A) puts("-1"),exit(0);
		ll u=C/A;
		if (u<0) puts("-1"),exit(0);
		P z;
		rep(i,0,x.fi.size()-1) z.fi.pb(x.fi[i]+x.se[i]*u),z.se.pb(0);
		return z;
	}
	if (A<0) A=-A,B=-B,C=-C;
	assert(B<0);
	const V &M=x.fi,&N=x.se;
	{
	ll a=A,b=B,c=C,g,x,y;
	if (b<0) a=-a,b=-b,c=-c;
	a=(a%b+b)%b;
	c=(c%b+b)%b;
	exgcd(a,b,g,x,y);
	if (c%g) puts("-1"),exit(0);
	a/=g,b/=g,c/=g;
	x=(x+b)%b;
	x=lll(x)*c%b;
	ll k;
	if (C-lll(A)*x<0) k=0;
	else k=(C-lll(A)*x+lll(A)*b-1)/(lll(A)*b);
	x+=b*k;
	P z;
	rep(i,0,M.size()-1) z.fi.pb(M[i]+N[i]*x),z.se.pb(N[i]*b);
	return z;
	}
}

void solve(){
	static ll a[110],b[110];
	n=read();
	rep(i,1,n) a[i]=read(),b[i]=read();
	{
	ll ans=INF;
	rep(i,1,n){
		bool f=1;
		const ll V=a[i];
		rep(j,1,n){
			if (V%a[j]){f=0;break;}
			if (a[j]!=V&&b[j]==1){f=0;break;}
			ll U=V/a[j]; while (U!=1&&U%b[j]==0) U/=b[j];
			if (U!=1){f=0;break;}
		}
		if (f) ans=min(ans,V);
	}
	if (ans^INF) printf("%lld\n",ans),exit(0);
	}
	auto S=merge(getdiv(a[1]),getdiv(b[1]));
	rep(i,2,n){
		const auto T=merge(getdiv(a[i]),getdiv(b[i]));
		if (S!=T) puts("-1"),exit(0);
	}
	P U(getdiv(a[1],S),getdiv(b[1],S)); //int o=1;  // 1 uncertain 2 certain
	rep(i,2,n){
		const P V(getdiv(a[i],S),getdiv(b[i],S));
		U=merge(U,V);
	}
	int ans=1;
	rep(i,0,S.size()-1) ans=1LL*ans*qpow(S[i],U.fi[i]%(mod-1))%mod;
	printf("%d\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}