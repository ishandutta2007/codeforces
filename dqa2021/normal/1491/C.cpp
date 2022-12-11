#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,w[5010];
ll tot[5010];
void solve(){
	n=read();
	rep(i,1,n) w[i]=read(),tot[i]=0;
	ll ans=0;
	rep(i,1,n){
		ans+=max(0LL,w[i]-1-tot[i]);
		rep(j,2,min(w[i],n-i)) tot[i+j]++;
		if (w[i]-1<tot[i]) tot[i+1]+=(tot[i]-w[i]+1);
	}
	printf("%lld\n",ans);
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}