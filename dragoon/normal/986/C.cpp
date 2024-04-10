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

const int B = 22;
int in_input[1 << B];
int is_under[1 << B];
int n;
int kisu[1 << B];
int par[1 << B];

int Par(int x) {
	if (x == par[x]) return x;
	return par[x] = Par(par[x]);
}

void Join(int a, int b) {
	a = Par(a);
	b = Par(b);
	if (a != b) {
		par[a] = b;
	}
}

void solve(int ks) {
	int m;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		in_input[x] = 1;
	}

	int Z = 1 << B;
	for (int i = 0; i < Z; i++) {
		par[i] = i;
		kisu[i] = -1;
	}

	for (int i = 0; i < Z; i++) {
		is_under[i] = in_input[i];
		for (int j = 0; j < B; j++) {
			if (i & (1 << j)) {
				is_under[i] |= is_under[i ^ (1 << j)];
			}
		}
	}

	for (int i = Z - 1; i >= 0; i--) {
		if (in_input[(Z - 1) ^ i]) {
			if (kisu[i] != -1 && is_under[i]) Join(kisu[i], (Z - 1) ^ i);
			kisu[i] = (Z - 1) ^ i;
		}
		if (in_input[i] && kisu[i] != -1) {
			Join(i, kisu[i]);
		}
		if (kisu[i] != -1) {
			for (int j = 0; j < B; j++) {
				if (i & (1 << j)) {
					int other = i ^ (1 << j);
					if (is_under[other] && kisu[other] != -1) Join(kisu[other], kisu[i]);
					kisu[other] = kisu[i];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < Z; i++) {
		if (in_input[i]) {
			ans += (i == Par(i));
		}
	}
	printf("%d\n", ans);
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