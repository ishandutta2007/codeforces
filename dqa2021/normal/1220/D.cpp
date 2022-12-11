#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
#define gcd __gcd

int n; ll w[200010];

void solve(){
	n=read(); ll g=0;
	rep(i,1,n) w[i]=read();
	int tot=n+10,id=-1;
	rep(e,0,60){
		int z=0;
		rep(i,1,n) if ((w[i]>>e<<e)!=w[i]) ++z;
		else z+=(w[i]>>e+1<<e+1)==w[i];
		if (z<tot) tot=z,id=e;
	}
	printf("%d\n",tot);
	int e=id;
	rep(i,1,n) if ((w[i]>>e<<e)!=w[i]) printf("%lld ",w[i]);
		else if ((w[i]>>e+1<<e+1)==w[i]) printf("%lld ",w[i]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}