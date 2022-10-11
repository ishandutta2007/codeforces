#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int64 answer = 0;
	int64 add = 101;
	int64 p, q;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d %I64d", &p, &q);

		add = min(add, q);
		answer += p*add;
	}

	printf("%I64d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}