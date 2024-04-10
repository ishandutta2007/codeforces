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

const LL MOD = 1000000007;
int n, m, A[100005], B[100005];
LL prob[100005];

LL bigmod(LL a, LL b) {
	if (b == 0) return 1;
	LL x = bigmod(a, b / 2);
	x = (x * x) % MOD;
	if (b & 1) x = (x * a) % MOD;
	return x;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
		prob[n + 1] = 0;
		LL invm = bigmod(m, MOD - 2);
		LL inv2 = bigmod(2, MOD - 2);
		for (int i = n; i >= 1; i--) {
			if (!A[i] && !B[i]) {
				prob[i] = ((((m * (m - 1LL)) % MOD) * invm) % MOD) * invm;
				prob[i] %= MOD;
				prob[i] *= inv2;
				prob[i] %= MOD;
				prob[i] += invm * prob[i + 1];
			}
			else if (!A[i]) {
				prob[i] = invm * prob[i + 1];
				prob[i] += (m - B[i]) * invm;
			}
			else if (!B[i]) {
				prob[i] = invm * prob[i + 1];
				prob[i] += (A[i] - 1) * invm;
			}
			else {
				if (A[i] == B[i]) prob[i] = prob[i + 1];
				else prob[i] = A[i] > B[i];
			}
			prob[i] %= MOD;
		}
		printf("%lld\n", prob[1]);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}