#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m;
vector<int> e[500010];
int w[500010];
void solve(){
	n=read(),m=read();
	while (m--){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	rep(i,1,n) w[i]=read();
	static vector<int> S[500010];
	rep(i,1,n){
		static int mrk[500010];
		for (const int &v: e[i]) mrk[w[v]]=i;
		int mex=1;
		while (mrk[mex]==i) ++mex;
		if (mex!=w[i]) puts("-1"),exit(0);
		S[w[i]].pb(i);
	}
	rep(i,1,n)
		for (int x: S[i]) printf("%d ",x);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}