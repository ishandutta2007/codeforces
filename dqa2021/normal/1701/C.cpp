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

int n,m,c[200010];

bool check(int T){
	static int d[200010];
	int S=0;
	rep(i,1,n){
		if (c[i]<=T) d[i]=c[i];
		else d[i]=T,S+=c[i]-d[i];
	}
	rep(i,1,n){
		int w=T-d[i]>>1;
		S=max(0,S-w);
	}
	return S<=0;
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) c[i]=0;
	rep(i,1,m) ++c[read()];
	int l=1,r=m*2,mid;
	while (l<r){
		mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}