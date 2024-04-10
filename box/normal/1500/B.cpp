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
} using io::gi;

// end fast read template by CYJian

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)

int A[500005], B[500005];
int gc;
int ree[1000006]; 
int n, m;
int byv1[1000006];
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	long long k; gi(n),gi(m),gi(k);
    k--;
    rep(i, n) gi(A[i]);
    rep(j, m) gi(B[j]);
    if(n > m) {
        swap(n, m);
        swap(A, B);
    }
    gc = __gcd(n, m);
    long long lc = 1ll * n * m / gc;
    memset(byv1, -1, sizeof byv1);
    rep(i,n) byv1[A[i]]=i;
    rep(i,m) {
        if(byv1[B[i]]==-1)continue;
        int p=i-byv1[B[i]];
        if(p<0)p+=m;
        ree[p]--;
    }
    rep(i,m) ree[i]+=n;
    long long cn = 0;
    rep(i,m/gc) cn += ree[1ll*i*n%m];
    long long ans = lc * (k / cn);
    k%=cn;
    rep(i,m){
        int cp=1ll*i*n%m;
        if(ree[cp]<=k){
            k-=ree[cp];ans+=n;
        }else break;
    }
    while(1) {
        if(A[ans%n] != B[ans%m]) {
            if(!k) {
                cout << ans+1 << endl;
                return 0;
            }
            k--;
        }
        ans++;
    }
    return 0;
}