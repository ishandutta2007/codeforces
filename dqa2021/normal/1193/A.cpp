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

const int mod=998244353;
const ll smod=1LL*mod*mod;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
inline ll supd(const ll &x){return x+(x>>63&smod);}
inline void sadd(ll &x,const ll &y){x=supd(x+y-smod);}
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

int n,m; int lim;
int e[32];
int O[1<<18];
int f[1<<18];
int pop[1<<18];

int c[32],q;
int ans;
//int B; int ans;
//void dfs(int o,int msk,int tot){
//	if (o==q){
//		(pop[B]&1?add:iadd)(ans,1LL*f[msk]*f[(~0^msk^B)&lim]%mod*tot%mod);
////		printf("A %d B %d C %d coef %d * %d * %d tot %d\n",(~0^msk^B)&lim,B,msk,f[(~0^msk^B)&lim],pop[B]&1?1:-1,f[msk],tot);
//		return;
//	}
//	dfs(o+1,msk,tot);
//	dfs(o+1,msk|1<<c[o],tot+pop[e[c[o]]&B]);
//}
int msk[1<<18],tot[1<<18];

void solve(){
	n=read(),m=read();
	rep(i,1,m){
		int u=read(),v=read();
		e[u-1]|=1<<v-1;
	}
	lim=(1<<n)-1;
	rep(i,1,lim) pop[i]=pop[i>>1]+(i&1);
	rep(i,1,lim){
		rep(j,0,n-1) if (i>>j&1)
			O[i]|=e[j];
	}
	f[0]=1;
	rep(i,1,lim){
		for (int j=i;j;j=(j-1)&i)
			if (O[j]&j);
			else (pop[j]&1?add:iadd)(f[i],f[i^j]);
	}
//	rep(i,1,lim-1){
//		if (O[i]&i) continue;
//		q=0; //B=i;
//		rep(j,0,n-1) if (i>>j&1^1)
//			c[q++]=j;
//		int top=1;
//		msk[0]=tot[0]=0;
//		rep(_,0,q-1){
//			const int o=c[_],p=pop[e[o]&i];
//			per(j,0,top-1){
//				msk[j|top]=msk[j]|1<<o;
//				tot[j|top]=tot[j]+p;
//			}
//			top<<=1;
//		}
//		ll z=0;
//		rep(j,0,top-1){
//			const int &S=msk[j],&T=tot[j];
//			sadd(z,1LL*f[S]*f[(~0^S^i)&lim]%mod*T);
//		}
//		(pop[i]&1?add:iadd)(ans,z%mod);
//	}
	ans=1LL*f[lim]*m%mod*(mod+1>>1)%mod;
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}