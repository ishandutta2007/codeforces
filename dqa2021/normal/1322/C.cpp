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
ull getrand(){
	static ull sd=574865423500258962ULL;
	return sd^=sd>>13,sd^=sd<<44,sd^=sd>>38,sd^=sd<<19;
}
#define gcd __gcd

int n,m;
ll c[500010];
ull L[500010],R[500010];
//ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

vector<int> e[500010];

void solve(){
	n=read(),m=read();
	rep(i,1,n) c[i]=read();
	rep(i,1,n) L[i]=getrand(),e[i].clear();
	rep(i,1,n) R[i]=0;
	while (m--){
		int u=read(),v=read();
		e[u].pb(v);
	}
	ll S=0;
	rep(i,1,n){
		map<ull,ll> mp;
		for (int j: e[i]) mp[R[j]]+=c[j];
		for (auto it: mp) S=gcd(S,it.se);
		for (int j: e[i]) R[j]^=L[i];
	}
	printf("%lld\n",S);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}