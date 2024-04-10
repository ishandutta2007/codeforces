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
#define forall(x,y) for (const int &y: e[x])
#define gcd __gcd
bool vis[1000010];
int prm[1000010];
void sieve(int x){
	rep(i,2,x){
		if (!vis[i]) prm[++*prm]=i;
		rep(j,1,*prm){
			if (i*prm[j]>x) break;
			vis[i*prm[j]]=1;
			if (i%prm[j]==0) break;
		}
	}
}
vector<ll> work(ll l,ll r){
	static ll g[400010];
	rep(i,1,r-l+1) g[i]=i+l-1;
	rep(i,1,*prm){
		const int &x=prm[i];
		for (ll w=(l+x-1)/x*x;w<=r;w+=x)
			while (g[w-l+1]%x==0) g[w-l+1]/=x;
	}
	vector<ll> S;
	rep(i,1,r-l+1) if (g[i]>1) S.pb(g[i]);
	return S;
}

int n;
ll w[200010];
int ans=2e5;

void check(ll g){
	ll z=0;
	rep(i,1,n){
		if (w[i]<=g) z+=g-w[i];
		else z+=min(w[i]%g,g-w[i]%g);
		if (z>=ans) return;
	}
	ans=z;
}

void solve(){
	n=read();
	rep(i,1,n) w[i]=read();
	sort(w+1,w+n+1);
	sieve(1e6);
	const auto S=work(max(1LL,w[1]-n),w[1]+n);
	rep(i,1,*prm) check(prm[i]);
	for (ll x: S) check(x);
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}