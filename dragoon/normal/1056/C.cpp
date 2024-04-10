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
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

typedef long double ld;

int n, m;
int score[3003];
VP V;
int done[3003];
int other[3003];
int prevs;

void myTurn() {
	if (prevs != -1) {
		int x = other[prevs];
		if (x && !done[x]) {
			done[x] = 1;
			printf("%d\n", x);
			fflush(stdout);
			return;
		}
	}

	for (auto& p : V) {
		if (!done[p.first]) {
			done[p.first] = 1;
			printf("%d\n", p.first);
			fflush(stdout);
			return;
		}
	}

	int mxValue = -1, which = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (!done[i] && mxValue < score[i]) {
			mxValue = score[i];
			which = i;
		}
	}
	done[which] = 1;
	printf("%d\n", which);
	fflush(stdout);
}

void yourTurn() {
	scanf("%d", &prevs);
	done[prevs] = 1;
}

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= 2 * n; i++) {
		scanf("%d", &score[i]);
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (score[a] < score[b]) swap(a, b);
		V.push_back(PII(a, b));
		other[a] = b;
		other[b] = a;
	}

	int t;
	scanf("%d", &t);
	t--;
	prevs = -1;
	// t = 0, my.
	for (int i = 1; i <= 2 * n; i++) {
		if (t == 0) {
			myTurn();
		}
		else {
			yourTurn();
		}
		t ^= 1;
	}
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	//freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	solve();

	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}