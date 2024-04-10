#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
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
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n; ll k;
void solve(){
	n=read(); k=read();
	if (n<=63&&k>(1LL<<n-1)) return puts("-1"),void();
	int suf=n;
	while ((1LL<<n-suf)<k) --suf;
	rep(i,1,suf-1) printf("%d ",i);
	while (suf<=n){
		int t=suf;
		while (t<n&&k>(1LL<<n-t-1)) k-=1LL<<n-t-1,++t;
//		assert(t<=n);
		per(i,suf,t) printf("%d ",i);
		suf=t+1;
	}
	puts("");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}