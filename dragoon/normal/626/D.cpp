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

LL cnt[5003];
LL diff[10003];
LL diff2[10003];

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int n, v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v);
		cnt[v]++;
	}
	for (int i = 1; i <= 5000; i++) {
		for (int j = i + 1; j <= 5000; j++) {
			diff[j - i] += cnt[i] * cnt[j];
		}
	}
	for (int i = 1; i <= 5000; i++) {
		for (int j = 1; j <= 5000; j++) {
			diff2[i + j] += diff[i] * diff[j];
		}
	}
	for (int i = 5000; i >= 0; i--) diff[i] += diff[i + 1];
	double ans = 0;
	for (int i = 1; i <= 10000; i++) {
		ans += diff2[i] * diff[i + 1];
	}
	ans /= pow(n * (n - 1) / 2., 3);
	printf("%.10lf\n", ans);
	return 0;
}