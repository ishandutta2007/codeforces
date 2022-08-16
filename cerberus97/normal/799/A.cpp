/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
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

const int N = 1e5 + 5;

int main()
{
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int t1 = ((n / k) * t) + ((n % k) ? t : 0);
	int l = 1, r = 1e7;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int temp = ((mid / t) * k);
		if (mid >= d)
			temp += ((mid - d) / t) * k;

		if (temp >= n)
			r = mid - 1;

		else
			l = mid + 1;
	}

	if (r + 1 < t1)
		cout << "YES";

	else
		cout << "NO";
}