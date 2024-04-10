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
const int MAX_N = 105;
int arr[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr, arr + n);
	reverse(arr, arr + n);
	if (n > 2) reverse(arr + 1, arr + n - 1);
	for (int i = 0; i < n; ++i) printf("%d ", arr[i]);

	fclose(stdin);
	fclose(stdout);

	return 0;
}