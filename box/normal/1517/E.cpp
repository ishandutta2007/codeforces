#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

// begin fast read template by CYJian (source: https://www.luogu.com.cn/paste/i11c3ppx)

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

// end fast read template by CYJian

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int ar[200005];
ll sfx[200015],pfx[200015],sfp[200015];
template<typename T>int flas(T f){
	if(!f(0))return -1;
	int ans=0;
	for(int i=17;i>=0;i--)if(f(ans|(1<<i)))ans|=(1<<i);
	return ans;
}
ll gud(int n){
	rep(i,n){
		sfx[i]=ar[i];
		pfx[i]=ar[i];if(i)pfx[i]+=pfx[i-1];
		if(i!=n-1)sfp[i]=ar[i]-ar[i+1];
	}
	rep(i,10)sfx[n+i]=sfp[n-1+i]=0;
	for(int i=n-1;i>=0;i--){
		sfx[i]+=sfx[i+1];
		sfp[i]+=sfp[i+2];
	}
	ll ans=0;
	for(int i=n;i>=0;i--){
		ll a=-sfx[i];if(i)a+=pfx[i-1];
		ans+=(a>0);
	}
	iter(l,1,n)ans+=flas([&](int i){return (l+2*i<n)&&(-pfx[l-1]+sfp[l]-sfp[l+2*i]+sfx[l+2*i]>0);})+1;
	iter(l,2,n)ans+=flas([&](int i){return (l+2*i<n)&&(-pfx[l-1]+sfp[l]-sfp[l+2*i]+sfx[l+2*i]+2*ar[0]>0);})+1;
	iter(l,1,n)ans+=flas([&](int i){return (l+2*i<n-1)&&(-pfx[l-1]+sfp[l]-sfp[l+2*i]+sfx[l+2*i]-2*ar[n-1]>0);})+1;
	iter(l,2,n)ans+=flas([&](int i){return (l+2*i<n-1)&&(-pfx[l-1]+sfp[l]-sfp[l+2*i]+sfx[l+2*i]+2*ar[0]-2*ar[n-1]>0);})+1;
	return ans%998244353;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;cin>>t;
	while(t--){
		int n;cin>>n;
		rep(i,n)cin>>ar[i];
		cout<<gud(n)<<endl;
	}
}