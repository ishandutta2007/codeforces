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
//#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	VI V;
	for (int i = 1; ; i++) {
		if (sum >= i) {
			sum -= i;
			V.push_back(i);
		}
		else {
			break;
		}
	}

	VI A, B;
	int sumA = a, sumB = b;
	for (int i = SZ(V) - 1; i >= 0; i--) {
		if (V[i] <= sumA) {
			sumA -= V[i];
			A.push_back(V[i]);
		}
		else {
			B.push_back(V[i]);
		}
	}

	sort(ALL(A));
	sort(ALL(B));
	sum = 0;
	for (int a : A) sum += a;
	while (sum > a) {
		sum -= A[SZ(A) - 1];
		A.pop_back();
	}
	sum = 0;
	for (int b : B) sum += b;
	while (sum > b) {
		sum -= B[SZ(B) - 1];
		B.pop_back();
	}
	printf("%d\n", SZ(A));
	for (int a : A) {
		printf("%d ", a);
	}
	printf("\n");
	printf("%d\n", SZ(B));
	for (int a : B) {
		printf("%d ", a);
	}
	printf("\n");

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}