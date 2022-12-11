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
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,q;
int a[200010],c[200010];
vector<int> e[200010];

int getval(int x){
	int w=0;
	if (x==e[a[x]][0]) ++w;
	if (x==e[a[x]].back()) --w;
	return w;
}

void solve(){
	n=read(),q=read();
	rep(i,1,n) ++c[a[i]=read()],e[a[i]].pb(i);
	int z=n;
	for (int l=1,r,w;l<=n;l=r+1){
		for (r=l,w=getval(r);w;w+=getval(++r));
		w=0;
		rep(i,l,r) w=max(w,c[a[i]]);
		z-=w;
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}