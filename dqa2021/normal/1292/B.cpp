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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
const ll INF=5e16;

ll X[128],Y[128]; int n;
ll a,b,c,d;

ll getdis(ll x,ll y,ll X,ll Y){
	return abs(x-X)+abs(y-Y);
}

void solve(){
	X[0]=read(),Y[0]=read();
	a=read(),b=read(),c=read(),d=read();
	ll x=read(),y=read(),t=read();
	while (X[n]*a+c<=INF&&Y[n]*b+d<=INF){
		X[n+1]=X[n]*a+c;
		Y[n+1]=Y[n]*b+d;
		++n;
		//printf("test %d: %lld %lld\n",n,X[n],Y[n]);
	}
	//puts("test");
	int ans=0;
	rep(l,0,n) rep(r,l,n){
		bool ok=0;
		rep(k,l,r){
			ok=ok||getdis(x,y,X[k],Y[k])+getdis(X[k],Y[k],X[l],Y[l])+getdis(X[l],Y[l],X[r],Y[r])<=t;
			ok=ok||getdis(x,y,X[k],Y[k])+getdis(X[k],Y[k],X[r],Y[r])+getdis(X[l],Y[l],X[r],Y[r])<=t;
		}
		if (ok) ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}