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
typedef pair<ll,ll> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
#define gcd __gcd


inline void move(ll &x,ll &y,vector<P> &S){
	if (x==y) return;
	S.emplace_back(x,y);
	x=2*y-x;
}

ll prework(ll *a,vector<P> &S){
	while (a[3]-a[0]>1){
//		debug("prework:");
//		rep(i,0,3) debug(" %lld",a[i]);
//		debug("\n");
		const ll l=a[0]+(a[3]-a[0]+3>>2),r=a[3]-(a[3]-a[0]+3>>2)/*,m=a[0]+(a[3]-a[0]>>1)*/;
		int s=0,t=0;
		if (a[1]<l) s=-1;
		if (r<a[1]) s=1;
		if (a[2]<l) t=-1;
		if (r<a[2]) t=1;
		if (!s){
			move(a[0],a[1],S);
		}
		else if (!t){
			move(a[3],a[2],S);
		}
		else{
			if (t==-1){
				while (a[2]<l){
					move(a[1],a[0],S);
					move(a[1],a[2],S);
					sort(a,a+4);
				}
			}
			else if (s==1){
				while (a[1]>r){
					move(a[2],a[3],S);
					move(a[2],a[1],S);
					sort(a,a+4);
				}
			}
			else{
				while (a[1]<l&&a[2]>r){
					if (a[1]-a[0]<=a[3]-a[2]){
						move(a[1],a[2],S);
						move(a[1],a[3],S);
					}
					else{
						move(a[2],a[1],S);
						move(a[2],a[0],S);
					}
					sort(a,a+4);
				}
			}
		}
		sort(a,a+4);
	}
//	debug("prework2:");
//	rep(i,0,3) debug(" %lld",a[i]);
//	debug("\n");
	if (a[0]&1){
		rep(i,0,2) if (a[i]&1) move(a[i],a[3],S); else break;
		sort(a,a+4);
	}
//	debug("prework3:");
//	rep(i,0,3) debug(" %lld",a[i]);
//	debug("\n=====================\n");
	return a[0];
}

void work(ll *a,ll L,vector<P> &S){
//	debug("work %lld\n",L);
//	rep(i,0,3) debug("%lld ",a[i]);
//	debug("\n");
	assert(L&1^1); L>>=1;
	int cnt=0;
	while (a[3]-a[0]<=L){
//		rep(i,0,3) debug("%lld ",a[i]);
//		debug("\n");
		move(a[3],a[0],S);
		move(a[0],a[2],S);
		sort(a,a+4);
		++cnt;
	}
//	debug("test1\n");
	while (cnt--){
		move(a[3],a[2],S);
		move(a[0],a[3],S);
		sort(a,a+4);
		while (a[3]-a[0]<=L){
//			debug("jump L %lld d %lld:\n",L,a[3]-a[0]);
//			rep(i,0,3) debug("%lld ",a[i]);
//			debug("\n");
			L-=a[3]-a[0];
			rep(i,0,2) move(a[i],a[3],S);
			per(i,1,3) move(a[i],a[0],S);
//			rep(i,0,3) debug("%lld ",a[i]);
//			debug("\n");
//			sort(a,a+4);
		}
	}
//	debug("test2 L %lld\n",L);
}

ll B,G;
ll a[4],b[4];

void solve(){
	rep(i,0,3) a[i]=read();
	rep(i,0,3) b[i]=read();
	sort(a,a+4); sort(b,b+4);
	if (a[0]==a[3]||b[0]==b[3]){
		if (a[0]==a[3]&&b[0]==b[3]&&a[0]==b[0]) return puts("0"),void();
		puts("-1"); return;
	}
	{
	ll s=0,t=0;
	rep(i,1,3) s=gcd(s,a[i]-a[0]),t=gcd(t,b[i]-b[0]);
	if (s!=t) return puts("-1"),void();
	if ((a[0]-b[0])%s) return puts("-1"),void();
	B=a[0],G=s;
	per(i,0,3) a[i]=(a[i]-B)/G,b[i]=(b[i]-B)/G;
	int otot=0;
	rep(i,0,3) otot+=a[i]&1,otot-=b[i]&1;
	if (otot) return puts("-1"),void();
	}
	vector<P> L,R;
	ll p=prework(a,L),q=prework(b,R);
	
//	debug("test L %d R %d\n",int(L.size()),int(R.size()));
//	debug("a: ");
//	rep(i,0,3) debug("%lld ",a[i]);
//	debug("\n");
//	debug("b: ");
//	rep(i,0,3) debug("%lld ",b[i]);
//	debug("\n");
//	debug("q: %lld\n",q);
//	for (const P &o: R) debug("R %lld %lld\n",B+o.fi*G,B+o.se*G);
	
	if (q-p>=0) work(a,q-p,L);
	else work(b,p-q,R);
	
//	debug("a: ");
//	rep(i,0,3) debug("%lld ",a[i]);
//	debug("\n");
//	debug("b: ");
//	rep(i,0,3) debug("%lld ",b[i]);
//	debug("\n");
	
	printf("%d\n",int(L.size()+R.size()));
	for (const P &o: L) printf("%lld %lld\n",B+o.fi*G,B+o.se*G);
	
//	debug("===========\n");
	
	reverse(all(R));
	for (const P &o: R) printf("%lld %lld\n",B+(2*o.se-o.fi)*G,B+o.se*G);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}


/*

*/