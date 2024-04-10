#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
typedef pair<ll,ll> P;
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
const ll INF=1e18;

int n;
P w[100010];
ll f[100010],g[100010];
ll h[100010];

void ins(int x,ll v){
	for (;x<=n;x+=x&-x)
		h[x]=min(h[x],v);
}
ll ask(int x){
	ll z=INF;
	for (;x;x-=x&-x)
		z=min(z,h[x]);
	return z;
}

ll solve(){
	n=read();
	rep(i,1,n) w[i].fi=read(),w[i].se=read();
	sort(w+1,w+n+1);
	ll ans=0;
	rep(i,1,n) ans+=w[i].se;
	//if (w[1].fi+w[1].se>=w[n].fi) return ans;
	memset(h,0x3f,sizeof h);
	g[n+1]=INF; f[n]=0,g[n]=w[n].fi;
	ins(n,f[n]);
	per(i,1,n-1){
		int j=lower_bound(w+i+1,w+n+1,P(w[i].fi+w[i].se,0))-w;
		f[i]=min(ask(j-1),g[j]-w[i].fi-w[i].se);
		g[i]=min(g[i+1],f[i]+w[i].fi);
		ins(i,f[i]);
		//printf("%d: j %d f %lld\n",i,j,f[i]);
	}
	ans+=f[1];
	return ans;
}

int main()
{
	for (int T=1;T--;) printf("%lld\n",solve());
	return 0;
}