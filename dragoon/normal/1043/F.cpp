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

LL cnt[300005];
LL temp[300005], tmpCnt[300005];
int n;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a  %b);
}

#define MAXN 300000

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	scanf("%d", &n);
	int g;
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		if (i == 1) g = a;
		else g = gcd(g, a);
		temp[a] = cnt[a] = 1;

		if (a == 1) {
			printf("1\n");
			return 0;
		}
	}

	if (g > 1) {
		printf("-1\n");
		return 0;
	}


	for (int i = 1; i <= MAXN; i++) {
		for (int j = i + i; j <= MAXN; j += i) {
			cnt[i] += cnt[j];
		}
	}

	for (int k = 2; ; k++) {
		for (int i = 1; i <= MAXN; i++) tmpCnt[i] = temp[i];
		for (int i = 1; i <= MAXN; i++) {
			for (int j = i + i; j <= MAXN; j += i) {
				tmpCnt[i] += tmpCnt[j];
			}
		}
		for (int i = 1; i <= MAXN; i++) tmpCnt[i] *= cnt[i];
		for (int i = MAXN; i >= 1; i--) {
			for (int j = i + i; j <= MAXN; j+=i) {
				tmpCnt[i] -= tmpCnt[j];
			}
		}
		for (int i = 1; i <= MAXN; i++) {
			temp[i] = (tmpCnt[i] > 0);
		}
		if (temp[1]) {
			printf("%d\n", k);
			return 0;
		}
	}


#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}