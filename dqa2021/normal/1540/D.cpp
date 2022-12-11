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
const int S=888,N=1e5;


int n,c[100010];
struct B{
	P d[S+10]; int m;
	void init(int l,int r){
		m=0;
		per(i,l,r) d[++m]={0,i};
	}
	void modify(int x,int w){
		rep(_,1,m) if (d[_].se==x){
			per(i,_+1,m) if (d[i].se>x){
				if (i<m&&d[i].fi==d[i+1].fi) swap(d[i],d[i+1]);
				else ++d[i].fi;
			}
			rep(i,_,m-1) swap(d[i],d[i+1]);
			P o=d[m--];
			c[x]=w;
			int p=m+1,s=0;
			rep(i,1,m){
				s+=d[i].se<x;
				if (d[i].fi+s>w){
					p=i; break;
				}
			}
			s=w;
			rep(i,1,p-1) s-=d[i].se<x;
			o.fi=s;
			per(i,p,m) swap(d[i],d[i+1]);
			++m; d[p]=o;
			rep(i,p+1,m){
				if (d[i].se>x){
					if (d[i].fi==d[i-1].fi) swap(d[i],d[i-1]);
					else --d[i].fi;
				}
			}
			return;
		}
		assert(0);
	}
	
	int query(int x){
		int l=0,r=m,mid;
		while (l<r){
			mid=l+r+1>>1;
			if (d[mid].fi<x) l=mid;
			else r=mid-1;
		}
		return l;
	}
}b[N/S+10];

void solve(){
	n=read();
	for (int i=0;i*S+1<=n;++i) b[i].init(i*S+1,min((i+1)*S,n));
	rep(i,1,n) b[(i-1)/S].modify(i,i-1-read());
	int q=read();
	while (q--){
		if (read()&1){
			int x=read(),w=x-1-read();
			b[(x-1)/S].modify(x,w);
		}
		else{
			int x=read(),z=c[x]+1;
			rep(i,x+1,min(n,((x-1)/S+1)*S)) if (c[i]<z) ++z;
			rep(i,(x-1)/S+1,(n-1)/S) z+=b[i].query(z);
			printf("%d\n",z);
		}
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}