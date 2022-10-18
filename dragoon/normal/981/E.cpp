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
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef long double ld;

VI V[40004];

void insert(int at, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		V[at].push_back(v);
		return;
	}
	if (R < l || r < L) return;
	int mid = (l + r) / 2;
	insert(at * 2, l, mid, L, R, v);
	insert(at * 2 + 1, mid + 1, r, L, R, v);
}

bitset<10004> ans;

void process(int at, int l, int r, bitset<10004> B) {
	for (int v : V[at]) {
		B |= (B << v);
	}
	if (l == r) {
		ans |= B;
		return;
	}
	int m = (l + r) / 2;
	process(at * 2, l, m, B);
	process(at * 2 + 1, m + 1, r, B);
}

void solve(int ks) {
	int n, q;
	scanf("%d %d", &n, &q);
	while (q--) {
		int l, r, v;
		scanf("%d %d %d", &l, &r, &v);
		insert(1, 1, n, l, r, v);
	}
	bitset<10004> B;
	B.set(0);
	process(1, 1, n, B);
	VI Z;
	for (int i = 1; i <= n; i++) {
		if (ans.test(i)) Z.push_back(i);
	}
	printf("%d\n", SZ(Z));
	for (int z : Z) printf("%d ", z);
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