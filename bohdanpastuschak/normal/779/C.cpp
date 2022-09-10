#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
#define ll unsigned long long
#define mod 1000000007

int compare(int a, int b)
{
	return a < b;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	ll ans = 0;
	vector<int> c(n);
	for (int i = 0; i < n; ++i)
	{
		c[i] = a[i] - b[i];
	}

	sort(c.begin(), c.end(), compare);
	for (int i = 0; i < k; ++i)
		ans += c[i];
	for (int i = k; i < n; ++i)
	{
		if (c[i] < 0) ans += c[i];
		else break;
	}
	for (int i = 0; i < n; ++i)
		ans += b[i];

	cout << ans;
	return 0;
}