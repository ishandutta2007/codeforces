#include <stdio.h>
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

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
int arr[228];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	
	int ans = 0;
	auto kek = max_element(arr, arr + n);
	int x = kek - arr;
	ans += x;
	for (int i = x; i >= 1; --i)
		arr[i] = arr[i - 1];
	reverse(arr + 1, arr + n);
	kek = min_element(arr + 1, arr + n);
	ans += kek - arr - 1;

	cout << ans;

	return 0;
}