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

const int N = 1e6 + 5, mod = 1e9 + 7;

ll b[N];

int main()
{
	fast_cin();
	string s;
	cin >> s;
	int n = s.length();
	ll ans = 0;
	b[n - 1] = ((s[n - 1] == 'b') ? 1 : 0);
	for (int i = n - 2; i >= 0; --i)
	{
		if (s[i] == 'b')
			b[i] = (b[i + 1] + 1) % mod;

		else
		{
			ans = (ans + b[i + 1]) % mod;
			b[i] = (2 * b[i + 1]) % mod;
		}
	}

	cout << ans;
}