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

int mark[1 << 10];

void Print(int x) {
	printf(" ");
	VI V;
	for (int i = 0; i < 8; i++) V.push_back((x & (1 << i)) ? 1 : 0);
	reverse(ALL(V));
	for (int i = 0; i < 8; i++) {
		if (i == 2 || i == 4 || i==6) printf(",");
		printf("%d", V[i]);
	}
}

LL mul[4][4] = {
	{0, 0, 0},
	{1, 2, 3},
	{2, 3, 1},
	{3, 1, 2},
};

VL Calc(LL n, LL slot, VL V = { 1, 2, 3 }) {
	if (slot == 0) return V;
	for (int i = 0; i <= 3; i++) {
		if (1LL << (2 * (slot - 1)) >= n) {
			for (int j = 0; j < 3; j++) {
				V[j] = V[j] * 4 + mul[i][j];
			}
		return 	Calc(n, slot - 1, V);
		}
		n -= 1LL << (2 * (slot - 1));
	}
}

VL Calc(LL n) {
	if (n == 1) return { 1, 2, 3 };
	n -= 1;
	if (n == 4)
		n = 4;
	for (LL i = 1; ; i++) {
		if (1LL << (2 * i) >= n) {
			return Calc(n, i, { 1LL, 2LL, 3LL });
		}
		n -= 1LL << (2 * i);
	}
}

LL Brute(LL n) {
		VI V;
		CLR(mark);
	for (int i = 1; i <= 33; i++) {
		int done = 0;
	for (int j = 1; j <= 200 && !done; j++) for (int k = j + 1; k <= 200 && !done; k++)
	{
	if (mark[j] == 0 && !mark[k] && !mark[j ^ k]) {
	V.push_back(j);
	V.push_back(k);
	V.push_back(j ^ k);
	mark[j] = mark[k] = mark[j ^ k] = 1;
	done = 1;
	}
	}
	}
	/*
	for (int i = 0; i + 2 < SZ(V); i += 3) {
	Print(V[i]); Print(V[i + 1]); Print(V[i + 2]);
	printf("\n");
	}*/
	return V[n - 1];

}

LL Smart(LL n) {
	LL _n = (n - 1) / 3 + 1;
	VL V = Calc(_n);
	LL st = 3 * (_n - 1) + 1;
	LL ans;
	if (st == n) ans = V[0];
	else if (st + 1 == n) ans = V[1];
	else ans = V[2];
	return ans;
}

void solve(int ks) {
	LL n;
	scanf("%lld", &n);
/*	for (LL n = 1; n <= 99; n++) {
		if (n == 16)
			n = 16;
		LL ans = Smart(n);
		LL ans2 = Brute(n);
		if (ans != ans2) printf(">>%lld %lld %lld\n", n, ans, ans2);
		assert(ans == ans2);
	}*/
	LL ans = Smart(n);
	printf("%lld\n", ans);
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

	if (1) {
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