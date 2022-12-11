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

const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,p[400010],q[400010];
int fat[400010];
int find(int x){
	return fat[x]?fat[x]=find(fat[x]):x;
}
void solve(){
	n=read();
	rep(i,1,n) fat[i]=0;
	rep(i,1,n) p[i]=read();
	rep(i,1,n) q[i]=read();
	rep(i,1,n) if (p[i]==q[i]) return puts("0"),void();
	rep(i,1,n){
		int x=find(p[i]),y=find(q[i]);
		if (x^y) fat[y]=x;
	}
	int z=1;
	rep(i,1,n) if (find(i)==i) z=2*z%mod;
	printf("%d\n",z);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}