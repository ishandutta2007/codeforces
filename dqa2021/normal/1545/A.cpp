#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
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

int n,m,a[100010],b[100010];
int tri[100010];
void add(int x){
	for (;x<=m;x+=x&-x) ++tri[x];
}
int ask(int x){
	int z=0;
	for (;x;x-=x&-x) z+=tri[x];
	return z;
}
int c[100010],d[100010];

bool solve(){
	n=read();
	rep(i,1,n) a[i]=read();
	m=*max_element(a+1,a+n+1);
	memset(tri,0,sizeof tri);
	rep(i,1,n){
		b[i]=ask(m)-ask(a[i]);
		add(a[i]);
	}
	memset(tri,0,sizeof tri);
	per(i,1,n){
		b[i]+=ask(a[i]-1);
		add(a[i]);
	}
	memset(c,0,sizeof c);
	rep(i,1,m) d[i]=1;
	rep(i,1,n){
		int x=a[i];
		c[x]+=d[x]*(b[i]&1);
		d[x]=-d[x];
	}
	rep(i,1,m) if (c[i]) return 0;
	return 1;
}

int main()
{
	for (int T=read();T--;) puts(solve()?"YES":"NO");
	return 0;
}