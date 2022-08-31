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

ll f[N];

int main()
{
	int k;
	cin >> k;
	if (!k)
	{
		cout << 'a';
		return 0;
	}
	
	f[1] = 0;
	for (int i = 2; i < N; ++i)
		f[i] = i - 1 + f[i - 1];

	int p = 1;
	char c = 'a';
	while (f[p + 1] <= k)
		++p;

	while (k)
	{
		for (int j = 0; j < p; ++j)
			cout << c;

		++c;
		k -= f[p];
		while (f[p] > k)
			--p;
	}
}