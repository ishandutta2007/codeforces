#pragma GCC optimize ("O3")
#pragma GCC target ("sse4.1")
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;
 
#define rep(i, f, t) for (int i = f; i < (t); i++)
#define trav(a, x) for (auto& a : x)
typedef vector<int> vi;
 
static const int T = 30080;
static_assert(T % 128 == 0, "");
 
struct bs {
	union {
		__m128i bits[T / 128];
		uint8_t ch[T / 8];
	};
	bs() : bits{} {}
	bool operator[](int ind) {
		return ch[ind >> 3] & (1 << (ind & 7));
	}
	void set(int ind) {
		ch[ind >> 3] |= 1 << (ind & 7);
	}
	void clear() {
		int i = 0;
		while (i+4 <= T/128) {
			bits[i] = _mm_setzero_si128(), i++;
			bits[i] = _mm_setzero_si128(), i++;
			bits[i] = _mm_setzero_si128(), i++;
			bits[i] = _mm_setzero_si128(), i++;
		}
		while (i < T/128)
			bits[i] = _mm_setzero_si128(), i++;
	}
};
inline bs operator|(const bs& a, const bs& b) {
	bs r;
	int i = 0;
	while (i+4 <= T/128) {
		r.bits[i] = a.bits[i] | b.bits[i], i++;
		r.bits[i] = a.bits[i] | b.bits[i], i++;
		r.bits[i] = a.bits[i] | b.bits[i], i++;
		r.bits[i] = a.bits[i] | b.bits[i], i++;
	}
	while (i < T/128)
		r.bits[i] = a.bits[i] | b.bits[i], i++;
	return r;
}
inline bs& operator|=(bs& a, const bs& b) {
	int i = 0;
	while (i+4 <= T/128) {
		a.bits[i] |= b.bits[i], i++;
		a.bits[i] |= b.bits[i], i++;
		a.bits[i] |= b.bits[i], i++;
		a.bits[i] |= b.bits[i], i++;
	}
	while (i < T/128)
		a.bits[i] |= b.bits[i], i++;
	return a;
}
 
int N;
 
static const int SMALL_CAP = 50;
bs* v[2*T];
vi smallv[2*T];
void get(bs& ret, int l, int r) {
	ret.clear();
	auto add = [&](int i) {
		if (smallv[i].empty()) ret |= *v[i];
		else trav(x, smallv[i]) ret.set(x);
	};
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) add(l++);
        if (r&1) add(--r);
    }
}
 
uint16_t num[T];
uint16_t fib[T];
 
int main() {
	int q, mod;
	ignore = scanf("%d%d", &N, &mod);
	map<int, vi> mp;
	rep(i,0,N) {
		int k;
		ignore = scanf("%d", &k);
		mp[k].push_back(i);
	}
	int a = 0, mx = (int)mp.size();
	trav(it, mp) {
		for(int i : it.second) {
			smallv[N+i].push_back(a);
		}
		num[a++] = (it.first)%mod;
	}
 
	for (int i = N; i --> 0;) {
		vi &left = smallv[2*i], &right = smallv[2*i+1];
		int si = left.size() + right.size();
		if (!left.empty() && !right.empty() && si <= SMALL_CAP) {
			vi& out = smallv[i];
			out.reserve(si);
			trav(x, smallv[2*i+0]) out.push_back(x);
			trav(x, smallv[2*i+1]) out.push_back(x);
		}
		else {
			v[i] = (bs*)_mm_malloc(sizeof(bs), 32);
			if (left.empty() && right.empty()) *v[i] = *v[2*i] | *v[2*i+1];
			else if (left.empty()) *v[i] = *v[2*i];
			else if (right.empty()) *v[i] = *v[2*i+1];
			else v[i]->clear();
			trav(x, left) v[i]->set(x);
			trav(x, right) v[i]->set(x);
		}
	}
 
	fib[0] = fib[1] = 1 % mod;
	rep(i, 2, T)
		fib[i] = (fib[i-1]+fib[i-2])%mod;
 
	ignore = scanf("%d", &q);
	vector<pair<int, int> > que(q);
	rep(i,0,q) {
		ignore = scanf("%d%d", &que[i].first, &que[i].second);
		que[i].first--;
	}
 
	__m128i mfilter[256];
	int popcnt[256];
	rep(i,0,256) {
		uint8_t ar[16];
		memset(ar, -1, sizeof ar);
		int inputj = 0, outputj = 0;
		rep(j,0,8) rep(k,0,2) {
			if (i & 1 << j)
				ar[outputj++] = inputj;
			inputj++;
		}
		mfilter[i] = _mm_load_si128((__m128i*)ar);
		popcnt[i] = (int)__builtin_popcount(i);
	}
 
	mx = (mx + 7) / 8;
	bs b;
	rep(i,0,q) {
		get(b, que[i].first, que[i].second);
		uint16_t* fibs = fib;
		__m128i* nums = (__m128i*)num;
 
		__m128i mzero = _mm_setzero_si128();
		__m128i macc = mzero;
		for (int j = 0; j < mx; ) {
#define ITER(res) { \
				uint8_t bits = b.ch[j]; \
				__m128i mnums = nums[j]; \
				__m128i mfibs = _mm_loadu_si128((__m128i*)fibs); \
				mnums = _mm_shuffle_epi8(mnums, mfilter[bits]); \
				fibs += popcnt[bits]; \
				res = _mm_madd_epi16(mnums, mfibs); \
				j++; \
			}
 
			__m128i mresa, mresb, mres;
			ITER(mresa)
			ITER(mresb)
			mres = _mm_add_epi32(mresa, mresb);
			macc = _mm_add_epi64(macc, _mm_unpacklo_epi32(mres, mzero));
			macc = _mm_add_epi64(macc, _mm_unpackhi_epi32(mres, mzero));
 
			ITER(mresa)
			ITER(mresb)
			mres = _mm_add_epi32(mresa, mresb);
			macc = _mm_add_epi64(macc, _mm_unpacklo_epi32(mres, mzero));
			macc = _mm_add_epi64(macc, _mm_unpackhi_epi32(mres, mzero));
		}
 
		union {
			__m128i m;
			uint64_t i[2];
		} u;
		u.m = macc;
		uint64_t ans = u.i[0] + u.i[1];
 
		ans %= mod;
		printf("%d\n", (int)(ans % mod));
	}
 
	fflush(stdout);
	_Exit(0);
}