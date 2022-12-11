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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m;
bool mrk[300010];

void solve(){
	n=read()*3,m=read();
	memset(mrk+1,0,n);
	vector<int> S;
	rep(i,1,m){
		int u=read(),v=read();
		if (!mrk[u]&&!mrk[v]){
			mrk[u]=mrk[v]=1;
			S.emplace_back(i);
		}
	}
	if (int(S.size())>=n/3){
		puts("Matching");
		S.resize(n/3);
		for (auto x: S) printf("%d ",x);
		puts("");
	}
	else{
		puts("IndSet");
		int t=0;
		rep(i,1,n) if (!mrk[i]&&t*3<n) ++t,printf("%d ",i);
		puts("");
	}
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}