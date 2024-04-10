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

int n, k;
int a[200005];
map<int, int> M;

LL solve1() {
	M.clear();
	LL ans = 0;

	int prev = 0;
	M[0] = 1;
	for (int i = 1; i <= n; i++) {
		int a = ::a[i];
		a ^= prev;

		int op1 = 0, op2 = 0;
		int a1 = a, a2 = a ^ ((1 << k) - 1);
		if (M.find(a1) == M.end()) op1 = 0;
		else op1 = M[a1];
		if (M.find(a2) == M.end()) op2 = 0;
		else op2 = M[a2];

		if (op1 < op2) {
			M[a1]++;
			ans += i - op1;
			prev = a1;
		}
		else {
			M[a2]++;
			ans += i - op2;
			prev = a2;
		}
	}

	return ans;
}

LL solve2() {
	VI V(n + 1);
	LL ret = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				V[j + 1] = a[j + 1];
			}
			else {
				V[j + 1] = a[j + 1] ^ ((1 << k) - 1);
			}
		}

		LL ans = 0;
		for (int i = 1; i <= n; i++) {
			int now = 0;
			for (int j = i; j <= n; j++) {
				now ^= V[j];
				if (now) ans++;
			}
		}
		ret = MAX(ret, ans);
	}
	return ret;
}

void gen() {
	n = 4, k = 3;
	for (int i = 1; i <= n; i++) {
		a[i] = rand() % 8;
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	LL ans = solve1();
	printf("%lld\n", ans);

/*	while (true) {
		gen();
		LL ans1 = solve1();
		LL ans2 = solve2();
		if (ans1 != ans2) {
			printf("%d %d\n", n, k);
			for (int i = 1; i <= n; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			printf("%lld\n", ans1);
			printf("%lld\n", ans2);
			assert(ans1 == ans2);
		}
	}
	*/
#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}