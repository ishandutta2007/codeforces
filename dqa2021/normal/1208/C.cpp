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

int n,m;
int w[1010][1010];
const int e[]={8,9,1,13,3,12,7,5,0,2,4,11,6,10,15,14};

void solve(){
	n=read(),m=n>>2;
	rep(i,0,m-1) rep(j,0,m-1){
		const int B=(i*m+j)*16;
		int x=i*4,y=j*4;
		rep(g,0,15){
			int dx=g/4,dy=g%4;
			w[x+dx][y+dy]=e[g]+B;
		}
	}
	rep(i,0,n-1){
		rep(j,0,n-1) printf("%d ",w[i][j]);
		puts("");
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}