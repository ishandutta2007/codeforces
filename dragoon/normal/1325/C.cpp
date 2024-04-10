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

#define MAXN 100005
//const LL MOD = 1000000007;
const LL MOD = 998244353;
const LL INF = 2000000000000000001LL;

VP adj[100005];
int ans[100005];
int n;
int cur = 3;

int AssignALeaf(int u, int v, int col) {
	for (auto& p : adj[u]) {
		if (p.first == v) continue;
		if (SZ(adj[p.first]) == 1 && ans[p.second] == -1) {
			ans[p.second] = col;
			return 1;
		}
		if (AssignALeaf(p.first, u, col)) return 1;
	}
	return 0;
}

void AssignAny(int u, int v) {
	for (auto& p : adj[u]) {
		if (p.first == v) continue;
		if (ans[p.second] == -1) {
			ans[p.second] = cur++;
		}
		AssignAny(p.first, u);
	}
}

void Print() {
	FORAB(i, 1, n - 1) printf("%d\n", ans[i]);
}

int IsStar() {
	int cnt = 0;
	FORAB(i, 1, n) cnt += SZ(adj[i]) > 1;
	return cnt < 2;
}

int IsPath() {
	int cnt[3] = { 0, 0, 0 };
	FORAB(i, 1, n) {
		if (SZ(adj[i]) > 2) return 0;
		cnt[SZ(adj[i])]++;
	}
	if (cnt[1] == 2 && cnt[2] == n - 2) return 1;
	return 0;
}

int CountLeaf(int u, int v) {
	int cnt = 0;
	cnt += SZ(adj[u]) == 1;
	for (auto& p : adj[u]) {
		if (p.first == v) continue;
		cnt += CountLeaf(p.first, u);
	}
	return cnt;
}

void solve(int ks) {
	scanf("%d", &n);
	FORAB(i, 1, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back({ v, i });
		adj[v].push_back({ u, i });
	}

	if (IsStar() || IsPath()) {
		FORAB(i, 1, n - 1) ans[i] = i - 1;
		Print();
		return;
	}

	int u, v;
	FORAB(i, 1, n) {
		for (auto p : adj[i]) {
			if (SZ(adj[i]) > 1 && SZ(adj[p.first]) > 1) {
				u = i;
				v = p.first;
				ans[p.second] = n - 2;
				goto done;
			}
		}
	}
	
	done:
	int cnt_leaf_u = CountLeaf(u, v);
	int cnt_leaf_v = CountLeaf(v, u);

	if (cnt_leaf_u < cnt_leaf_v) {
		swap(u, v);
		swap(cnt_leaf_u, cnt_leaf_v);
	}

	MEM(ans, -1);
	AssignALeaf(u, v, 0);
	AssignALeaf(v, u, 1);
	AssignALeaf(u, v, 2);
	AssignAny(u, -1);
	Print();
}

void gen() {
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	gen();

	if (0) {
		int T;
		scanf("%d", &T);
		//AIN(T, 1, 5000);
		for (int ks = 1; ks <= T; ks++) {
			solve(ks);
			//fprintf(stderr, "%d done\n", ks);
		}
	}
	else {
		solve(0);
	}

	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}