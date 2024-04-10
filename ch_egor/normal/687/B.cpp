#include <stdio.h> // before *stream
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d %d", &n, &k);

	int d = 1;

	for (int i = 0; i < n; ++i)
	{
		int v;
		scanf("%d", &v);
		v /= gcd(v, d);
		d *= gcd(k / d, v);
	}

	printf("%s\n", (d == k ? "Yes" : "No"));

	fclose(stdin);
	fclose(stdout);

	return 0;
}