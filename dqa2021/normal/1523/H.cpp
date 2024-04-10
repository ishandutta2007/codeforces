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
const int INF=1e9;


int n,q;
int a[20010];
int bt[20010],st[15][20010];

inline int chk(int x,int y){
	if (!min(x,y)) return x|y;
	return x+a[x]>y+a[y]?x:y;
}

inline int getmax(int l,int r){
	const int t=bt[r-l+1];
	return chk(st[t][l],st[t][r-(1<<t)+1]);
}

int gnd[16][32][20010];

void solve(){
	n=read(),q=read();
	bt[0]=-1; rep(i,1,n) bt[i]=bt[i>>1]+1,st[0][i]=i,a[i]=read();
	a[n+1]=INF;
	rep(j,1,14)
		rep(i,1,n-(1<<j)+1)
			st[j][i]=chk(st[j-1][i],st[j-1][i+(1<<j-1)]);
			
	rep(_,0,14) rep(j,0,30) gnd[_][j][n+1]=n+1;
	per(i,1,n){
		if (i+a[i]>n) gnd[0][0][i]=n+1;
		else gnd[0][0][i]=getmax(i+1,i+a[i]);
		rep(j,1,30){
			if (i+a[i]+j>n) gnd[0][j][i]=n+1;
			else gnd[0][j][i]=i+a[i]+j;
		}
	}
	rep(_,1,14){
		auto F=gnd[_];
		const auto G=gnd[_-1];
		rep(u,0,30){
			rep(v,0,30-u){
				rep(i,1,n){
					F[u+v][i]=chk(F[u+v][i],G[v][G[u][i]]);
				}
			}
		}
	}
	
//	rep(_,0,5) rep(j,0,4) rep(i,1,n+1) debug("gnd %d %d %d = %d\n",_,j,i,gnd[_][j][i]);
	
	while (q--){
		int l=read(),r=read(),k=read();
		if (l==r) {puts("0"); continue;}
		if (l+a[l]+k>=r) {puts("1"); continue;}
		static int A[32],B[32];
		rep(i,0,k) A[i]=l;
		int z=2;
		per(_,0,14){
//			debug("per %d\n",_);
			bool g=0;
			const auto F=gnd[_];
			rep(u,0,k){
				rep(v,0,k-u){
					const int p=F[v][A[u]];
//					debug("  u %d jump v %d: %d %d\n",u,v,p,p+a[p]);
					if (p+a[p]+k-u-v>=r){
						g=1; break;
					}
				}
				if (g) break;
			}
			if (g) continue;
//			debug("  upd %d\n",1<<_);
			memset(B,0,sizeof B);
			rep(u,0,k) rep(v,0,k-u) B[u+v]=chk(B[u+v],F[v][A[u]]);
			z+=1<<_;
			memcpy(A,B,sizeof A);
		}
		printf("%d\n",z);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}