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

const int MAX_N = 2000 * 100 + 5;

int n, m;
int arr1[MAX_N];
int arr2[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &arr1[i]);
	for (int i = 0; i < m; ++i) scanf("%d", &arr2[i]);

	int answer = max((*min_element(arr1, arr1 + n)) * 2, *max_element(arr1, arr1 + n));
	int cc = *min_element(arr2, arr2 + m);

	if (cc <= answer) printf("-1");
	else printf("%d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}