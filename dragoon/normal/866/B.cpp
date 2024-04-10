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
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

struct Pizza {
	LL profit, remain;
};

bool operator<(Pizza A, Pizza B) {
	return A.profit < B.profit;
}

struct Person {
	LL s, a, b;
};
Person p[100005];
LL sum = 0;
int n, s;

priority_queue<Pizza> Q;

LL solveLarge() {
	LL total = (sum + s - 1) / s;

	LL bestCost = 0;
	LL curCost = 0;
	for (int i = 0; i < n; i++) {
		curCost += p[i].a * p[i].s;
		Q.push({ p[i].b - p[i].a, p[i].s });
	}

	bestCost = curCost;
	int atLeast = ((sum % s) == 0) ? s : (sum % s);
	int atMost = s;
	for (int i = 1; i <= total; i++) {
		int cur = atLeast;
		while (cur && !Q.empty()) {
			Pizza A = Q.top();
			Q.pop();
			int z = MIN(A.remain, cur);
			A.remain -= z;
			cur -= z;
			curCost += z * A.profit;
			if (A.remain) {
				Q.push(A);
			}
		}
		bestCost = MAX(bestCost, curCost);

		cur = atMost - atLeast;
		while (cur && !Q.empty()) {
			Pizza A = Q.top();
			Q.pop();
			int z = MIN(A.remain, cur);
			A.remain -= z;
			cur -= z;
			curCost += z * A.profit;
			if (A.remain) {
				Q.push(A);
			}
			bestCost = MAX(bestCost, curCost);
		}
		bestCost = MAX(bestCost, curCost);
	}
	return bestCost;
}

int main()
{
	LL ans = 0;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld", &p[i].s, &p[i].a, &p[i].b);
		LL mins = MIN(p[i].s, 4 * s);
		LL rem = p[i].s - mins;
		LL z = rem % s;
		rem -= z;
		mins += z;
		ans += MAX(p[i].a, p[i].b) * (rem);
		p[i].s = mins;
		sum += p[i].s;
	}

	ans += solveLarge();
	printf("%lld\n", ans);
	return 0;
}