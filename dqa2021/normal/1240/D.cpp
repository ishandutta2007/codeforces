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

int n,a[300010];

map<int,int> mp[300010];
int ctot;
int c[300010];
int fat[300010];

int stk[300010];

void solve(){
	n=read();
//	rep(i,1,n) mp[i].clear();
	ctot=1; mp[1].clear(); c[1]=1;
	rep(i,1,n) a[i]=read();
	int top=0; int o=1;
	rep(i,1,n){
		int x=a[i];
		if (top&&x==stk[top]){
			--top; o=fat[o];
		}
		else{
			stk[++top]=x;
			auto it=mp[o].find(x);
			if (it==mp[o].end()){
				mp[o].emplace(x,++ctot);
				c[ctot]=0; mp[ctot].clear();
				fat[ctot]=o;
			}
			o=mp[o][x];
		}
		++c[o];
	}
	ll z=0;
	rep(i,1,ctot) z+=1LL*c[i]*(c[i]-1)/2;
	printf("%lld\n",z);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}