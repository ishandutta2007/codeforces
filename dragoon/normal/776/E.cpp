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

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int f(int n) {
	if (n == 1) return 1;
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (gcd(i, n - i) == 1)
			cnt++;
	}
	return cnt;
}

int g(int n) {
	int ans = 0;
	for (int d = 1; d <= n; d++) {
		if (n % d) continue;
		ans += f(n / d);
	}
	return ans;
}

LL phi(LL n) {
	LL ret = n;
	for (LL i = 2; i * i <= n; i++) {
		if (n % i) continue;

		ret /= i;
		ret *= i - 1;
		while (n % i == 0) n /= i;
	}

	if (n > 1) {
		ret /= n;
		ret *= n - 1;
	}
	return ret;
}

int main()
{
//	for (int i = 1; i <= 20; i++) {
		//printf("%d   %d   %d\n", i, f(i), g(i));
//	}

	LL n, k;
	scanf("%I64d %I64d", &n, &k);
	for (int i = 1; i <= (k + 1) / 2; i++) {
		if (n == 1) break;
		n = phi(n);
	}

	n %= 1000000007;

	printf("%I64d\n", n);
	return 0;
}