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

int n,c[500010],m;
int pre[500010];
int s[500010];

ll W;  // greedily cut into y
P operator+(const P &x,const P &y){
	return P(max(x.fi,y.fi),max(min(x.fi,y.fi),max(x.se,y.se)));
}
P operator+(const P &x,const int &y){
	return P(max(x.fi,y),max(min(x.fi,y),x.se));
}

P h[500010];

void init(int y){
	W=0;
	rep(i,1,m/y){
		W+=(s[min((i+1)*y-1,m)]-s[i*y-1])*1LL*i;
	}
//	debug("init %d: %lld\n",y,W);
	h[m+1]={-1,-1};
	per(i,1,m/y){
		int l=i*y,r=(i+1)*y-1; r=min(r,m);
		h[l]=h[r+1];
		if (pre[r]>=l){
			int x=pre[r];
			h[l]=h[l]+x%y;
			if (c[x]>1){
				h[l]=h[l]+x%y;
			}
			else if (pre[x-1]>=l){
				x=pre[x-1];
				h[l]=h[l]+x%y;
			}
		}
	}
}

bool check1(int x,int y){  // into 1
	if (2*x>m) return 0;
	int l=2*x,r=2*x/y*y+y; r=min(r,m+1); --r;
	P o=h[r+1];
	if (pre[r]>=l){
		int z=pre[r];
		o=o+z%y;
		if (c[z]>1){
			o=o+z%y;
		}
		else if (pre[z-1]>=l){
			z=pre[z-1];
			o=o+z%y;
		}
	}
	const int A=o.fi,B=(x%y)*2; int C=(x/y)*2;
	if (!~A) return 0;
//	debug("C0 %d\n",C);
	if (B<=A);
	else if (B<=A+y) ++C;
	else C+=2;
//	debug("check1 %d %d: W %lld - C %d  A %d\n",x,y,W,C,A);
	return W-C>=x;
}

bool check2(int x,int y){
//	debug("==================\nCHECK2 %d %d\n",x,y);
	int l=x,r=x/y*y+y; r=min(r,m+1); --r;
//	debug("l %d r %d\n",l,r);
	P o=h[r+1];
//	debug("o %d %d\n",o.fi,o.se);
	if (pre[r]>=l){
		int z=pre[r];
		o=o+z%y;
		if (c[z]>1){
			o=o+z%y;
		}
		else if (pre[z-1]>=l){
			z=pre[z-1];
			o=o+z%y;
		}
	}
//	debug("o %d %d\n",o.fi,o.se);
	const int A=o.fi,B=o.se,G=x%y; int C=(x/y)*2;
	if (!~B) return 0;
//	debug("C0 %d\n",C);
	if (G<=A);
	else ++C;
	if (G<=B);
	else ++C;
//	debug("check2 %d %d: W %lld - C %d  A %d B %d\n",x,y,W,C,A,B);
	return W-C>=x;
}

void solve(){
	n=read();
	rep(i,1,n){
		int x=read(); m=max(m,x);
		++c[x];
	}
	rep(i,2,m){
		pre[i]=c[i]?i:pre[i-1];
		s[i]=s[i-1]+c[i];
	}
	int x=1; ll z=0;
	per(y,2,m){
		init(y);
		while (x<m&&(check1(x+1,y)||check2(x+1,y))) ++x;
		if (x>1) z=max(z,1LL*x*y);
	}
	assert(z);
	printf("%lld\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}