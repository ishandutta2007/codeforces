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

typedef pair<int, int> PII;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

int n, color, at;
#define DIM 1024
LL tree[2][2][DIM][DIM];

void update(int x, int y, LL val)
{
	if (x == 0 || y == 0) return;

	color = (x + y) % 2;
	at = x % 2;
	while (x < DIM)
	{
		LL y1 = y;
		while (y1 < DIM)
		{
			tree[color][at][x][y1] ^= val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

LL read(int idx, int idy)
{
	if (idx == 0 || idy == 0) return 0;
	LL sum = 0, y = idy;
	color = (idx + idy) % 2;
	at = idx % 2;

	while (idx > 0)
	{
		idy = y;
		while (idy>0)
		{
			sum ^= tree[color][at][idx][idy];
			idy -= (idy & -idy);
		}
		idx -= (idx & -idx);
	}

	return sum;
}

int main() {
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
#endif
	int q;
	scanf("%d %d", &n, &q);
	while (q--) {
		int type;
		scanf("%d", &type);
		int tx0, ty0, tx1, ty1;
		LL v;
		scanf("%d %d %d %d", &tx0, &ty0, &tx1, &ty1);
		if (type == 2) {
			scanf("%I64d", &v);
		}

		if (type == 1) {
			LL ans = read(tx1, ty1) ^ read(tx0 - 1, ty1) ^ read(tx1, ty0- 1) ^ read(tx0 - 1, ty0 - 1);
			printf("%I64d\n", ans);
		}
		else {
			update(tx0, ty0, v);
			update(tx1 + 1, ty0, v);
			update(tx0, ty1 + 1, v);
			update(tx1 + 1, ty1 + 1, v);
		}
		/*
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				color = (i + j) % 2;
				at = i % 2;
				LL ans = read(i, j);
				printf("%lld ", ans);
			}
			printf("\n");
		}
		printf("\n");*/
	}
	return 0;
}