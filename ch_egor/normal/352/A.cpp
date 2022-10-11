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
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
int cnt[10];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	int x; cnt[0] = cnt[5] = 0;
	for (int i = 0; i < n; ++i) scanf("%d", &x), ++cnt[x];

	if (cnt[0] == 0) printf("-1\n"), exit(0);
	if (cnt[5] < 9) printf("0"), exit(0);

	for (int i = 0; i < cnt[5] - cnt[5] % 9; ++i) printf("5");
	for (int i = 0; i < cnt[0]; ++i) printf("0");

	fclose(stdin);
	fclose(stdout);

	return 0;
}