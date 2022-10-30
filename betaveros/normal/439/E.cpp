// @betaveros :: vim:set fdm=marker syntax=cppc:
// #define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cinttypes> // C++11?
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
#include <iostream>
using namespace std;
// }}}
// #defines, typedefs, constants {{{
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define fori0(i,e) for(int i = 0; i < ((int)e); i++)
#define fori1(i,e) for(int i = 1; i <= ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define foruin(i,c) for(unsigned int i = 0; i < ((unsigned int)(c).size()); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define scan_d(x) scanf("%d",&(x))
#define scan_dd(x,y) scanf("%d%d",&(x),&(y))
#define scan_ddd(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan_dddd(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#define debugf(...) ((void)0)
#else
#define debug(code) code
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

// const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
// const int       M7  = 1000000007;
// const int       M9  = 1000000009;
const long long M7L = 1000000007L;
// }}}
// dump, min/maxify {{{
template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
// }}}

ll mod(ll x) {
	x %= M7L;
	return x < 0 ? x + M7L : x;
}
ll mx(ll a, ll b) {
	return mod(mod(a) * mod(b));
}
ll _inv[100008];
void makeInv() {
	fori1 (i, 100007) {
		if (i == 1) _inv[i] = 1;
		else {
			// qx + r = M7L
			// (-q/r)x = 1
			ll q = M7L / i;
			int r = (int) (M7L % i);
			_inv[i] = mod(-mx(q, _inv[r]));
		}
	}
}
ll inv(ll x) {
	assert(x);
	if (x <= 100007) return _inv[(int)x];
	ll q = M7L / x;
	ll r = M7L % x;
	return mod(-mx(q, inv(r)));
}
ll _f[200008], _finv[200008];
void makeFinv() {
	fori0 (i, 200008) {
		if (i == 0) _f[i] = _finv[i] = 1;
		else {
			_f[i] = mx(_f[i-1], i);
			_finv[i] = mx(_finv[i-1], inv(i));
		}
	}
}
int n, f;
void readInput() {
	scan_dd(n, f);
}

ll binom(int a, int b) {
	if (a < 0 || b < 0) return 0;
	return mx(mx(_f[a+b], _finv[a]), _finv[b]);
	/*
	// C(a+b, a)
	if (a > b) swap(a, b);
	// a smaller
	ll ret = 1;
	fori1 (i, a) ret = mx(ret, b + i);
	fori1 (i, a) ret = mx(ret, inv(i));
	return ret;
	*/
}

vector<int> pf;
void makePrimeFactors() {
	pf.clear();
	int nn = n;
	auto extract = [&] (int p) -> void {
		if (nn % p == 0) {
			pf.push_back(p);
			do nn /= p; while (nn % p == 0);
		}
	};
	extract(2);
	for (int p = 3; p * p <= nn; p += 2) extract(p);
	if (nn > 1) extract(nn);
}

ll res;
void gather(uint pix, int nn, bool parity) {
	if (pix >= pf.size()) {
		ll s = binom(nn - f, f - 1);
		if (parity) {
			res = mod(res + s);
		} else {
			res = mod(res - s);
		}
	} else {
		gather(pix + 1, nn, parity);
		gather(pix + 1, nn / pf[pix], !parity);
	}
}

void tc() {
	readInput();
	makePrimeFactors();
	res = 0;
	gather(0, n, true);
	printf("%" PRId64 "\n", res);
}

int main() {
	makeInv();
	makeFinv();
	int tcn;
	scanf("%d", &tcn);
	repeat (tcn) tc();
}