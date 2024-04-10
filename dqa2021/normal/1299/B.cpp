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

int n;
struct P{
	ll x,y;
}p[100010];
P operator-(const P &x,const P &y){
	return P{x.x-y.x,x.y-y.y};
}
ll cross(const P &x,const P &y){
	return x.x*y.y-x.y*y.x;
}
ll dot(const P &x,const P &y){
	return x.x*y.x+x.y*y.y;
}
ll dot(const P &x){
	return x.x*x.x+x.y*x.y;
}

bool solve(){
	n=read();
	rep(i,1,n){
		int x=read(),y=read();
		p[i]=P{x,y};
	}
	p[n+1]=p[1];
	if (n&1) return 0;
	int m=n>>1;
	rep(i,1,m){
		if (cross(p[i+m+1]-p[i+m],p[i+1]-p[i])) return 0;
		if (dot(p[i+m+1]-p[i+m],p[i+1]-p[i])>=0) return 0;
		if (dot(p[i+m+1]-p[i+m])!=dot(p[i+1]-p[i])) return 0;
	}
	return 1;
}

int main()
{
	for (int T=1;T--;) puts(solve()?"yes":"no");
	return 0;
}