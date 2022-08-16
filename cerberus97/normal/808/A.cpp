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
	ll n;
	cin >> n;
	int i = 0;
	ll p = 1;
	for (; i < 15; ++i)
	{
		if (9 * p > n)
			break;

		p *= 10;
	}

	ll x = 1;
	for (; x <= 9; ++x)
	{
		if (x * p > n)
			break;
	}

	cout << x * p - n;
}