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

ll bruteforce(ll a, ll b, ll p, ll q) {
	p %= q;
	ll best = 0x3f3f3f3f3f3f3f3f, bestp = 0, cur = p*a % q;
	iter(i, a, b+1) {
		if(abs(2*cur-q) < best) {
			best = abs(2*cur-q);
			bestp = i;
		}
		cur += p; cur -= (cur >= q ? q : 0);
	}
	return bestp;
}
constexpr ll infty = 1e18;
void exgcd(ll a, ll b, ll&x, ll&y) {
	if(!b) x=1,y=0;
	else exgcd(b, a%b, y, x), y-=a/b*x;
}
ll sv(ll p, ll q) { ll x,y; exgcd(p,q,x,y); return (x%q+q)%q; }
ll solution(ll p, ll q, ll g, ll tg, ll v, ll l, ll r) {
	if(!(0 <= tg && tg < q)) return infty;
	if(tg % g) return infty;
	ll tmp = v * (tg/g) % q;
	if(tmp < l) {
		ll k = (l - tmp + q - 1) / q;
		tmp += k * q;
	} else {
		ll k = (tmp - l) / q;
		tmp -= k * q;
	}
	assert(l <= tmp);
	assert(tmp-q < l);
	if(r < tmp) return infty;
	return tmp;
}
ll bruteforce2(ll a, ll b, ll p, ll q) {
	ll g = 1;
	ll low, high;
	ll v = sv(p, q);
	if(q % 2 == 0) {
		ll t = solution(p, q, g, q/2, v, a, b);
		if(t != infty) return t;
		low = q/2 - 1, high = q/2+1;
	} else low = q/2, high = q/2+1;
	while(1) {
		//if(low % 1000000 == 0) cout << low << ' ' << high << endl;
		if(low <= -1 && high >= q) return -1;
		ll t1 = solution(p, q, g, low, v, a, b);
		ll t2 = solution(p, q, g, high, v, a, b);
		t2 = min(t1, t2);
		if(t2 != infty) return t2;
		low--; high++;
	}
	return -1;
}
ll check1(ll a, ll b, ll p, ll q) {
	auto eval = [&](ll x){return abs(2*(p*x%q)-q);};
	ll low = a, high = b;
	pair<ll, ll> ans = {infty,0};
	ans = min(ans, {eval(a), a});
	ans = min(ans, {eval(b), b});
	if(eval(a)<eval(a+1)) {
		while(low <= high) {
			ll mid = (low+high)/2;
			ans = min(ans, {eval(mid), mid});
			ans = min(ans, {eval(mid+1), mid+1});
			if(eval(mid)<eval(mid+1)) low = mid + 1;
			else high = mid - 1;
		}
	}
	return ans.se;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
	while(t--) {
		ll a, b, p, q; cin >> a >> b >> p >> q;
		ll g = __gcd(p, q);
		p /= g;
		q /= g;
		if(b-a+1 <= 1000000) cout << bruteforce(a, b, p, q) << endl;
		else if(2 * p * (b-a+1) < q && q > 1000000) cout << check1(a, b, p, q) << endl;
		else cout << bruteforce2(a, b, p, q) << endl;
	}
}