/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int main()
{
	int n, k;
	cin >> n >> k;
	int m = n - 1, h = (m / k) + !!(m % k);
	if (m % k == 1)
		cout << 2 * h - 1 << endl;
	else
		cout << 2 * h << endl;

	for (int i = 1; i <= min(k, m); ++i)
		cout << n << ' ' << i << endl;

	for (int i = k + 1; i <= m; ++i)
		cout << i << ' ' << i - k << endl;
}