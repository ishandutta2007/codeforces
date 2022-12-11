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

int n,a[100010];
bool check(){
	ll z=a[1];
	rep(i,2,n) z+=a[i]-i+1;
	return z&1;
}
bool solve(){
	n=read();
	rep(i,1,n) a[i]=read();
	if (n==1){
		return a[1]&1?1:0;
	}
	sort(a+1,a+n+1);
	int p=-1;
	rep(i,2,n){
		if (a[i]^a[i-1]) continue;
		if (~p) return 0;
		p=i-1;
	}
	if (~p){
		if (p>1&&a[p]-1==a[p-1]) return 0;
		if (!a[p]) return 0;
		--a[p];
		return check()^1;
	}
	return check();
}

int main()
{
	for (int T=1;T--;) puts(solve()?"sjfnb":"cslnb");
	return 0;
}