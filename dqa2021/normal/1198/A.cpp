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

int n,I,a[400010],b[400010],c[400010];

int getlog(int x){
	int t=0;
	while ((1<<t)<x) ++t;
	return t;
}

void solve(){
	n=read(),I=read()<<3;
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	rep(i,1,n) b[i]=i==1||a[i]!=a[i-1]?b[i-1]+1:b[i-1];
	int m=b[n];
	rep(i,1,n) ++c[b[i]];
	rep(i,1,m) c[i]+=c[i-1];
	int z=1e9;
	rep(i,1,m){
		int l=i,r=m,mid;
		while (l<r){
			mid=l+r+1>>1;
			if (n*getlog(mid-i+1)<=I) l=mid;
			else r=mid-1;
		}
//		printf("test %d %d  %d\n",i,l,(l-i+1)*getlog(l-i+1));
		z=min(z,n-(c[l]-c[i-1]));
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}