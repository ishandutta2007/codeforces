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
const int INF=1e8;

int n,w[1000010],m=21,lim=(1<<m)-1;

struct C{
	int a,b,c;
}c[1<<21];

C operator+(const C &x,const C &y){
	C z;
	z.a=min(x.a,y.a);
	if (x.c>y.c){
		z.c=x.c;
		z.b=max(x.b,y.c);
	}
	else{
		z.c=y.c;
		z.b=max(y.b,x.c);
	}
	return z;
}

void solve(){
	n=read();
	rep(i,0,lim) c[i]=(C){INF,-INF,-INF};
	rep(i,1,n){
		w[i]=read();
		c[w[i]]=c[w[i]]+(C){i,-INF,i};
	}
	rep(j,0,m-1)
		rep(i,0,lim)
			if (i>>j&1)
				c[i^1<<j]=c[i^1<<j]+c[i];
	int ans=0;
	rep(i,0,lim){
		if (c[i].b==-INF) continue;
		int z=0;
		per(j,0,m-1) if (i>>j&1^1){
			if (c[z|1<<j].a<c[i].b) z|=1<<j;
		}
		ans=max(ans,z|i);
	}
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}