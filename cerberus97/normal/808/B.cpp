/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include "iomanip"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int a[N];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	ll cur = 0, num = 0;
	for (int i = 0; i < k; ++i)
		cur += a[i];

	num = cur;
	for (int i = k; i < n; ++i)
	{
		cur += a[i] - a[i - k];
		num += cur;
	}

	cout << fixed << setprecision(8) << double(num) / (n - k + 1);
}