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
ll d[300010];

struct C{
	int x,y; ll w;
};

vector<C> S;

void solve(){
	n=read(),m=read();
	while (m--){
		int u=read(),v=read(),w=read();
		d[u]-=w,d[v]+=w;
	}
	vector<int> A,B;
	rep(i,1,n)
		if (d[i]>0) A.pb(i);
		else if (d[i]<0) B.pb(i);
	while (A.size()){
		int u=A.back(),v=B.back();
		A.pop_back(),B.pop_back();
		ll w=min(d[u],-d[v]);
		S.pb((C){v,u,w});
		d[u]-=w,d[v]+=w;
		if (d[u]) A.pb(u);
		if (d[v]) B.pb(v);
	}
	printf("%d\n",int(S.size()));
	for (const auto &v: S) printf("%d %d %lld\n",v.x,v.y,v.w);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}