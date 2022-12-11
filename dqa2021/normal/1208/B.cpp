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
int w[2010];
int c[2010],d[2010];

void solve(){
	n=read();
	map<int,int> mp; int m=0;
	rep(i,1,n){
		int x=read();
		if (!mp[x]) mp[x]=++m;
		x=mp[x];
		w[i]=x;
		++d[x];
	}
	int ban=0;
	rep(i,1,m) ban+=d[i]>1;
	if (!ban) return puts("0"),void();
	int z=1e9;
	rep(l,1,n){
		int t=ban;
		memcpy(c,d,sizeof c);
		rep(r,l,n){
			if (c[w[r]]==2) --t;
			--c[w[r]];
			if (!t) z=min(z,r-l+1);
		}
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}