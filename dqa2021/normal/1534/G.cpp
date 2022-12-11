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

int n;
P p[800010];
//void debugprint(priority_queue<ll,vector<ll>,greater<ll> > A,priority_queue<ll,vector<ll>,greater<ll> > B,ll L,ll R,ll TA,ll TB){
//	debug("=====================\n");
//	debug("test 0: %lld %lld\n",L,R);
//	int cnt;
//	cnt=0;
//	while (A.size()){
//		printf("test -%d: %lld\n",++cnt,L-(A.top()+TA));
//		A.pop();
//	}
//	cnt=0;
//	while (B.size()){
//		printf("test +%d: %lld\n",++cnt,R+(B.top()+TB));
//		B.pop();
//	}
//	debug("=====================\n");
//}
void solve(){
	n=read();
	rep(i,1,n){
		ll x=read(),y=read();
		p[i]={x+y,x-y};
	}
	sort(p+1,p+n+1);
	priority_queue<ll,vector<ll>,greater<ll> > A;
	priority_queue<ll,vector<ll>,greater<ll> > B;
	ll L=0,R=0,ans=0; ll TA=0,TB=0;
	rep(_,1,n){
		ll x,y; tie(x,y)=p[_];
//		debug("p %d: %lld %lld\n",_,x,y);
		const ll d=x-p[_-1].fi;
//		debug("d %lld\n",d);
		L-=d; R+=d;
		if (y<L){
			ans+=L-y;
			A.push(L-y-TA); A.push(L-y-TA);
			const ll g=A.top()+TA; A.pop();
			TA-=g;
			B.push(-TB); TB+=R-L;
			R=L,L-=g;
		}
		else if (y>R){
			ans+=y-R;
			B.push(y-R-TB); B.push(y-R-TB);
			const ll g=B.top()+TB; B.pop();
			TB-=g;
			A.push(-TA); TA+=R-L;
			L=R,R+=g;
		}
		else{
			B.push(-TB); A.push(-TA);
			TB+=R-y,TA+=y-L;
			L=R=y;
		}
//		debugprint(A,B,L,R,TA,TB);
	}
	printf("%lld\n",ans>>1);
//	debug("test ans %lld\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}