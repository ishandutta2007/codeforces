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
#define gcd __gcd

int n,w[100010];
mt19937 rnd(20210611);

void div(int x,int *a){
	*a=0;
	for (int i=2;i*i<=x;++i)
		if (x%i==0){
			a[++*a]=i;
			while (x%i==0) x/=i;
		}
	if (x^1) a[++*a]=x;
}
int a[16],b[16];
int c[32];

bool dp[200][1<<18];
int h[200];

void work(int x,int y){
//	debug("work %d %d\n",x,y);
	div(w[x],a); div(w[y],b);
//	debug("a:"); rep(j,1,*a) debug(" %d",a[j]); debug("\n");
//	debug("b:"); rep(j,1,*b) debug(" %d",b[j]); debug("\n");
	memset(c,0,sizeof c);
//	memset(d,0,sizeof d);
	vector<int> S={0};
	rep(i,1,n) if (i^x&&i^y){
		const int &w=::w[i];
		int msk=0;
		int g=-1;
		rep(j,1,*a) if (w%a[j]) msk|=1<<j-1;
		rep(j,1,*b) if (w%b[j]) msk|=1<<j-1+9;
		rep(j,1,*a) if (w%a[j]&&c[j]<=9) g=j;
		rep(j,1,*b) if (w%b[j]&&c[j+9]<=9) g=j+9;
//		debug("i %d g %d msk %d\n",i,g,msk);
		if (~g) ++c[g],h[S.size()]=msk,S.pb(i);
	}
	const int m=S.size()-1;
//	debug("m %d\n",m);
//	rep(i,1,m) printf("%d: S %d h %d\n",i,S[i],h[i]);
	rep(i,0,m) memset(dp[i],0,1<<18);
//	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	rep(_,1,m){
		const int &w=h[_];
		const auto G=dp[_-1];
		auto F=dp[_];
		rep(msk,0,262143) if (G[msk])
			F[msk|(w&511)]=1,
			F[msk|(w&261632)]=1;
	}
	int s=0;
	rep(j,1,*a) s|=1<<j-1;
	rep(j,1,*b) s|=1<<j-1+9;
	if (!dp[m][s]) return;
	puts("YES");
	static int d[100010];
	d[x]=1,d[y]=2;
	int E=s;
	per(_,1,m){
		const int &w=h[_];
		const auto G=dp[_-1];
		rep(msk,0,262143) if (G[msk]){
			if ((msk|(w&511))==E){
				d[S[_]]=1; E=msk; break;
			}
			if ((msk|(w&261632))==E){
				d[S[_]]=2; E=msk; break;
			}
		}
	}
	rep(i,1,n) printf("%d ",max(d[i],1));
	puts(""); exit(0);
}

void solve(){
	n=read();
	rep(i,1,n) w[i]=read();
	
//	work(2,3); return;
	
	while (0.35>double(clock())/CLOCKS_PER_SEC){  // !!!
		int x=rnd()%n+1,y=rnd()%(n-1)+1;
		if (y>=x) ++y;
		work(x,y);
	}
	puts("NO");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}