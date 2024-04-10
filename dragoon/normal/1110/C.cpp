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

int arr[] = {
	0,
	1,
	1,
	5,
	1,
	21,
	1,
	85,
	73,
	341,
	89,
	1365,
	1,
	5461,
	4681,
	21845,
	1,
	87381,
	1,
	349525,
	299593,
	1398101,
	178481,
	5592405,
	1082401,
};

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a  % b);
}
void solve(int ks) {
/*	for (int i = 1; i <= 25; i++) {
		int x = (1 << i) - 1;
		int ans = 0;
		for (int j = 1; j < x; j++) {
			int g = gcd(j ^ x, j & x);
			ans = MAX(ans, g);
		}
		printf("%d\n", ans);
	}*/
	int q;
	scanf("%d", &q);
	while (q--) {
		int x;
		scanf("%d", &x);
		if (x & (x + 1)) {
			int ans = 0;
			while (x) {
				ans = (ans * 2) + 1;
				x >>= 1;
			}
			printf("%d\n", ans);
		}
		else {
			int ans = 0;
			for (int i = 1; i <= 25; i++) {
				if (x == ((1 << i) - 1)) {
					ans = arr[i - 1];
				}
			}
			printf("%d\n", ans);
		}
	}
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
		/*
		n = 30, m = 1000;
		for (int i = 1; i <= n/3; i++) {
			int x = rand() % 7 + 1;
			if (rand() % 2) cnt[x]+=3;
			else cnt[x]++, cnt[x + 1]++, cnt[x + 2]++;
		}
		cnt[1] = 0;
		*/
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}