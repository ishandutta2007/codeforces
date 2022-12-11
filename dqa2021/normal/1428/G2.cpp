#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
typedef long long ll;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
typedef pair<ll,int> P;
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)
const ll INF=1e18;

int K,F[6],q;
ll dp[1000010]; const int lim=1e6;
inline void check(ll &x,const ll &y){if (y>x) x=y;}
void ins(int tot,int V,int W){
	//printf("ins %d %d %d\n",tot,V,W);
	static P que[1000010]; int hd,tl;
	rep(e,0,V-1){
		hd=1,tl=0;
		for (int i=e,j=0;i<=lim;i+=V,j++){
			if (dp[i]!=-INF){
				const P &C=P(dp[i]-1LL*j*W,j);
				while (hd<=tl&&que[tl].fi<C.fi) --tl;
				que[++tl]=C;
			}
			while (hd<=tl&&j-que[hd].se>tot) ++hd;
			if (hd<=tl) dp[i]=que[hd].fi+1LL*j*W;
		}
	}
	//rep(i,0,100) printf("%d: %lld\n",i,dp[i]);
	//puts("============");
}
void solve(){
	K=read();
	rep(i,0,5) F[i]=read();
	rep(i,1,lim) dp[i]=-INF;  //caution -inf
	for (int e=0,V=3;e<=5;e++,V*=10) ins(3*(K-1),V,F[e]);
	for (int e=0,V=1;e<=5;e++,V*=10){
		per(i,0,lim){
			const ll &C=dp[i];
			per(j,1,9){
				if (i+j*V>lim) continue;
				const ll &W=j%3?0:j/3LL*F[e];
				check(dp[i+j*V],C+W);
			}
		}
	}
	//rep(i,0,100) printf("%d: %lld\n",i,dp[i]);
	//puts("============");
	q=read();
	while (q--) printf("%lld\n",dp[read()]);
}
int main()
{
	for (int T=1;T--;) solve();
}