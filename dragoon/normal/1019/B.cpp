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

int n;
#define GEN 0
int num[100005];

int query(int at) {
	if (GEN) return num[at - 1];
	
	printf("? %d\n", at + 1);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

int main()
{
#ifdef LOCAL
//	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	if (!GEN) scanf("%d", &n);
	if (GEN) {
		n = 100000;
		int pos = n / 2, neg = n / 2;
		int init = rand();
		for (int i = 0; i < n; i++) {
			double p = (rand() % 100) / 100.;
			if (p < 0.5 && pos) { init++; pos--; num[i] = init; }
			else if (p >= 0.5 && neg) {
				init--;
				neg--;
				num[i] = init;
			}
			else if (pos) {
				init++; pos--; num[i] = init;
			}
			else {
				init--; neg--; num[i] = init;
			}
		}
		assert(!pos && !neg);
	}
	if (n % 4) {
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}

	int lo = 0, hi = n / 2 - 1;
	int a = query(lo), b = query(n/2);
	if (a == b) {
		printf("! %d\n", lo + 1);
		fflush(stdout);
		return 0;
	}
	int sign = (a < b ? +1 : -1);
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int a = query(mid), b = query(mid + n / 2);
		if (a == b) {
			printf("! %d\n", mid + 1);
			fflush(stdout);
			return 0;
		}

		int new_sign = (a < b ? +1 : -1);
		if (sign == new_sign) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	assert(lo == hi);

	printf("! %d\n", lo + 1);
	fflush(stdout);

	return 0;
}