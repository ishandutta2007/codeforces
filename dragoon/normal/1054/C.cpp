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

int n, l[1003], r[1003], num[1003];

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
	VP V;
	for (int i = 1; i <= n; i++) {
		V.push_back({ l[i] + r[i], i });
	}
	sort(ALL(V));
	int last_sum = -10;
	int cur_num = n + 1;
	for (int i = 0; i < V.size(); i++) {
		if (last_sum == V[i].first) {
			num[V[i].second] = cur_num;
		}
		else {
			cur_num--;
			last_sum = V[i].first;
			num[V[i].second] = cur_num;
		}
	}

	int flag = 1;
	for (int i = 1; i <= n; i++) {
		int ll = 0, rr = 0;
		for (int j = 1; j < i; j++) {
			if (num[j] > num[i]) ll++;
		}
		for (int j = i + 1; j <= n; j++) {
			if (num[j] > num[i]) rr++;
		}
		if (ll != l[i] || rr != r[i]) {
			flag = 0;
		}
	}

	if (!flag) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}