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
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n,k;
struct C{
	int L,x; ll d;
};
bool operator>(const C &x,const C &y){
	return x.d>y.d;
}
priority_queue<C,vector<C>,greater<C> > que;
ll cut(int x,int t){
	assert(t<=x);
	int a=x/t,b=x/t+1;
	int totb=x%t,tota=t-totb;
	return 1LL*a*a*tota+1LL*b*b*totb;
}
void solve(){
	n=read(),k=read()-n;
	ll ans=0;
	rep(i,1,n){
		int x=read();
		ans+=cut(x,1);
		if (x>1) que.push((C){x,2,-cut(x,1)+cut(x,2)});
	}
	while (k--){
		assert(que.size());
		C x=que.top(); que.pop();
		ans+=x.d;
		if (x.L>x.x) que.push((C){x.L,x.x+1,-cut(x.L,x.x)+cut(x.L,x.x+1)});
	}
	printf("%lld\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
}