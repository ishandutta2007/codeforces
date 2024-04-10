#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
/*
typedef pair<int,int> P;
*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n,m;
int a[300010],c[300010];
void solve(){
	n=read(),m=read();
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	rep(i,1,m) c[i]=read();
	ll ans=0;
	for (int i=n,j=1;i;i--){
		if (j<=a[i]) ans+=c[j++];
		else ans+=c[a[i]];
	}
	printf("%lld\n",ans);
}
int main()
{
	for (int T=read();T--;) solve();
}