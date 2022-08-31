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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

int a[N], ans[N];
pii b[N];

int main()
{
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= m; ++i)
	{
		cin >> b[i].first;
		b[i].second = i;
	}

	sort(a + 1, a + m + 1);
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= m; ++i)
		ans[b[i].second] = a[m - i + 1];

	for (int i = 1; i <= m; ++i)
		cout << ans[i] << ' ';
}