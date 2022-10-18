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
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int lis[100];

int LIS(VI V) {
	for (int i = 0; i < SZ(V); i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {
			if (V[j] < V[i]) {
				lis[i] = MAX(lis[i], lis[j] + 1);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < SZ(V); i++) {
		ret = MAX(ret, lis[i]);
	}
	return ret;
}

int check(VI V) {
	int ret = LIS(V);
	reverse(ALL(V));
	ret += LIS(V);
	return ret;
}

int ans[] = { -1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7 };

void solve(int len) {
	VI V;
	int ret = 1000000;
	for (int i = 0; i < len; i++) V.push_back(i);
	do {
		int now = check(V);
		ret = MIN(ret, now);
		if (ans[len] == now) {
			for (int i : V) printf("%d ", i);
			printf("\n");
		}
	} while (next_permutation(ALL(V)));
	printf(">>%d %d\n", len, ret);
}
int solve2(int n) {
	int ans = n + 1;
	int ansLen = 1;
	for (int len = 1; len <= n; len++) {
		int cnt = n / len;
		int extra = n % len;

		int now = cnt + (extra > 0);
		now += len;
		if (now < ans) {
			ans = now;
			ansLen = len;
		}
	}
	return ansLen;
}

vector<PII> V;
int main()
{
#ifdef LOCAL
	//freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	//for (int i = 1; i <= 10; i++)
	//	solve(i);

	int n;
	scanf("%d", &n);
	int ans = solve2(n);
	for (int i = 0; i < n; i += ans) {
		V.push_back(PII(i, MIN(i + ans - 1, n - 1)));
	}

	reverse(ALL(V));
	int flag = 0;
	for (auto Z : V) {
		for (int i = Z.first; i <= Z.second; i++) {
			if (flag) printf(" ");
			printf("%d", i + 1);
			flag = 1;
		}
	}
	printf("\n");
	//printf("%d\n", ans);
	return 0;
}