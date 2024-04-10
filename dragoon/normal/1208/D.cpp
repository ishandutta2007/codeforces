//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include <array>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
	~debug() { cerr << endl; }
	template<class c> typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
		cerr << boolalpha << i; return *this;
	}

	template<class c, int=0> typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
		return *this << range(begin(i), end(i));
	}

sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
	sim dor(const c&) { ris; }
#endif
};
#define watch(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int128 LLL;
typedef long long LLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PLL > VPL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<vector<int>> VVI;
typedef long double ld;

const LL MOD = 998244353;

struct Seg {
	int cnt;
	LL lo, hi;
	LL lazy;
};
Seg seg[4 * 200005];

void build(int at, int l, int h) {
	if (l == h) {
		seg[at].cnt = 1;
		seg[at].lo = seg[at].hi = ((l - 1LL) * l) / 2;
		seg[at].lazy = 0;
		return;
	}
	int m = (l + h) / 2;
	build(at * 2, l, m);
	build(at * 2 + 1, m + 1, h);
	seg[at].lo = seg[at * 2].lo;
	seg[at].hi = seg[at * 2 + 1].hi;
	seg[at].cnt = seg[at * 2].cnt + seg[at * 2 + 1].cnt;
	seg[at].lazy = 0;
}

void push(int at, int lo, int hi) {
	LL amount = seg[at].lazy;
	seg[at].lazy = 0;
	seg[at * 2].lazy += amount;
	seg[at * 2 + 1].lazy += amount;
	seg[at * 2].lo += amount;
	seg[at * 2].hi += amount;
	seg[at * 2 + 1].lo += amount;
	seg[at * 2 + 1].hi += amount;
}

int query(int at, int lo, int hi, LL v) {
	if (lo == hi) return lo;
	if (seg[at].lazy) push(at, lo, hi);
	int mid = (lo + hi) / 2;
	if (seg[at * 2].cnt &&
		v <= seg[at * 2].hi) return query(at * 2, lo, mid, v);
	return query(at * 2 + 1, mid + 1, hi, v);
}

void Combine(int at) {
	seg[at].cnt = seg[at * 2].cnt + seg[at * 2 + 1].cnt;
	if (seg[at].cnt == 0) return;
	seg[at].lo = (seg[at * 2].cnt ? seg[at * 2].lo : seg[at * 2 + 1].lo);
	seg[at].hi = (seg[at * 2 + 1].cnt ? seg[at * 2 + 1].hi : seg[at * 2].hi);
	seg[at].lazy = 0;
}

void update(int at, int lo, int hi, int pos) {
	if (lo == hi) {
		seg[at].cnt = 0;
		seg[at].lo = seg[at].hi = 0;
		seg[at].lazy = 0;
		return;
	}
	if (seg[at].lazy) push(at, lo, hi);
	int mid = (lo + hi) / 2;
	if (pos <= mid) {
		seg[at * 2 + 1].lazy -= pos;
		seg[at * 2 + 1].lo -= pos;
		seg[at * 2 + 1].hi -= pos;
		update(at * 2, lo, mid, pos);
	}
	else {
		update(at * 2 + 1, mid + 1, hi, pos);
	}
	Combine(at);
}

LL inp[200005];
int ans[200005];

void solve(int ks) {
	int n;
	scanf("%d", &n);
	FORAB(i, 1, n) scanf("%lld", &inp[i]);
	build(1, 1, n);
	for (int i = n; i >= 1; i--) {
		int at = query(1, 1, n, inp[i]);
		update(1, 1, n, at);
		ans[i] = at;
	}
	FORAB(i, 1, n) {
		if (i > 1) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}

int main()
{
#ifdef LOCAL
	double start_time = clock();
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif


	if (0) {
		int T;
		scanf("%d", &T);
		//AIN(T, 1, 25);
		for (int ks = 1; ks <= T; ks++) {
			solve(ks);
			fprintf(stderr, "%d done\n", ks);
		}
	}
	else {
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}