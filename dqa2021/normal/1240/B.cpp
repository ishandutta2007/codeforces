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

int n,a[300010];
P b[300010];
bool ok[300010]; int m;

void solve(){
	n=read();
	rep(i,1,n) a[i]=read(),b[i]={a[i],i};
	sort(b+1,b+n+1);
	m=1;
	rep(i,1,n-1) if (b[i].fi!=b[i+1].fi){
		ok[m]=b[i].se<b[i+1].se;
		m++;
	}
	--m;
	int z=1;
	for (int l=1,r;l<=m;l=r+1){
		if (ok[l]==0){
			r=l; continue;
		}
		for (r=l;r<m&&ok[r+1];++r);
		z=max(z,r-l+2);
	}
	printf("%d\n",m-z+1);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}