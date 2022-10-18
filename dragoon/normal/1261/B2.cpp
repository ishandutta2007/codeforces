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

	template<class c, int = 0> typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
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
typedef vector<string> VS;
typedef long double ld;

#define MAXN 200005
const LL MOD = 1000000007;
//const LL MOD = 998244353;

int n, mx[4 * MAXN];
int m, tree[4 * 200005], cnt[4 * MAXN];
int arr[MAXN];

void mx_build(int at, int l, int r) {
	if (l == r) {
		mx[at] = arr[l];
		return;
	}
	int m = (l + r) / 2;
	mx_build(at * 2, l, m);
	mx_build(at * 2 + 1, m + 1, r);
	mx[at] = MAX(mx[at * 2], mx[at * 2 + 1]);
}

int mx_query(int at, int l, int r) {
	return mx[at];
}

int mx_update(int at, int l, int r, int val) {
	if (l == r) {
		mx[at] = -1;
		return l;
	}
	int m = (l + r) / 2;
	int z;
	if (mx[at * 2] == val) z = mx_update(at * 2, l, m, val);
	else z = mx_update(at * 2 + 1, m + 1, r, val);
	mx[at] = MAX(mx[at * 2], mx[at * 2 + 1]);
	return z;
}

void insert(int at, int l, int r, int pos, int val) {
	if (l == r) {
		tree[at] = val;
		cnt[at] = 1;
		return;
	}
	int m = (l + r) / 2;
	if (pos <= m) insert(at * 2, l, m, pos, val);
	else insert(at * 2 + 1, m + 1, r, pos, val);
	cnt[at] = cnt[at * 2] + cnt[at * 2 + 1];
}

int query(int at, int l, int r, int pos) {
	if (l == r) return tree[at];
	int m = (l + r) / 2;
	if (pos <= cnt[at * 2]) return query(at * 2, l, m, pos);
	return query(at * 2 + 1, m + 1, r, pos - cnt[at * 2]);
}

struct Queries {
	int k, pos, id;
} queries[MAXN];

bool operator<(Queries A, Queries B) {
	return A.k < B.k;
}
int answer[MAXN];

void solve(int ks) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	mx_build(1, 1, n);
	
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &queries[i].k, &queries[i].pos);
		queries[i].id = i;
	}
	sort(queries, queries + q);
	int j = 0;
	for (int i = 1; i <= n; i++) {
		int mx = mx_query(1, 1, n);
		int whr = mx_update(1, 1, n, mx);
		insert(1, 1, n, whr, mx);

		while (j < q && queries[j].k == i) {
			answer[queries[j].id] = query(1, 1, n, queries[j].pos);
			j++;
		}
	}

	for (int i = 0; i < q; i++) printf("%d\n", answer[i]);
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	if (0) {
		int T;
		scanf("%d", &T);
		//AIN(T, 1, 10);
		for (int ks = 1; ks <= T; ks++) {
			solve(ks);
			fprintf(stderr, "%d done\n", ks);
		}
	}
	else {
		solve(0);
	}


	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}