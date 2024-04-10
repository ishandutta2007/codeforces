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

LL tree[1000006];
//return cf[idx]
LL read(int idx)
{
	if (idx == 0) return 0;
	LL sum = 0;

	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

//add val to f[idx].
//MaxVal = Just max value of index
void update(int idx, int val)
{
	while (idx <= 1000001)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int find(int a, int b) {
	// [a+1, b-1].
	int c = 0;
	if (a + 1 <= b - 1) {
		c = read(b - 1) - read(a);
		c *= 2;
		if (a + 1 <= 1 && 1 <= b - 1) {
			c--;
		}
	}
	else {
		c = read(b - 1) + read(1000001) - read(a);
		c *= 2;
		if (b - 1 >= 1) {
			c--;
		}
	}

	update(b, 1);
	return c + 1;

}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	k = MIN(n - k, k);
	int now = 1;
	LL ans = 1;
	update(1, 1);
	for (int i = 1; i <= n; i++) {
		int a = now;
		now += k;
		if (now > n) now -= n;
		int b = now;

		// a to b.
		int calc = find(a, b);
		ans += calc;
		printf("%I64d ", ans);
	}
	return 0;
}