/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;
const ll inf = 2e9 + 5;

ll a[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	ll mn = inf, ctr = 0;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] - a[i - 1] < mn)
		{
			mn = a[i] - a[i - 1];
			ctr = 1;
		}

		else if (a[i] - a[i - 1] == mn)
			++ctr;
	}

	cout << mn << ' ' << ctr;
}