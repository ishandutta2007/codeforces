#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
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
typedef pair<ll,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
//#define pop(x) __builtin_popcount(x)
uint getrand(){
	static uint sd=542365825U;
	return sd^=sd>>13,sd^=sd<<27,sd^=sd>>24,sd^=sd<<8;
}

int n,lim; ll w[32];
int pop[1<<20];

bool work(int msk){
	static ll w[32]; int m=0;
	ll S=0;
	rep(i,1,n) if (msk>>i-1&1) w[++m]=::w[i],S+=w[m];
	if ((S^m^1)&1) return 0;
	const int L=m>>1,R=m+1>>1;
	
	static P f[1<<10],g[1<<10]; int ftop=1,gtop=1;  // caution [0, top)
	f[0]=g[0]=P(0,0);
	per(_,1,L){
		int top=ftop;
		rep(i,0,top-1){
			f[ftop++]=P(f[i].fi+w[_],f[i].se|1<<_-1);
			f[i].fi-=w[_];
		}
		inplace_merge(f,f+top,f+ftop);
//		rep(i,0,ftop-1) printf("  f %d: %d %d\n",i,f[i].fi,f[i].se);
	}
	per(_,L+1,m){
		int top=gtop;
		rep(i,0,top-1){
			g[gtop++]=P(g[i].fi-w[_],g[i].se|1<<_-1-L);
			g[i].fi+=w[_];
		}
		inplace_merge(g,g+top,g+gtop);
//		rep(i,0,gtop-1) printf("  g %d: %d %d\n",i,g[i].fi,g[i].se);
	}
//	printf("test work %d: ftop %d gtop %d\n",msk,ftop,gtop);
	for (int i=0,l=0,r=0;i<ftop;++i){
		const ll w=f[i].fi;
		if (f[i].se==0){
			rep(j,0,gtop-1)
				if (g[j].se&&abs(w-g[j].fi)<=m)
					return 1;
			continue;
		}
		if (f[i].se==ftop-1){
			rep(j,0,gtop-1)
				if (g[j].se!=gtop-1&&abs(w-g[j].fi)<=m)
					return 1;
			continue;
		}
		while (r<gtop&&g[r].fi<=w+m) ++r;
		while (l<gtop&&g[l].fi<w-m) ++l;
		if (l<r) return 1;
	}
	
	return 0;
}


void fwt(uint *w){
	rep(i,0,n-1)
		rep(j,0,lim)
			if (j>>i&1)
				w[j]+=w[j^(1<<i)];
}
void ifwt(uint *w){
	rep(i,0,n-1)
		rep(j,0,lim)
			if (j>>i&1)
				w[j]-=w[j^(1<<i)];
}

void mul(uint f[][1<<20],const uint g[][1<<20],const int d){
	rep(u,d,n-d) rep(v,d,n-u){
		uint *F=f[u+v];
		const uint *G=g[u],*H=g[v];
		rep(i,0,lim) F[i]+=G[i]*H[i];
	}
}
void mul(uint f[][1<<20],const uint g[][1<<20],const uint h[][1<<20],const int c,const int d){
	rep(u,c,n-d) rep(v,d,n-u){
		uint *F=f[u+v];
		const uint *G=g[u],*H=h[v];
		rep(i,0,lim) F[i]+=G[i]*H[i];
	}
}

uint ok[1<<20];
uint g[5][21][1<<20];
uint f[21][1<<20],h[21][1<<20],d[21][1<<20];

void solve(){
	n=read();
	rep(i,1,n) w[i]=read();
	{
	int m=n; n=0;
	rep(i,1,m) if (w[i]) w[++n]=w[i];
	}
	if (!n) return puts("0"),void();
	lim=(1<<n)-1;
	rep(i,1,lim) pop[i]=pop[i>>1]+(i&1);
	rep(i,0,lim) if (pop[i]>1) ok[i]=work(i)?getrand():0;
	
//	rep(i,0,lim) printf("ok %d = %u\n",i,ok[i]);
//	return;
	
	rep(i,0,lim) g[0][pop[i]][i]=ok[i];
	rep(i,1,n) fwt(g[0][i]);
	rep(_,1,4) mul(g[_],g[_-1],1<<_-1);
	f[0][0]=1; fwt(f[0]);
	int z=n;
	per(_,0,4){
		memset(h,0,sizeof h);
		mul(h,f,g[_],n-z,1<<_);
		memcpy(d,h,sizeof d);
		rep(i,n-z+(1<<_),n) ifwt(h[i]);
		bool t=0;
		rep(i,0,lim) if (h[pop[i]][i]) {t=1; break;}
//		printf("Case %d:\n",_);
//		rep(i,0,lim) printf("%u ",h[pop[i]][i]);
//		puts("");
//		if (t) memcpy(f,d,sizeof d),z-=1<<_,printf("try %d: ok\n",_);
//		else printf("try %d: fail\n",_);
		if (t) memcpy(f,d,sizeof d),z-=1<<_;
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}