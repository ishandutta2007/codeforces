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

int c;
int dp[3005][3005];
vector<int> elist[3005];
void dfs(int u){
	rep1(i,c)dp[u][i]=1;
	for(int v:elist[u]){
		dfs(v);
		int sm=0;
		rep1(i,c){
			sm=(sm+dp[v][i])%MOD;
			dp[u][i]=1ll*dp[u][i]*sm%MOD;
		}
	}
}
int qpow(int b, int e) {
	int a=1;
	while(e){
		if(e&1)a=1ll*a*b%MOD;
		b=1ll*b*b%MOD;e>>=1;
	}
	return a;
}
int lagrange(ll n,vector<pii>x) {
	n%=MOD;
	int r=0;
	rep(i,x.size()) {
		int a=x[i].se,b=1;
		rep(j,x.size()) {
			if(i==j)continue;
			a=1ll*a*(MOD+n-x[j].fi)%MOD;
			b=1ll*b*(MOD+x[i].fi-x[j].fi)%MOD;
		}
		r=(r+1ll*a*qpow(b,MOD-2))%MOD;
	}
	return r;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,d;cin>>n>>d;
	iter(i,2,n+1){
		int f;cin>>f;
		elist[f].push_back(i);
	}
	c=n+1;
	dfs(1);
	rep1(i,n+1)dp[1][i]=(dp[1][i]+dp[1][i-1])%MOD;
	if(d<=n+1)cout<<dp[1][d]<<endl;
	else{
		vector<pii>ex;
		rep1(i,n+1)ex.push_back({i,dp[1][i]});
		cout<<lagrange(d,ex)<<endl;
	}
}