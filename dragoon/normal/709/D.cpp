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
//typedef __int128 LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;
typedef long double ld;

vector<LL> countDigit(LL n) {
	if (n == 0) return { 0, 1 };
	for (LL i = 2; ; i++) {
		n -= i - 1;
		if (n == 0) return { i };
		if (n < 0) return {};
	}
}

void solve() {
	LL n00, n01, n10, n11;
	cin >> n00 >> n01 >> n10 >> n11;
	VL C0 = countDigit(n00);
	VL C1 = countDigit(n11);

	for (LL c0 : C0) for (LL c1 : C1) {
		if (!c0 && !c1) continue;
		LL total = c0 + c1;
		LL nc2 = total * (total - 1) / 2;
		if (nc2 != n00 + n11 + n01 + n10) continue;
		if (c1 == 0 || c0 == 0) {
			for (LL i = 0; i < c0; i++) cout << "0";
			for (LL i = 0; i < c1; i++) cout << "1";
			return;
		}
		LL pre0 = n01 / c1;
		LL tail1 = n01 % c1;
		LL pre1 = c1 - tail1;
		LL tail0 = c0 - pre0 - (tail1 > 0);
		for (LL i = 0; i < pre0; i++) cout << "0";
		for (LL i = 0; i < pre1; i++) cout << "1";
		if (tail1) cout << "0";
		for (LL i = 0; i < tail1; i++) cout << "1";
		for (LL i = 0; i < tail0; i++) cout << "0";
		return;
	}
	cout << "Impossible\n";
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	solve();

	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}