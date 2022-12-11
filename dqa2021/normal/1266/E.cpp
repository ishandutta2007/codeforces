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
typedef pair<int,int> P;
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

int n,q;
int a[200010];
int b[200010];
ll ans;
map<P,int> mp;
void erase(int s,int t,int u){
	ans-=max(0,a[u]-b[u]);
	b[u]--;
	ans+=max(0,a[u]-b[u]);
}
void ins(int s,int t,int u){
	ans-=max(0,a[u]-b[u]);
	b[u]++;
	ans+=max(0,a[u]-b[u]);
}
void solve(){
	n=read();
	rep(i,1,n) a[i]=read(),ans+=a[i];
	q=read();
	while (q--){
		int s=read(),t=read(),u=read();
		if (mp.count(P(s,t))) erase(s,t,mp[P(s,t)]),mp.erase(P(s,t));
		if (u) mp[P(s,t)]=u,ins(s,t,u);
		printf("%lld\n",ans);
	}
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}