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
typedef vector<PII > VP;
typedef vector<PLL > VPL;
typedef vector<double> VD;
typedef long double ld;

char S[1003];
const LL MOD = 998244353;

int p[3000], val[3000], e[3000];

PII par(int a) {
	if (a == p[a]) return { a, 0 };
	PII now = par(p[a]);
	p[a] = now.first;
	e[a] = now.second ^ e[a];
	return { p[a], e[a] };
}

int add_edge(int a, int b, int c) {
	PII x = par(a);
	PII y = par(b);
	if (x.first == y.first) {
		if (x.second ^ y.second ^ c) {
			return 0;
		}
		return 1;
	}

	p[x.first] = y.first;
	e[x.first] = c ^ x.second ^ y.second;
	return 1;
}

int check_or_assign(int a, int c) {
	PII x = par(a);
	if (val[x.first] == -1) {
		val[x.first] = e[a] ^ c;
		return 1;
	}
	if (val[x.first] ^ e[a] == c) return 1;
	return 0;
}

int should_multiply(int a) {
	PII x = par(a);
	if (x.first != a) return 0;
	if (val[x.first] == -1) return 1;
	return 0;
}

int solve(int len1, int len2) {
	int n = len1 + len2;
	for (int i = 0; i < n; i++) {
		p[i] = i;
		val[i] = -1;
		e[i] = 0;
	}
	// num variable = len1 + len2
	for (int i = 0, j = len1 - 1; i < j; i++, j--) {
		if (!add_edge(i, j, 0)) return 0;
	}
	for (int i = 0, j = len2 - 1; i < j; i++, j--) {
		if (!add_edge(i + len1, j + len1, 0)) return 0;
	}
	for (int x = 0; x < len2; x++) {
		if (S[x] == '?') continue;
		int y = x - (len2 - 1) + (len1 - 1);

		if (y >= 0) {
			if (!add_edge(y, x + len1, S[x] - '0')) return 0;
		}
	}

	for (int x = 0; x < len2; x++) {
		if (S[x] == '?') continue;
		int y = x - (len2 - 1) + (len1 - 1);
		if (y < 0) {
			if (!check_or_assign(x + len1, S[x] - '0')) {
				return 0;
			}
		}
	}
	if (!check_or_assign(0 + len1, 1)) {
		return 0;
	}
	if (!check_or_assign(0, 1)) {
		return 0;
	}
	LL ret = 1;
	for (int i = 0; i < len1 + len2; i++) {
		if (should_multiply(i)) {
			ret *= 2;
			ret %= MOD;
		}
	}
	return ret;
}

void solve(int ks) {
	scanf("%s", S);
	int n = strlen(S);
	LL ans = 0;
	for (int i = 1; i < n; i++) {
		ans += solve(i, n);
		ans %= MOD;
	}

	printf("%lld\n", ans);
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
		for (int ks = 1; ks <= T; ks++) solve(ks);
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