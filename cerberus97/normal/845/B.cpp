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

const int N = 1e5 + 10;

int main()
{
	string s;
	cin >> s;
	int ans = 10;
	for (int i = 0; i <= 999999; ++i)
	{
		int temp = i, s1 = 0, s2 = 0;
		for (int j = 0; j < 3; ++j)
		{
			s1 += temp % 10;
			temp /= 10;
		}

		for (int j = 0; j < 3; ++j)
		{
			s2 += temp % 10;
			temp /= 10;
		}

		if (s1 != s2)
			continue;

		int ctr = 0;
		temp = i;
		for (int j = 5; j >= 0; --j)
		{
			if (temp % 10 != s[j] - '0')
				++ctr;

			temp /= 10;
		}

		ans = min(ans, ctr);
	}

	cout << ans;
}