#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
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
//typedef __int64 LL;

typedef pair<int,int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

LL n, xx, yy;

LL solveEven() {
	LL done = 0;
	done += ((xx - 1) / 2)  * n;
	if ((xx & 1) == 0) {
		done += (n + 1) / 2;
	}
	LL w1 = (yy + 1) / 2;
	LL w2 = yy - w1;
	if ((1 + xx) % 2 == 0) done += w1;
	else done += w2;
	return done;
}

LL solveOdd() {
	LL done = (n * n + 1)/2;
	done += ((xx - 1) / 2)  * n;
	if ((xx & 1) == 0) {
		done += (n) / 2;
	}
	LL w1 = (yy + 1) / 2;
	LL w2 = yy - w1;
	if ((1 + xx) % 2 == 1) done += w1;
	else done += w2;
	return done;
}

LL solve() {
	if ((xx + yy) & 1) return solveOdd();
	return solveEven();
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	int q;
	scanf("%lld %d", &n, &q);
	while (q--) {
		scanf("%lld %lld", &xx, &yy);
		printf("%lld\n", solve());
	}


	return 0;
}