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

int segt[1000005],tag[1000005];
#define lson idx*2,l,(l+r)/2
#define rson idx*2+1,(l+r)/2,r
void put(int idx,int l,int r,int t){
	tag[idx]=t;
	if(t==1)segt[idx]=0;
	else segt[idx]=r-l;
}
void pd(int idx,int l,int r){
	if(r-l==1||!tag[idx])return;
	put(lson,tag[idx]);put(rson,tag[idx]);
	tag[idx]=0;
}
int gsum(int idx,int l,int r,int L,int R){
	if(L<=l&&r<=R)return segt[idx];
	if(R<=l||r<=L)return 0;
	pd(idx,l,r);return gsum(lson,L,R)+gsum(rson,L,R);
}
void push(int idx,int l,int r,int L,int R,int v){
	if(L<=l&&r<=R)return put(idx,l,r,v);
	if(R<=l||r<=L)return;
	pd(idx,l,r);push(lson,L,R,v);push(rson,L,R,v);
	segt[idx]=segt[idx*2]+segt[idx*2+1];
}
int L[200005],R[200005];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;cin>>t;
	while(t--){
		int n,q;cin>>n>>q;
		rep(i,n*4+50)segt[i]=tag[i]=0;
		string a,b;cin>>a>>b;
		rep(i,q)cin>>L[i]>>R[i];
		rep(i,n)push(1,0,n,i,i+1,b[i]-'0'+1);
		bool r=1;
		for(int i=q-1;i>=0;i--){
			L[i]--;int s=gsum(1,0,n,L[i],R[i]);
			if(s*2==R[i]-L[i])r=0;
			else if(s*2<R[i]-L[i])push(1,0,n,L[i],R[i],1);
			else push(1,0,n,L[i],R[i],2);
		}
		rep(i,n)r=r&&(gsum(1,0,n,i,i+1)==a[i]-'0');
		cout<<(r?"YES\n":"NO\n");
	}
}