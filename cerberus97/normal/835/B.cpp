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
#define ceil_div(a, b) ((a) / (b)) + !!((a) % (b))

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	ll k; string s;
	cin >> k >> s;
	ll cur = 0, ctr[11] = {0};
	for (auto &i : s)
	{
		ctr[i - '0']++;
		cur += i - '0';
	}

	ll ans = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (cur >= k)
			break;

		ll p = ceil_div(k - cur, 9 - i);
		if (p <= ctr[i])
		{
			ans += p;
			break;
		}

		else
		{
			ans += ctr[i];
			cur += (9 - i) * ctr[i];
		}
	}

	cout << ans << endl;
}