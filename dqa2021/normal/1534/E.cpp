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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
#define F fflush(stdout)

int n,k;
int c[512];

bool check(int o,bool tp=0){
	int T=o; o*=k;
	if (o<n) return 0;
	if ((o-n)&1) return 0;
	fill(c+1,c+n+1,1); o-=n;
	o>>=1; int b=o/n,h=o%n;
	rep(i,1,n){
		if (i<=h) c[i]+=b+1<<1,o-=b+1;
		else c[i]+=b<<1,o-=b;
	}
	assert(!o);
	static P p[512];
	rep(i,1,n) p[i]={c[i],i};
	int z=0;
	while (T--){
		nth_element(p+1,p+k,p+n+1,greater<P>());
		rep(i,1,k) if (!(p[i].fi--)) return 0;
		if (tp){
			printf("? ");
			rep(i,1,k) printf("%d ",p[i].se);
			puts("");
			F; z^=read();
		}
	}
	if (tp){
		printf("! %d\n",z);
		F;
	}
	return 1;
}

void solve(){
	n=read(),k=read();
	int l=1,r=251,mid;
	while (l<r){
		mid=l+r>>1;
		if (check(mid-1<<1|1)) r=mid;
		else l=mid+1;
	}
	int O=l-1<<1|1; l=1,r=251;
	while (l<r){
		mid=l+r>>1;
		if (check(mid<<1)) r=mid;
		else l=mid+1;
	}
	int E=l<<1;
	if (min(O,E)>500) return puts("-1"),F,void();
	assert(check(min(O,E),1));
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}