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
typedef long long LLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<PLL > VPL;
typedef vector<double> VD;
typedef long double ld;

vector<int> Prime;
int mark[1000002];

void sieve(int n)
{
	int i, j, limit = sqrt(n*1.) + 2;

	mark[1] = 1;
	for (i = 4; i <= n; i += 2) mark[i] = 1;

	Prime.push_back(2);
	for (i = 3; i <= n; i += 2)
		if (!mark[i])
		{
			Prime.push_back(i);

			if (i <= limit)
			{
				for (j = i * i; j <= n; j += i * 2)
				{
					mark[j] = 1;
				}
			}
		}
}

void solve(int ks) {
	sieve(500000);
	int n;
	int c1 = 0, c2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) c1++; else c2++;
	}

	VI V;
	if (c2) { V.push_back(2); c2--; }
	if (c1) { V.push_back(1); c1--; }
	while (c2) {
		V.push_back(2);
		c2--;
	}
	while (c1) {
		V.push_back(1);
		c1--;
	}

	int ans = 0;
	int cur = 0;
	for (int i : V) {
		printf("%d ", i);
		cur += i;
		ans += (mark[cur] == 0);
	}
	

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
		//AIN(T, 1, 25);
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