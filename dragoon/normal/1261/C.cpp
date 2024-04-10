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
int n, m;
VVI board, sum, board2;
char S[1000006];
VP trees;
VP candi;
VS ans;

int possible(int g) {
	for (auto& v : board2) for (auto& i : v) i = 0;
	candi.clear();

	for (int i = 0; i < SZ(trees); i++) {
		int r = trees[i].first;
		int c = trees[i].second;
		int lr = r - g;
		int hr = r + g;
		int lc = c - g;
		int hc = c + g;
		if (lr < 1 || lc < 1 || hr > n || hc > m) continue;
		int total = (hr - lr + 1) * (hc - lc + 1);
		int now = sum[hr][hc] - sum[hr][lc - 1] - sum[lr - 1][hc] + sum[lr - 1][lc - 1];
		if (total != now) continue;
		candi.push_back(trees[i]);
		board2[lr][lc]++;
		board2[lr][hc + 1]--;
		board2[hr + 1][lc]--;
		board2[hr + 1][hc + 1]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			board2[i][j] += board2[i - 1][j] + board2[i][j - 1] - board2[i - 1][j - 1];
			if (board[i][j] && board2[i][j] == 0) return 0;
			if (board[i][j] == 0 && board2[i][j]) return 0;
		}
	}
	return 1;
}

void solve(int ks) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n + 1; i++) {
		board.push_back(VI(m + 2, 0));
	}
	board2 = board;

	for (int i = 1; i <= n; i++) {
		scanf("%s", S + 1);
		for (int j = 1; j <= m; j++) {
			board[i][j] = (S[j] == 'X');
			if (S[j] == 'X') trees.push_back({ i, j });
		}
	}
	sum = board;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= m + 1; j++) {
			sum[i][j] = -sum[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] + board[i][j];
		}
	}
	int mn = MIN(n, m);
	int lo = 0, hi = (mn - 1) / 2;
	while (lo < hi) {
		int m = (lo + hi + 1) / 2;
		if (possible(m)) lo = m;
		else hi = m - 1;
	}
	possible(lo);
	string S;
	for (int i = 0; i < m; i++) S.push_back('.');
	for (int i = 0; i < n; i++) {
		ans.push_back(S);
	}
	for (auto& p : candi) ans[p.first - 1][p.second - 1] = 'X';

	printf("%d\n", lo);
	for (auto& s : ans) printf("%s\n", s.c_str());
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