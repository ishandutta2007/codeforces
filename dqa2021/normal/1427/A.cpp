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

int n,a[55];
int cmp(int x,int y){return abs(x)>abs(y);}
void solve(){
	n=read();
	int W=0;
	rep(i,1,n) a[i]=read(),W+=a[i];
	if (W==0) return puts("NO"),void();
	puts("YES");
	vector<int> S,T,E;
	rep(i,1,n) if (a[i]>0) S.pb(a[i]); else if (a[i]<0) T.pb(a[i]); else E.pb(a[i]);
	if (W<0){
		for (int x: T) printf("%d ",x);
		for (int x: S) printf("%d ",x);
	}
	else{
		for (int x: S) printf("%d ",x);
		for (int x: T) printf("%d ",x);
	}
	for(int x: E) printf("%d ",x);
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
}