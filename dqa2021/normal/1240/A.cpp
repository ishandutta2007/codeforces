#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
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
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,p[200010];
int g[200010];

ll check(int t){
	static int h[200010];
	rep(i,1,t) h[i]=g[i];
	sort(h+1,h+t+1,greater<int>());
	ll z=0;
	rep(i,1,t) z+=p[i]*1LL*h[i];
	return z;
}

void solve(){
	n=read();
	rep(i,1,n) p[i]=read()/100,g[i]=0;
	sort(p+1,p+n+1,greater<int>());
	int x=read(),a=read(),y=read(),b=read();
	ll k=read();
	rep(i,1,n/a) g[i*a]+=x;
	rep(i,1,n/b) g[i*b]+=y;
	int l=1,r=n+1,mid;
	while (l<r){
		mid=l+r>>1;
		if (check(mid)>=k) r=mid;
		else l=mid+1;
	}
	if (l==n+1) l=-1;
	printf("%d\n",l);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}