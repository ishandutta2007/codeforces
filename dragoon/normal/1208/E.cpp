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

vector<vector<int>> V;
int n, w;
LL ans[1000006];

bool cmpSz(int a, int b) {
	return SZ(V[a]) < SZ(V[b]);
}

VL process(VI& arr, int len) {
	VL ans(len);
	LL glbl = 0;
	int now = 0;
	VL mx(SZ(arr));
	for (int i = 0; i < len; i++) {
		LL cur = 0;
		for (int j = now; j < SZ(arr); j++) {
			if (V[arr[j]].size() == i) {
				now++;
				glbl += mx[j];
			}
			else {
				mx[j] = MAX(mx[j], V[arr[j]][i]);
				cur += mx[j];
			}
		}
		cur += glbl;
		ans[i] = cur;
	}
	return ans;
}

void processLo(VI& lo) {
	sort(ALL(lo), cmpSz);
	VL A = process(lo, w / 2);
	for (int i : lo) {
		reverse(ALL(V[i]));
	}
	VL B = process(lo, w - w / 2);
	for (int i : lo) {
		reverse(ALL(V[i]));
	}
	reverse(ALL(B));
	VL& now = A;
	for (LL b : B) now.push_back(b);
	for (int i = 0; i < w; i++) ans[i] = now[i];
}

LL calc(VVI& V, int mn, int mx) {
	int len = mx - mn + 1;
	int i = 0, j = 1;
	while (true) {
		if (2 * j >= len) break;
		i++;
		j *= 2;
	}
	return MAX(V[i][mn], V[i][mx - j + 1]);
}

VL process2(int id, int w) {
	VVI p = { V[id] };
	int now = 0;
	for (int i = 2; i <= SZ(V[id]); i*=2) {
		VI z(SZ(V[id]));
		now++;
		int pre_i = i / 2;
		for (int j = 0; j < SZ(V[id]); j++) {
			int w = MAX(p[now - 1][j], (j + pre_i >= SZ(V[id])) ? -1000000001 : p[now - 1][j + pre_i]);
			z[j] = w;
		}
		p.push_back(z);
	}

	VL ret(w);
	for (int i = 0; i < w; i++) {
		int L = SZ(V[id]);
		int mn = L - w + i;
		int mx = i;
		mn = MAX(mn, 0);
		mx = MIN(mx, L - 1);
		ret[i] = calc(p, mn, mx);
		if (i > L - 1 || L - w + i < 0) ret[i] = MAX(ret[i], 0);
	}
	return ret;
}

void processHi(VI& hi) {
	for (int i : hi) {
		VL A = process2(i, w);
		for (int j = 0; j < w; j++) {
			ans[j] += A[j];
		}
	}
}

void solve(int ks) {
	scanf("%d %d", &n, &w);
	V.resize(n);
	for (int i = 0; i < n; i++) {
		int l;
		scanf("%d", &l);
		VI& W = V[i];
		W.resize(l);
		FORN(j, l) {
			scanf("%d", &W[j]);
		}
		V.push_back(W);
	}
	VI lo, hi;
	for (int i = 0; i < n; i++) {
		if (SZ(V[i]) * 2 <= w) lo.push_back(i);
		else hi.push_back(i);
	}
	processLo(lo);
	processHi(hi);
	for (int i = 0; i < w; i++) {
		if (i) printf(" ");
		printf("%lld", ans[i]);
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