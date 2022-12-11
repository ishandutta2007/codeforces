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
int p[100010];
int a[100010],b[100010];
void solve(){
	n=read(),m=read();
	rep(i,1,m) p[i]=read();
	rep(i,1,m) a[p[i]]=i;
	fill(b+1,b+n+1,m+1);
	per(i,1,m) b[p[i]]=i;
	ll z=0;
	rep(i,1,n){
		if (!a[i]){
			++z;
		}
		if (i>1){
			z+=max(0,b[i]-a[i-1])?1:0;
		}
		if (i<n){
			z+=max(0,b[i]-a[i+1])?1:0;
		}
	}
	printf("%lld\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}